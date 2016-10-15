#include "Reciever.h"
#include "iostream"


Reciever::Reciever(){
}


void Reciever::init(std::string info){
	statement.info = info;
	decipher();
	

}


void Reciever::decipher(){
	std::string searchString = "^v-";
	std::size_t pos = statement.info.find_first_of(searchString);
	std::vector<int> positions;

	while(pos != std::string::npos){
		if(statement.info[pos] == '^'/*Logic::and*/){
			std::cout << "Found ^ operator\n";
			if(pos + 1 < statement.info.length())
				statement.info = statement.info.substr(pos + 1);
			else
				break;
			pos = statement.info.find_first_of(searchString);
		}
		if(statement.info[pos] == 'v' /*Logic::or*/){
			std::cout << "Found v operator\n";
			if(pos + 1 < statement.info.length())
				statement.info = statement.info.substr(pos + 1);
			else
				break;
			pos = statement.info.find_first_of(searchString);
		}
		if(statement.info[pos] == '-'/*Logic::conditional*/){
			std::cout << "Found -> operator\n";
			if(pos + 1 < statement.info.length())
				statement.info = statement.info.substr(pos + 1);
			else
				break;
			pos = statement.info.find_first_of(searchString);
		}
	} //else
	

		std::cout << statement.info.substr(pos+1);

}


Reciever::~Reciever(){
}
