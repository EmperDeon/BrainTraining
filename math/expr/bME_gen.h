#ifndef BRAINTRAINING_MATH_EXPR_GEN_H
#define BRAINTRAINING_MATH_EXPR_GEN_H
#include <bdefines.h>
#include "util/bU_math.h"

namespace BME {

	class Gen {
	public:
		Gen() { }

		static BMathExpr *getNextExpr();
	};

}
#endif //BRAINTRAINING_MATH_EXPR_GEN_H
