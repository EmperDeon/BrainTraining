#ifndef BRAINTRAINING_MATH_BGEN_H
#define BRAINTRAINING_MATH_BGEN_H
#include <I/bdefines.h>
#include "math/bmathutil.h"

class BMathGen{
public:
	BMathGen() { }

	static BMathExpr *getNextExpr();
};

#endif //BRAINTRAINING_MATH_BGEN_H
