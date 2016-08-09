#include "bio.h"
#include <widgets/bsettingswidgets.h>

// BIO
QJsonDocument BIO::loadJSONDocument(QString file) {
	QFile f(file);
	f.open(QFile::ReadOnly);
	return QJsonDocument::fromJson(f.readAll());
}

QJsonObject BIO::loadJSON(QString file) {
	return loadJSONDocument(file).object();
}

QJsonArray BIO::loadJSONA(QString file) {
	return loadJSONDocument(file).array();
}

void BIO::saveJSONDocument(QString file, QJsonDocument doc) {
 QFile f(file);
	f.open(QFile::WriteOnly);
	f.write(doc.toJson());
	f.close();
}

void BIO::saveJSON(QString file, QJsonObject obj) {
 saveJSONDocument(file, QJsonDocument(obj));
}

void BIO::saveJSON(QString file, QJsonArray obj) {
	saveJSONDocument(file, QJsonDocument(obj));
}

QString BIO::loadText(QString file) {
	QFile f(file);
	f.open(QFile::ReadOnly);
	return QString::fromUtf8(f.readAll());
}

QString BIO::getHash(QJsonObject o) {
	return QCryptographicHash::hash(QJsonDocument(o).toJson(), QCryptographicHash::Sha256).toHex();
}
// BIO


// BSettings
BSettings::BSettings() {
	if(QFile(file).exists()){
		obj = new QJsonObject(BIO::loadJSON(file));

	}else{
  QFile f(file);
		f.open(QFile::WriteOnly);
		f.write(QString("{\n"
			                "    \"Categories\": {\n"
			                "        \"Mathematics\": {\n"
			                "            \"color\": 4281126319\n"
			                "        }\n"
			                "    },\n"
			                "    \"generators\": {\n"
			                "        \"game_01\": [\n"
			                "            {\n"
			                "                \"bracket\": false,\n"
			                "                \"count\": 2,\n"
			                "                \"max\": 10,\n"
			                "                \"min\": 0,\n"
			                "                \"oper\": [\n"
			                "                    \"+\"\n"
			                "                ],\n"
			                "                \"score\": 0\n"
			                "            },\n"
			                "            {\n"
			                "                \"bracket\": false,\n"
			                "                \"count\": 2,\n"
			                "                \"max\": 20,\n"
			                "                \"min\": 0,\n"
			                "                \"oper\": [\n"
			                "                    \"+\",\n"
			                "                    \"-\"\n"
			                "                ],\n"
			                "                \"score\": 0\n"
			                "            },\n"
			                "            {\n"
			                "                \"bracket\": false,\n"
			                "                \"count\": 2,\n"
			                "                \"max\": 50,\n"
			                "                \"min\": 10,\n"
			                "                \"oper\": [\n"
			                "                    \"+\",\n"
			                "                    \"-\"\n"
			                "                ],\n"
			                "                \"score\": 0\n"
			                "            }\n"
			                "        ]\n"
			                "    },\n"
			                "    \"settingsWidget\": {\n"
			                "        \"game_01\": [\n"
			                "            {\n"
			                "                \"max\": 2,\n"
			                "                \"name\": \"level\",\n"
			                "                \"type\": \"level\"\n"
			                "            }\n"
			                "        ]\n"
			                "    }\n"
			                "}").toUtf8());
  f.close();

		obj = new QJsonObject(BIO::loadJSON(file));
//		obj = new QJsonObject();

	}
}

void BSettings::save() {
	BIO::saveJSON(file, *obj);
}

QString BSettings::getGameHash(QString id) {
	QJsonObject o;
	o["name"] = id;

	for(QJsonValue v : obj->value("settingsWidget").toObject()[id].toArray()){
		QJsonObject t = v.toObject();

		if(t["hash"].toBool()){
			QString name = t["name"].toString(),
				type = t["type"].toString();

			if(type == "level")
				o[name] = getSettings(id)[name].toInt();
			else if(type == "radio")
				o[name] = getSettings(id)[name].toString();
			else
				qDebug() << t;
		}
	}

	return BIO::getHash(o);
}

QWidget * BSettings::getNewGameSettings(QString id) {
	QWidget* w = new QWidget;
	QVBoxLayout* l_main = new QVBoxLayout;
 QPushButton *b_start = new QPushButton(QObject::tr("Start"));

 QJsonArray a = obj->value("settingsWidget").toObject()[id].toArray();

	for(QJsonValue v : a){
		QJsonObject t = v.toObject();

		if(t["type"].toString() == "level"){
			l_main->addWidget(new BSettLevel(t["max"].toInt()));

		}else if(t["type"].toString() == "radio"){
			QStringList r; for(QJsonValue v1 : t["items"].toArray()) r << v1.toString();
			l_main->addWidget(new BSettRadio(r));

		}
	}

	QObject::connect(b_start, &QPushButton::clicked, [=](){
		QJsonObject o = obj->value(id).toObject();
		int i = 0;

		for(QJsonValue v : a){
			QJsonObject t = v.toObject();

			if(t["type"].toString() == "level"){
				if(BSettLevel *b = static_cast<BSettLevel *>(l_main->itemAt(i++)->widget())){
					o[t["name"].toString()] = b->getValue();
				}
			}else if(t["type"].toString() == "radio"){
				if(BSettRadio *b = static_cast<BSettRadio *>(l_main->itemAt(i++)->widget())){
					o[t["name"].toString()] = b->getSelected();
				}

			}
		}

  obj->insert(id, o);
		B_MAIN->startGame(id);
	});

	l_main->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	l_main->addSpacing(10);
 l_main->addWidget(b_start, 1, Qt::AlignBottom | Qt::AlignHCenter);

	w->setLayout(l_main);
	return w;
}


QJsonArray BSettings::getLeaderBoard(QString hash) {
	if(getL().contains(hash)){
		return getL()[hash].toArray();

	}else{
	 return QJsonArray();

	}
}

void BSettings::setLeaderBoard(QString hash, QJsonValue a) {
 QJsonObject o = getL();
	o.insert(hash, a);
 setL(o);
}

void BSettings::addLEntry(QString id, BLEntry o) {
	QString hash = getGameHash(id);
	QList<BLEntry> ent = getLEntry(hash);

	ent << o;

	qSort(ent);

	QJsonArray a;
	for(int i = 0 ; i < 15 ; i++)
 	if(i < ent.size()){
		 a << ent.value(i).toJson();
	}

 setLeaderBoard(hash, a);
}

QList<BLEntry> BSettings::getLEntry(QString hash) {
	QList<BLEntry> ent;

	for(QJsonValue v : getLeaderBoard(hash)){
		ent << BLEntry::fromJson(v.toObject());
	}

	return ent;
}

BSettings *B_SETT;
// BSettings



BLEntry::BLEntry(QDateTime t, int s) {
 date = t.toString("hh:mm   dd-MM-yyyy");
	score = QString("%1").arg(s, 7, 'f', 0, '0');
}

BLEntry::BLEntry(QString t, QString s): date(t), score(s) { }

BLEntry BLEntry::fromJson(QJsonObject o) {
	return BLEntry(o["date"].toString(), o["score"].toString());
}

QJsonObject BLEntry::toJson() {
	return QJsonObject{{"date", date}, {"score", score}};
}









