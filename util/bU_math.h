#ifndef BRAINTRAINING_MATH_BUTIL_H
#define BRAINTRAINING_MATH_BUTIL_H
#include <bdefines.h>

enum class BMathOper { None, Plus, Minus, Multiply, Divide };

class BMathExpr{
	BMathExpr *first, *second;
	BMathOper oper;

public:
	BMathExpr(): first(nullptr), second(nullptr), oper(BMathOper::None) { }
	BMathExpr(BMathExpr *f, BMathExpr *s, BMathOper o): first(f), second(s), oper(o) { }

	virtual ~BMathExpr();
 virtual QString toString();
 virtual int getResult() const;

#define B_MATH_ADD_OPERATION(a) bool operator a (const BMathExpr &s){\
		return getResult() a s.getResult();\
	}

	B_MATH_ADD_OPERATION(%)
	B_MATH_ADD_OPERATION(<)
	B_MATH_ADD_OPERATION(>)
	B_MATH_ADD_OPERATION(<=)
	B_MATH_ADD_OPERATION(>=)
	B_MATH_ADD_OPERATION(==)

};

class BMathExprNum : public BMathExpr{
 int num;

public:
	BMathExprNum(int n): num(n) { }

	virtual ~BMathExprNum() { }
	virtual QString toString() { return QString::number(num); }
	virtual int getResult() const{ return num; }
};

#endif //BRAINTRAINING_MATH_BUTIL_H
