#ifndef BRAINTRAINING_BWIDGET_H
#define BRAINTRAINING_BWIDGET_H
#include <I/bdefines.h>
#include <bgames.h>

class BGames;
class BMainMenu;

class BMainWindow : public QMainWindow{
	Q_OBJECT

	BGames *games;

public:
	BMainWindow();
 void changeWidget(QString n);

	BGames *getGames(){ return games; }

	void startGame(QString id);
};

#endif //BRAINTRAINING_BWIDGET_H
