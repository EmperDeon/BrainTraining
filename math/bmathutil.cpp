#include "bmathutil.h"

// BMathExpr
QString BMathExpr::toString() {
	if(first == nullptr || second == nullptr || oper == BMathOper::None)
		return "<ERROR>";

	QString r = first->toString();

	switch(oper){
		case BMathOper::None:               break;
		case BMathOper::Plus:     r += " + "; break;
		case BMathOper::Minus:    r += " - "; break;
		case BMathOper::Multiply: r += " * "; break;
		case BMathOper::Divide:   r += " / "; break;
	}

	return r + second->toString();
}

int BMathExpr::getResult() const{
	if(first == nullptr || second == nullptr || oper == BMathOper::None)
		return 0;

	int r = first->getResult();

	switch(oper){
		case BMathOper::None:     return 0;
		case BMathOper::Plus:     return r + second->getResult();
		case BMathOper::Minus:    return r - second->getResult();
		case BMathOper::Multiply: return r * second->getResult();
		case BMathOper::Divide:   return r / second->getResult();
	}
}

BMathExpr::~BMathExpr() {
 if(first != nullptr)
	 delete first;

	if(second != nullptr)
		delete second;
}


// BMathExpr


