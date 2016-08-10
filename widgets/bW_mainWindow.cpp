#include "bW_mainWindow.h"
#include <widgets/bW_mainMenu.h>
#include <widgets/bW_leaderBoard.h>
#include <widgets/bW_statistics.h>

BMainWindow::BMainWindow() {
	games = new BGames;
	resize(550, 430);
}

void BMainWindow::changeWidget(QString n) {
	if(n.startsWith("mainMenu")){
		setCentralWidget(new BMainMenu());

	}else if(n.startsWith("game")){
	 setCentralWidget(B_SETT->getNewGameSettings(n));

	}else if(n.startsWith("leaderBoards")){
		QString s = QStringRef(&n, n.indexOf(' ') + 1, n.length() - n.indexOf(' ') - 1).toString();
		setCentralWidget(new BLeaderBoardWidget(s));

	}
}

void BMainWindow::startGame(QString id) {
	if(id.startsWith("game")){
		IGameWidget *w = games->getGame(id);
		setCentralWidget(w);
		w->setFocus(Qt::OtherFocusReason);
	}
}

void BMainWindow::keyReleaseEvent(QKeyEvent *event) {
	if(IGameWidget *w = dynamic_cast<IGameWidget*>(centralWidget())){
		w->keyPress(event->key());
	}
}

BMainWindow *B_MAIN;




