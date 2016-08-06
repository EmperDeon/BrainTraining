#include "bwidget.h"
#include <widgets/bmainmenu.h>


BMainWindow::BMainWindow() {
	games = new BGames;
	resize(550, 430);
}

void BMainWindow::changeWidget(QString n) {
	if(n.startsWith("mainMenu")){
		setCentralWidget(new BMainMenu());

	}else if(n.startsWith("game")){
	 setCentralWidget(B_SETT->getNewGameSettings(n));

	}
}

void BMainWindow::startGame(QString id) {
	if(id.startsWith("game")){
		IGameWidget *w = games->getGame(id);
		setCentralWidget(w);
		w->focus();
	}
}

BMainWindow *B_MAIN;




