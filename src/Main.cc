#include "IParser.h"
#include "ParserFactory.h"
#include "MaxSATSolver.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "VarMapP.h"
#include "VarMapDet.h"
#include "VarMapAtt.h"

//#include "compute_formula_stable.h"

using namespace std;

int main(int argc, char** argv){
/*
  parser la ligne de commande
  - fichier d'entrée
  - fichier de sortie
  - format de sortie
  parser le fichier d'entrée
  - VarMap des arguments remplie
  - VarMap des accepted remplie
  - Création de la varmap d'attaque
*/



  /*cout << "run unsat test ..." << endl;
  vector<int> lits;
  MaxSATSolver maxsat(3, 0);
  lits = {1, 2};
  maxsat.addClause(lits);
  lits = {1, -2};
  maxsat.addClause(lits);
  lits = {-1, -2};
  maxsat.addClause(lits);
  lits = {-1, 2};
  maxsat.addClause(lits);

  std::vector<int> model;
  uint64_t cost = 0;
  MaxSATSolver::ReturnCode ret = maxsat.compute_maxsat(model, cost);

  if(ret == MaxSATSolver::ReturnCode::SATISFIABLE)
	cout << "satisfiable" << endl;
  else if(ret == MaxSATSolver::ReturnCode::UNSATISFIABLE)
	cout << "unsatisfiable" << endl;
  else if(ret == MaxSATSolver::ReturnCode::UNKNOWN)
	cout << "unknown" << endl;
*/
/*
  int nbArgs = 2;
  int nbPossibleAttacks = 
  MaxSATSolver maxsat(nb_variables, 0);
*/


VarMapP vm = VarMapP();
vm.addEntry("a");
vm.addEntry("b");
int i = vm.getVar("a");
cout<<"a = "<<i<<endl;
cout<<"b = "<<vm.getVar("b")<<endl;
cout<<"nombre d'elements dans la vm "<<vm.nVars()<<endl;

VarMapAtt attmap = VarMapAtt(vm);
attmap.addEntry(vm,"a","b");
cout<<"on est arrivé la"<<endl;
vector<vector<int> >attacks = attmap.getAttacks();
cout<<"attacks a bien été get"<<endl;
cout<<"att(a,b)"<<attacks[vm.getVar("a")-1][vm.getVar("b")-1]<<endl;
return 0;

}
