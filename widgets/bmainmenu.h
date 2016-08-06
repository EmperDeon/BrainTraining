#ifndef BRAINTRAINING_BMAINMENU_H
#define BRAINTRAINING_BMAINMENU_H
#include <I/bdefines.h>
#include <bwidget.h>
#include <widgets/bgamebutton.h>

class BGames;
class BMainWindow;
class BGameButton;

class BMainMenu : public QWidget{
	Q_OBJECT

	BGames *games;

	// Lists
 QList<BGameButton*>* b_list;

	// Layouts and stuff
	QVBoxLayout* l_main;
 QGridLayout* l_list;
 QScrollArea* w_scroll;
	int columnsNum;

public:
	BMainMenu();

	void initLists();
	void reInitLayouts();

	void menuClick(QString id);

protected:
	virtual void resizeEvent(QResizeEvent *event);


	void init();
};

#endif //BRAINTRAINING_BMAINMENU_H
