#include "bWU_settingsWidgets.h"

// BSettLevel
#define LINE_SIZE 5

BSettLevel::BSettLevel(int max) {
 QVBoxLayout *l_main = new QVBoxLayout;
	QButtonGroup *b_group = new QButtonGroup;

	QHBoxLayout* l_temp = new QHBoxLayout;
 l_temp->setAlignment(Qt::AlignCenter);
	l_main->addLayout(l_temp);

	for(int i = 0 ; i <= max ; i++){
		if(i % LINE_SIZE == 0)
			l_temp = new QHBoxLayout,
				l_temp->setAlignment(Qt::AlignCenter),
				l_main->addLayout(l_temp);

  QPushButton *t = new QPushButton(QString::number(i));
		t->setFixedSize(30, 30);
		t->setCheckable(true);
		l_temp->addWidget(t);
		b_group->addButton(t, i);
	}

	connect(b_group, SIGNAL(buttonToggled(int, bool)), this, SLOT(buttonToggled(int, bool)));
	b_group->buttons()[0]->setChecked(true);

	l_main->setAlignment(Qt::AlignCenter);
	setLayout(l_main);
}

void BSettLevel::buttonToggled(int button, bool checked) {
	if(checked)
		selectedButton = button;
}
// BSettLevel


// BSettRadio
BSettRadio::BSettRadio(QStringList list) {
	QVBoxLayout *l_main = new QVBoxLayout;
 QButtonGroup *b_group = new QButtonGroup;

	for(QString s : list){
		QRadioButton *t = new QRadioButton(s);

		b_group->addButton(t);
		l_main->addWidget(t);
	}

	connect(b_group, SIGNAL(buttonToggled(QAbstractButton *, bool)), this, SLOT(buttonToggled(QAbstractButton *, bool)));
 b_group->buttons()[0]->setChecked(true);

	l_main->setAlignment(Qt::AlignCenter);
	setLayout(l_main);
}

void BSettRadio::buttonToggled(QAbstractButton *button, bool checked) {
 if(checked)
	 selected = button->text();
}
// BSettRadio



