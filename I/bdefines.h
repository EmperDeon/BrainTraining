#ifndef BRAINTRAINING_I_BDEFINES_H
#define BRAINTRAINING_I_BDEFINES_H
#include <QtCore>
#include <QtWidgets>

class BSettings;
class BMainWindow;
class IGameWidget;

extern BSettings *B_SETT;
extern BMainWindow *B_MAIN;

class IGame{
public:

	virtual QString getName() = 0;
	virtual QString getCategory() = 0;
	virtual IGameWidget *getWidget();
};

class IGameWidget : public QWidget{
public:
	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void keyPress(int key) = 0;
};

#include <bio.h>
#include <bwidget.h>
#endif //BRAINTRAINING_I_BDEFINES_H
