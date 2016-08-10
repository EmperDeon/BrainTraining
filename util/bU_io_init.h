#ifndef BRAINTRAINING_BINIT_H
#define BRAINTRAINING_BINIT_H
#include <bdefines.h>

class BIODefaults{
	QJsonObject settings;

public:
	BIODefaults();
	QJsonArray getSettingsWidget(QString id);
};
//
//		QJsonArray o;
//		o << QJsonObject{{"type", "level"}, {"name", "level"}, {"max", 9}};
//		o << QJsonObject{{"type", "radio"}, {"name", "type"}, {"items", QJsonArray{"Time", "Count"}}};
//		obj->insert("game_01", QJsonObject{{"settingsWidget", o}});

//{
//"items": [
//"Time",
//"Count"
//],
//"name": "type",
//"type": "radio"
//}


#endif //BRAINTRAINING_BINIT_H
