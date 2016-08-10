#include "bU_io_init.h"


BIODefaults::BIODefaults() {
 settings = QJsonObject{
	 {
		 "game_01", QJsonArray{
		 QJsonObject{{"hash", true},  {"max",   2}, {"name", "level"}, {"type", "level"}},
		 QJsonObject{{"hash", false}, {"items", QJsonArray{"Keyboard On", "Keyboard Off"}}, {"name", "keyb"},  {"type", "radio"}}
	 }
	 }
 };
}

QJsonArray BIODefaults::getSettingsWidget(QString id) {
	return settings[id].toArray();
}


