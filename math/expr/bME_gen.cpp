#include "math/expr/bME_gen.h"

typedef BMathOper MO;
typedef BMathExpr ME;
typedef BMathExprNum MEN;

inline int brand(int i, int a){
	return qrand() % (a - i) + i;
}

inline QList<MO> blist(QJsonArray a){
	QList<MO> r;
	for(QJsonValue v : a){
		QString s = v.toString();
		if(s == "+"){        r << MO::Plus;
		} else	if(s == "-"){ r << MO::Minus;
		} else	if(s == "*"){ r << MO::Multiply;
		} else	if(s == "/"){ r << MO::Divide;
		} else {
// TODO: Add more operation
		}
	}
	return r;
}

inline ME* bPMin(ME *a, ME *b) { return *a < *b ? a : b; }
inline ME* bPMax(ME *a, ME *b) { return *a > *b ? a : b; }

BMathExpr *BME::Gen::getNextExpr() {
	ME *l;
	int lev = B_SETT->getSettings("game_01")["level"].toInt();
	QJsonObject o = B_SETT->getGenerators("game_01")[lev].toObject();

//	bool brackets = o["bracket"].toBool();
	int count = o["count"].toInt(),
		     max = o["max"].toInt(),
		     min = o["min"].toInt();
 QList<MO> oper = blist(o["oper"].toArray());

	l = new MEN(brand(min, max));

	for ( int i = 1; i < count; ++i ) {
  ME *t = new MEN(brand(min, max));
		MO op = oper[qrand() % oper.size()];

		// TODO: Add more operations
		switch(op){
			case BMathOper::None:break;
			case BMathOper::Plus:				 l = new ME(l, t, op); break;
			case BMathOper::Minus:    l = new ME(bPMax(l, t), bPMin(l, t), op); break;
			case BMathOper::Multiply:break;
			case BMathOper::Divide:break;
		}
	}

	return l;
}


