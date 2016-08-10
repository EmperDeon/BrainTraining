#include "bW_mainMenu.h"


BMainMenu::BMainMenu() : games(B_MAIN->getGames()) {
	b_list = new QList<BGameButton*>;

	l_main = new QVBoxLayout;
	l_list = new QGridLayout;
	w_scroll = new QScrollArea;

	// Widget init
	init();
	initLists();
	reInitLayouts();

	setLayout(l_main);
}


void BMainMenu::initLists() {
	for(QString k : games->getIds()){
		b_list->append(new BGameButton(this, k, games->getName(k), games->getCategory(k)));
	}


}

void BMainMenu::reInitLayouts() {
	int i = 0;
	if(columnsNum == 0) {
		columnsNum = 1;
	}

	for ( int x = 0; x < l_list->rowCount(); x++ )
		for ( int y = 0; y < l_list->columnCount(); y++ )
			l_list->removeItem(l_list->itemAtPosition(x, y));

	for ( BGameButton *b : *b_list ) {
		l_list->addWidget(b, i / columnsNum, i % columnsNum, Qt::AlignCenter);
		i++;
	}
}


void BMainMenu::resizeEvent(QResizeEvent *event) {
	if(columnsNum != width() / 245)
		columnsNum = width() / 245,
			reInitLayouts();

	event->accept();
}

void BMainMenu::init() {
	QWidget* w = new QWidget;

	setMinimumWidth(245);

	l_list->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	l_list->setMargin(0);
	l_list->setSpacing(20);

	w->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	w->setLayout(l_list);

	w_scroll->setWidget(w);
	w_scroll->setWidgetResizable(true);
	w_scroll->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	w_scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	w_scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	w_scroll->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	w_scroll->setFrameShape(QFrame::NoFrame);

	l_main->addWidget(w_scroll);
}

void BMainMenu::menuClick(QString id) {
 B_MAIN->changeWidget(id);
}



