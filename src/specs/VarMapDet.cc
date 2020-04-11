
#include "VarMapDet.h"
#include "VarMapP.h"
using namespace std;

VarMapDet::VarMapDet(VarMapP vm) {
  nvars = 0;
	dets = vector<vector<int> > (vm.nVars());
  
}

void VarMapDet::addEntry(VarMapP vm, string a, string b) {
	int i=vm.getVar(a);
	int j=vm.getVar(b);
  if (!contains("det_"+a +"_"+b)){
	dets[i].at(j)=++nvars;
   
    varToName[nvars] = ("det_"+a +"_"+b);
    nameToVar["det_"+a +"_"+b] = nvars;
  }
}


string VarMapDet::getName(int var) {
  return varToName[var];
}

int VarMapDet::getVar(VarMapP vm, string a, string b) {
	string name = "det_"+a +"_"+b;
  int res = nameToVar[name];
  if(!res){
    addEntry(vm,a,b);
    res = ++nvars;
  }
  return res;
}


bool VarMapDet::contains(string name){

  return (bool)nameToVar[name];
}

vector<vector<int> > VarMapDet::getDets(){
	return dets;
}

/*vector<vector<int> >* VarMapAtt::intVars() {
  vector<vector<int> > *res = new vector<vector<int> >;
  for(map<vector<int>, string>::iterator it = varToName.begin(); it != varToName.end(); ++it)
    res->push_back(it->first);
  return res;
}*/

long VarMapDet::nVars() {
  return varToName.size();
}



