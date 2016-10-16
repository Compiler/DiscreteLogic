#pragma once

#include "Statement.h"


class Action{
public:
	Action();


	void truthTable(Statement statement);

	~Action();

private:

	void drawHeader(Statement statement);
	void drawLine(int count);
	int amountOfValues;
	
};

