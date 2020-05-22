#include "VarMapP.h"

using namespace std;

VarMapP::VarMapP() {
  nvars = 0;
  
}

void VarMapP::addEntry(string name) {
  if(!contains(name)){

    varToName[++nvars] = name;
    nameToVar[name] = nvars;

  }
}

string VarMapP::getName(int var) {
  return varToName[var>0 ? var : -var];
}

int VarMapP::getVar(string name) {
  int res = nameToVar[name];
  if(!res){
    addEntry(name);
    res = nvars;
  }
  return res;
}

bool VarMapP::contains(string name){
  return (bool)nameToVar[name];
}

void VarMapP::addExtension(vector<int> x){
  extensions.push_back(x);
}

vector<int>* VarMapP::intVars() {
  vector<int> *res = new vector<int>;
  for(map<int, string>::iterator it = varToName.begin(); it != varToName.end(); ++it)
    res->push_back(it->first);
  return res;
}

long VarMapP::nVars() {
  return varToName.size();
}

vector<vector<int> > VarMapP::getExtensions(){
	return extensions;
}




