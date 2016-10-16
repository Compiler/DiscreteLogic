#include "Action.h"
#include <math.h> 
#include "iostream"

Action::Action(){
}


void Action::truthTable(Statement statement){

	drawHeader(statement);



	amountOfValues = (int)pow(2, statement.variables.size());


	bool **tableInfo;

	// Allocate memory			height
	tableInfo = new bool*[amountOfValues];
	for(int i = 0; i < amountOfValues; ++i)
		tableInfo[i] = new bool[statement.variables.size() + 1];
	int count = 1;
	for(int k = 0; k <= statement.variables.size(); k++){
		count *= 2;
		for(int i = 0; i < amountOfValues; i++){
			if(i < amountOfValues / count)
				tableInfo[k][i] = true;
			else
				tableInfo[k][i] = false;
		}
	}


	std::cout << "\n\t";
	for(int i = 0; i < amountOfValues; i++){
		for(int k = 0; k <= statement.variables.size(); k++){
			std::cout << "| ";
			if(tableInfo[k][i])
				std::cout << "T ";
			else
				std::cout << "F ";

		}
		std::cout << "\n\t";
	}







	char c;
	std::cin >> c;
	// De-Allocate memory to prevent memory leak
	for(int i = 0; i < amountOfValues; i++)
		delete[] tableInfo[i];
	delete[] tableInfo;


}


void Action::drawHeader(Statement statement){
	std::cout << "\n\n\tTruth Table\n\n\t";
	drawLine(statement.variables.size() * 5 + statement.info.length());
	std::cout << "\n\t";
	for(int i = 0; i < statement.variables.size(); i++){
		std::cout << "| " << statement.variables[i] << " ";
	}
	std::cout << "| " << statement.info << "\n\t";
	drawLine(statement.variables.size() * 5 + statement.info.length());
}


void Action::drawLine(int count){
	for(int i = 0; i < count; i++){
		std::cout << "-";
	}
}


Action::~Action(){
}
