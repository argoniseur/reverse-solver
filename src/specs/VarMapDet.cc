#include "VarMapDet.h"

using namespace std;

VarMapDet::VarMapDet(VarMapP vm) {
 	this->vm = vm;
  	nvars = ((vm.nVars()*vm.nVars()) + vm.nVars());
	vector<int> vect(vm.nVars(), 0);
	for (int i = 0; i<vm.nVars();i++){
		dets.push_back(vect);
		}
	
}

void VarMapDet::addEntry(string a, string b) {
	VarMapP vm = this->getVm();
	
	int i=vm.getVar(a);
	int j=vm.getVar(b);
	
  if (!contains("det_"+a +"_"+b)){
	
	dets[i-1][j-1]=++nvars;
   	
    varToName[nvars] = ("det_"+a +"_"+b);
    nameToVar["det_"+a +"_"+b] = nvars;
	
  }
}


string VarMapDet::getName(int var) {
  return varToName[var];
}

int VarMapDet::getVar(string a, string b) {
	string name = "det_"+a +"_"+b;
  int res = nameToVar[name];
  if(!res){
    addEntry(a,b);
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

VarMapP VarMapDet::getVm(){
	return this->vm;
}

