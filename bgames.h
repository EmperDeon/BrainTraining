#ifndef BRAINTRAINING_BGAMES_H
#define BRAINTRAINING_BGAMES_H
#include <I/bdefines.h>
#include <math/bmathmain.h>

class BMathGame;

class BGames{
 QMap<QString, IGame*> *m_names;

public:
	BGames();

	void init();

	QStringList getIds() { return m_names->keys(); }
	IGameWidget *getGame(QString id) { return m_names->value(id)->getWidget(); }
	QString  getName(QString id) { return m_names->value(id)->getName(); }
	QString  getCategory(QString id) { return m_names->value(id)->getCategory(); }


};

#endif //BRAINTRAINING_BGAMES_H
