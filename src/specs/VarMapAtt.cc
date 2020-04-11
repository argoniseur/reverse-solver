
#include "VarMapAtt.h"
#include "VarMapP.h"
using namespace std;

VarMapAtt::VarMapAtt(VarMapP vm) {
  nvars = 0;
	attacks = vector<vector<int> > (vm.nVars());
  
}

void VarMapAtt::addEntry(VarMapP vm, string a, string b) {
	int i=vm.getVar(a);
	int j=vm.getVar(b);
  if (!contains("att_"+a +"_"+b)){
	attacks[i].at(j)=++nvars;
   
    varToName[nvars] = ("att_"+a +"_"+b);
    nameToVar["att_"+a +"_"+b] = nvars;
  }
}


string VarMapAtt::getName(int var) {
  return varToName[var];
}

int VarMapAtt::getVar(VarMapP vm, string a, string b) {
	string name = "att_"+a +"_"+b;
  int res = nameToVar[name];
  if(!res){
    addEntry(vm,a,b);
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



