#pragma once

#include <string>

class LogicalExpression
{
public:
	LogicalExpression() {};

	virtual bool getValue() const = 0;
	virtual void print() const = 0;
};