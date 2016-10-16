#include "Action.h"
#include <math.h> 
#include "iostream"

Action::Action(){
}


void Action::truthTable(Statement statement){

	drawHeader(statement);


	const unsigned n = statement.variables.size();
	std::vector<std::vector<int> > truthTable(n+1, std::vector<int>(1 << n));

	unsigned num_to_fill = 1U << (n - 1);
	for(unsigned col = 0; col < n; ++col, num_to_fill >>= 1U){
		for(unsigned row = num_to_fill; row < (1U << n); row += (num_to_fill * 2)){
			std::fill_n(&truthTable[col][row], num_to_fill, 1);
		
		}
	}

	truthTable[2][0] = truthTable[0][0] & truthTable[1][0];
	truthTable[2][1] = truthTable[0][1] & truthTable[1][1];
	truthTable[2][2] = truthTable[0][2] & truthTable[1][2];
	truthTable[2][3] = truthTable[0][3] & truthTable[1][3];








	std::cout << "\n\t";
	for(unsigned x = 0; x < (1 << n); ++x){
		for(unsigned y = 0; y < n + 1; ++y){
			if(truthTable[y][x] == 1)
				std::cout << "| T ";
			else
				std::cout << "| F ";
		}
		std::cout << "\n\t";
	}

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
