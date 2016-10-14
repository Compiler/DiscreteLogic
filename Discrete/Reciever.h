#pragma once

#include "string"
#include "Statement.h"
#include "Logic.h"

class Reciever{
public:
	Reciever();

	void init(std::string info);


	static const char conditional = '->';
	static const char and = '^';
	static const char or = 'v';

	~Reciever();

private:
	
	void decipher();

	Statement statement;
};

