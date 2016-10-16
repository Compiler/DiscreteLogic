
#include "iostream"
#include "string"
#include "Reciever.h"
#include "Action.h"

int main(){

	std::cout << "Enter a statement: \ne.g p->q^r\n";
	std::string statement;
	std::cin >> statement;
	Reciever reciever;
	reciever.init(statement);


	Action a;
	a.truthTable(reciever.getStatement());


	//studder
	char c;
	std::cin >> c;

	return 0;
}