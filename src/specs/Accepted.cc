#include "Accepted.h"

Accepted::Accepted(VarMapP *vm) : varMap(*vm){
	
	nbAccepted = 0;
}

void Accepted::addAccepted(string var){
	int variable = varMap.getVar(var);
	accs.push_back(variable);
	++nbAccepted;
	}

vector<int>* Accepted::getAccs(){
	return &accs;
	}

int Accepted::nAccs(){
	return nbAccepted;
	}


