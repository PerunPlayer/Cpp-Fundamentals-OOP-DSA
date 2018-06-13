#pragma once

#include "LogicalExpression.h"

#include <iostream>

class Constant : public LogicalExpression
{
private:
	bool value;

public:
	Constant(bool _value);

	bool getValue() const;
	void print() const;
};