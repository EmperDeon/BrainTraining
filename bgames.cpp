#include "bgames.h"


BGames::BGames() {
 m_names = new QMap<QString, IGame*>;

	init();
}

void BGames::init() {
 m_names->insert("game_01", new BMathGame());

}











