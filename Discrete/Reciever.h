#pragma once

#include "string"

class Reciever{
public:
	Reciever();

	void init(std::string statement);


	~Reciever();

private:
	void decipher(std::string statement);
};

