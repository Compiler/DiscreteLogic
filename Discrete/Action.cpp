#include "Action.h"
#include <math.h> 
#include "iostream"

Action::Action(){
}


void Action::truthTable(Statement statement){
	amountOfOperators = (int)pow(2, statement.variables.size());

	std::cout << "\n\n\tTruth Table\n\n\t";
	for(int i = 0; i < statement.variables.size(); i++){
		std::cout << "| " << statement.variables[i] << " ";
	}
	std::cout << "| " << statement.info << " ";

}


Action::~Action(){
}
