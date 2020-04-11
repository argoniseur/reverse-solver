#ifndef ACCEPTED_H
#define ACCEPTED_H


#include <vector>
#include <string>
#include <iostream>

#include "VarMapP.h"

using namespace std;

class Accepted{

	public :
	
		Accepted(VarMapP *vm);

		void addAccepted(string var);

		vector<int>* getAccs();
	
		int nAccs();

	protected :
		
		VarMapP varMap;

	private :
		vector<int> accs;
		int nbAccepted;



};

#endif
