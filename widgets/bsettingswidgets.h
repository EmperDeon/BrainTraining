#ifndef BRAINTRAINING_BSETTINGSWIDGETS_H
#define BRAINTRAINING_BSETTINGSWIDGETS_H
#include <I/bdefines.h>

class BSettLevel : public QWidget{
	Q_OBJECT

 int selectedButton = 0;

protected slots:
	void buttonToggled(int, bool checked);

public:
	BSettLevel(int max);
	int getValue() { return selectedButton; }

};

class BSettRadio : public QWidget{
	Q_OBJECT

 QString selected;

protected slots:
	void buttonToggled(QAbstractButton *button, bool checked);

public:
 BSettRadio(QStringList list);

	QString getSelected() { return selected; }
};
#endif //BRAINTRAINING_BSETTINGSWIDGETS_H
