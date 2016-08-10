#ifndef BRAINTRAINING_BIO_H
#define BRAINTRAINING_BIO_H
#include <bdefines.h>
#include <util/bU_io_init.h>

class BLEntry;
class BIODefaults;

class BIO{
public:
	static QJsonDocument loadJSONDocument(QString file);

 static QJsonObject loadJSON(QString file);
	static QJsonArray loadJSONA(QString file);
	static QString loadText(QString file);


	static void saveJSONDocument(QString file, QJsonDocument doc);

	static void saveJSON(QString file, QJsonObject obj);
	static void saveJSON(QString file, QJsonArray obj);

	static QString getHash(QJsonObject o);
};

class BSettings{
	BIODefaults* def;
	QJsonObject* obj;
	QString file = "b_config.json";

	QJsonObject getS() { return obj->value("Statistics"  ).toObject(); }
	QJsonObject getL() { return obj->value("LeaderBoards").toObject(); }
	QJsonObject getC() { return obj->value("Categories"  ).toObject(); }

	void setS(QJsonObject o) { obj->insert("Statistics"  , o); }
	void setL(QJsonObject o) { obj->insert("LeaderBoards", o); }
	void setC(QJsonObject o) { obj->insert("Categories"  , o); }

public:
	BSettings();
	void save();

	QJsonValue get(QString k) { return obj->value(k); }
	QString getS(QString k, QString d = "") { return obj->value(k).toString(d); }
	bool has(QString k) { return obj->contains(k); }
	void set(QString k, QJsonValue v) { this->obj->insert(k, v); }

 QString getGameHash(QString id);


	// Settings
	QWidget* getNewGameSettings(QString id);
 QJsonObject getSettings(QString id) { return obj->value(id).toObject(); }
	QJsonArray getGenerators(QString id) {	return obj->value("generators").toObject()[id].toArray();	}


	// Statistics


	// LeaderBoards
	QJsonArray getLeaderBoard(QString hash);
	void setLeaderBoard(QString hash, QJsonValue a);

	QList<BLEntry> getLEntry(QString hash);
 void addLEntry(QString id, BLEntry o);


 // Categories
	QColor getColor(QString name) { return QColor(QRgb( getC()[name].toObject()["color"].toDouble() )); }
};


class BLEntry{
	QString date, score;

public:
	BLEntry() { }
	BLEntry(QDateTime t, int s);
	BLEntry(QString t, QString s);

	static BLEntry fromJson(QJsonObject o);
	QJsonObject toJson();

	QString getDate() const { return date; }
	QString getScore() const { return score; }

	bool operator>(const BLEntry &s) const { return score < s.score; }
	bool operator<(const BLEntry &s) const { return score > s.score; }

	bool operator() (const BLEntry &t1, const BLEntry &t2) const { return (t1 > t2); }

};

#endif //BRAINTRAINING_BIO_H
