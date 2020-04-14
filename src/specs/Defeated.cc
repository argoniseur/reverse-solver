#include "Defeated.h"

using namespace std;

	//constructor
	 Defeated::Defeated(VarMapP *vm) : varMap(*vm){
		nbDefeats = 0;
	}
	

	//adding the defeated relation 
	// from has defeated to (acc(from) and att(from,to))
	void Defeated::addDefeated(string from, string to){
		int det = varMap.getVar(from);
		int def = varMap.getVar(to);
		defeats[det].push_back(def);
		++nbDefeats;
	}

	vector<int> *Defeated::getDefeatedBy(int var){
		return &defeats[var];
	}

	unsigned int Defeated::nDefeats(){
		return nbDefeats;
	}