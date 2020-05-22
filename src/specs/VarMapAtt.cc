#include "VarMapAtt.h"

using namespace std;

VarMapAtt::VarMapAtt(VarMapP vm) {
	this->vm = vm;
  	nvars = (vm.nVars()+1);
	vector<int> vect(vm.nVars(), 0);
	for (int i = 0; i<vm.nVars();i++){
		attacks.push_back(vect);
		}
}

void VarMapAtt::addEntry(string a, string b) {
	VarMapP vm = this->getVm();
	int i=vm.getVar(a);
	int j=vm.getVar(b);
	
  if (!contains("att_"+a +"_"+b)){
	
	attacks[i-1][j-1]=++nvars;
    varToName[nvars] = ("att_"+a +"_"+b);
    nameToVar["att_"+a +"_"+b] = nvars;
  }
	
}


string VarMapAtt::getName(int var) {
  return varToName[var];
}

int VarMapAtt::getVar(string a, string b) {
	string name = "att_"+a +"_"+b;
  int res = nameToVar[name];
  if(!res){
    addEntry(a,b);
    res = ++nvars;
  }
  return res;
}


bool VarMapAtt::contains(string name){

  return (bool)nameToVar[name];
}

vector<vector<int> > VarMapAtt::getAttacks(){
	return attacks;
}

/*vector<vector<int> >* VarMapAtt::intVars() {
  vector<vector<int> > *res = new vector<vector<int> >;
  for(map<vector<int>, string>::iterator it = varToName.begin(); it != varToName.end(); ++it)
    res->push_back(it->first);
  return res;
}*/

long VarMapAtt::nVars() {
  return varToName.size();
}

VarMapP VarMapAtt::getVm(){
	return this->vm;
}



