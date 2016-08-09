#include "bleaderboard.h"


BLeaderBoardWidget::BLeaderBoardWidget(QString i): id(i) {
	QVBoxLayout *l_main = new QVBoxLayout;
 QGridLayout *l_grid = new QGridLayout;
	QPushButton *b = new QPushButton(tr("Close"));

	int t = 0;
 for(BLEntry e : B_SETT->getLEntry(B_SETT->getGameHash(id))){
	 QLabel *nl = new QLabel(QString::number(t+1)); nl->setProperty("lead_text", "true");
	 l_grid->addWidget(nl, t, 0, Qt::AlignTop | Qt::AlignLeft);

	 nl = new QLabel(e.getScore()); nl->setProperty("lead_text", "true");
	 l_grid->addWidget(nl, t, 1, Qt::AlignTop | Qt::AlignHCenter);

	 nl = new QLabel(e.getDate()); nl->setProperty("lead_text", "true");
	 l_grid->addWidget(nl, t++, 2, Qt::AlignTop | Qt::AlignRight);
	}

	l_grid->setVerticalSpacing(10);
	l_grid->setAlignment(Qt::AlignTop);
	l_main->addLayout(l_grid);
	l_main->addWidget(b, Qt::AlignHCenter | Qt::AlignBottom);

 connect(b, &QPushButton::clicked, [](){
	 B_MAIN->changeWidget("mainMenu");
 });

	setLayout(l_main);
}

