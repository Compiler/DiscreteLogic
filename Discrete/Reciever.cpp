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
	std::string tmp = statement.info;
	while(pos != std::string::npos){
		if(pos < tmp.length() && tmp[pos] == Logic::and){
			std::cout << "Found ^ operator\n";
			if(pos + 1 < tmp.length())
				tmp = tmp.substr(pos + 1);
			else
				break;

			pos = tmp.find_first_of(searchString);
		}
		if(pos < tmp.length() && tmp[pos] == Logic::or){
			std::cout << "Found v operator\n";
			if(pos + 1 < tmp.length())
				tmp = tmp.substr(pos + 1);
			else
				break;
			pos = tmp.find_first_of(searchString);
		}
		if(pos < tmp.length() && tmp[pos] == Logic::conditional){
			std::cout << "Found -> operator\n";
			if(pos + 1 < tmp.length()){
				tmp = tmp.substr(pos + 1);
				
			}
			else
				break;
			pos = tmp.find_first_of(searchString);
		}
	}
	

		std::cout << tmp.substr(pos+1);

}


Reciever::~Reciever(){
}
