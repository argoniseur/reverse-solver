#include "MaxSATSolver.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "VarMapP.h"
#include "VarMapDet.h"
#include "VarMapAtt.h"
#include "ExtensionParser.h"
#include "CommandLineHelper.h"
#include "compute_formula_stable.h"

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


CommandLineHelper clh = CommandLineHelper(argc, argv);
clh.parseCommandLine();



ExtensionParser ep = ExtensionParser(clh.getInstanceFile());
ep.parseInstance();
ep.printArgs();


VarMapP vm = ep.getArguments();

vector<vector<int>> v = vm.getExtensions();
for(unsigned int i=0;i<v.size();i++){
  for(unsigned int j=0;j<v[i].size();j++){
    cout << v[i][j] << ' ';
  }
  cout << endl;
}

/*
VarMapP vm = VarMapP();
vm.addEntry("a");
vm.addEntry("b");
vm.addEntry("c");

cout<<"a = "<<vm.getVar("a")<<endl;
cout<<"b = "<<vm.getVar("b")<<endl;
cout<<"c = "<<vm.getVar("c")<<endl;
cout<<"nombre d'elements dans la vm "<<vm.nVars()<<endl;



attmap.addEntry("a","b");
cout<<"Entry AttMap ok!"<<endl;
detmap.addEntry("b","a");
detmap.addEntry("c","b");
cout<<"Entry DetMap ok!"<<endl;

cout<<"on est arrivé la"<<endl;
vector<vector<int> >attacks = attmap.getAttacks();
vector<vector<int> >dets = detmap.getDets();
cout<<"attacks a bien été get"<<endl;
cout<<"att(a,b)"<<attacks[vm.getVar("a")-1][vm.getVar("b")-1]<<endl;
cout<<"det(b,a)"<<dets[vm.getVar("b")-1][vm.getVar("a")-1]<<endl;
cout<<"det(c,b)"<<dets[vm.getVar("c")-1][vm.getVar("b")-1]<<endl;

Compute_formula_stable(vm,attmap,vm,detmap);

*/
VarMapAtt attmap = VarMapAtt(vm);
VarMapDet detmap = VarMapDet(vm);

vector<string> args = ep.getArgs();
for (unsigned int i =0;i<args.size();i++){
	for (unsigned int j = 0; j<args.size();j++){
		attmap.addEntry(args[i],args[j]);
		detmap.addEntry(args[i],args[j]);
	}
}

cout<<"okii"<<endl;
return 0;

}
