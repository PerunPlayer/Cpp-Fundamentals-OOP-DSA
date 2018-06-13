#include "stdafx.h"
#include "Constant.h"

Constant::Constant(bool _value)
{
	value = _value;
}

bool Constant::getValue() const
{
	return value;
}

void Constant::print() const
{
	if (getValue() == true)
	{
		std::cout << "true";
		return;
	}
	std::cout << "false";
}
