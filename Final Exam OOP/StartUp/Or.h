#pragma once

#include "LogicalExpression.h"
#include <iostream>

class Or : public LogicalExpression
{
private:
	LogicalExpression* expr1;
	LogicalExpression* expr2;

public:
	Or(LogicalExpression* expr1, LogicalExpression* expr2);

	bool getValue() const;
	void print() const;
};