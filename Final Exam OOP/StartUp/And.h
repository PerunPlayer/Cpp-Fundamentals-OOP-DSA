#pragma once

#include "LogicalExpression.h"
#include <iostream>

const size_t MAX_EXPRESSIONS = 10;

class And : public LogicalExpression
{
private:
	LogicalExpression* expressions[MAX_EXPRESSIONS];
	size_t countOfExpressions;

public:
	And(LogicalExpression** _expressions, size_t _countOfExpressions);

	void addExpression(LogicalExpression*);
	bool getValue() const;
	void print() const;
};