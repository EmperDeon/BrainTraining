#ifndef BRAINTRAINING_BWIDGET_H
#define BRAINTRAINING_BWIDGET_H
#include <bdefines.h>
#include <b_games.h>

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
protected:
	virtual void keyReleaseEvent(QKeyEvent *event);


};

#endif //BRAINTRAINING_BWIDGET_H
