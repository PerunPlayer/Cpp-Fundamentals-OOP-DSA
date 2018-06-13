#include "stdafx.h"
#include "Or.h"

Or::Or(LogicalExpression* _expr1, LogicalExpression* _expr2)
{
	expr1 = _expr1;
	expr2 = _expr2;
}

bool Or::getValue() const
{
	return (expr1->getValue() || expr2->getValue());
}

void Or::print() const
{
	std::cout << "or (";
	expr1->getValue();
	std::cout << ", ";
	expr2->getValue();
	std::cout << ")";
}
