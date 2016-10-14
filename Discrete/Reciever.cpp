#include "Reciever.h"
#include "iostream"


Reciever::Reciever(){
}


void Reciever::init(std::string info){
	statement.info = info;
	decipher();
	

}


void Reciever::decipher(){
	std::size_t pos = statement.info.find_first_of(Logic::and);
	if(pos != std::string::npos){
		if(statement.info[pos] == Logic::and){
			std::cout << "Found ^ operator\n";
		}
		if(statement.info[pos] == Logic::or){
			std::cout << "Found v operator\n";
		}
		if(statement.info[pos] == Logic::conditional){
			std::cout << "Found -> operator\n";
		}
	} else
		std::cout << "Couldn't find any logical operators";

}


Reciever::~Reciever(){
}
