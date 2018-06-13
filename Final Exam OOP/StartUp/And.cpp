#include "stdafx.h"
#include "And.h"

And::And(LogicalExpression** _expressions, size_t _countOfExpressions)
{
	countOfExpressions = _countOfExpressions;
	for (size_t i = 0; i < MAX_EXPRESSIONS; i++)
	{
		expressions[i] = _expressions[i];
	}
}

void And::addExpression(LogicalExpression* expr)
{
	if (countOfExpressions < MAX_EXPRESSIONS)
	{
		expressions[countOfExpressions] = expr;
		countOfExpressions++;
		return;
	}

	std::cout << "Limit of expressions reached! Couldn't add this one.\n";
}

bool And::getValue() const
{
	bool value = expressions[0]->getValue();
	for (size_t i = 1; i < countOfExpressions; i++)
	{
		value = value && expressions[i]->getValue();
	}
	return value;
}

void And::print() const
{
	std::cout << "and (";
	for (size_t i = 0; i < countOfExpressions; i++)
	{
		expressions[i]->print();
		std::cout << ", ";
	}
	std::cout << ")\n";
}
