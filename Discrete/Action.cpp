#include "Action.h"
#include <math.h> 
#include "iostream"

Action::Action(){
}


void Action::truthTable(Statement statement){

	

	amountOfOperators = (int)pow(2, statement.variables.size());
	

	std::cout << "\n\n\tTruth Table\n\n\t";
	for(int i = 0; i < statement.variables.size(); i++){
		std::cout <<"___";
	}
	std::cout << "\n\t";
	for(int i = 0; i < statement.variables.size(); i++){
		std::cout << "| " << statement.variables[i] << " ";
	}
	std::cout << "| " << statement.info << "\n\t";


	bool **tableInfo;

	// Allocate memory
	tableInfo = new bool*[amountOfOperators];
	for(int i = 0; i < amountOfOperators; ++i)
		tableInfo[i] = new bool[statement.variables.size() + 1];










	// De-Allocate memory to prevent memory leak
	for(int i = 0; i < amountOfOperators; ++i)
		delete[] tableInfo[i];
	delete[] tableInfo;


}


Action::~Action(){
}
