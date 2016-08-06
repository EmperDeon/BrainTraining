#ifndef BRAINTRAINING_MATH_BMAIN_H
#define BRAINTRAINING_MATH_BMAIN_H
#include <I/bdefines.h>

class BMathGame : public IGame{


public:
	BMathGame();

	virtual QString getName();
	virtual QString getCategory();
 virtual IGameWidget *getWidget();
};


#endif //BRAINTRAINING_MATH_BMAIN_H
