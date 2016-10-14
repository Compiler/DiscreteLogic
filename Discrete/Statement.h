
#pragma once
#include "string"
#include "vector"


struct Statement{

	std::string info;
	std::vector<char> variables;
	std::vector<char> logicalOperators;

	void addOperator(char logicalOperator){
		logicalOperators.push_back(logicalOperator);
	}
	void addVariable(char variable){
		variables.push_back(variable);
	}

};
