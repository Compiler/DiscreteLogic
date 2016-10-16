#pragma once

#include "Statement.h"


class Action{
public:
	Action();


	void truthTable(Statement statement);

	~Action();

private:



	int amountOfOperators;
	
};

