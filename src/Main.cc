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
#include "compute_phi_s.h"
#include "AspartixParser.h"
#include "QdimacsParser.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <cstring>
using namespace std;

int main(int argc, char** argv){
/*
  parser la ligne de commande
  - fichier d'entrée
  - fichier de sortie
  - format de sortie
  parser le fichier d'entrée
  - VarMap des arguments remplie
  - Création de la varmap d'attaque
  - Création de la varmap des defeated
  - Création de phi_sigma_S
  - Solving de phi_sigma_S par le maxSat solver
  - recuperation des modeles
  - fichier sortie
*/


//parsing of thecommand line
CommandLineHelper clh = CommandLineHelper(argc, argv);
clh.parseCommandLine();


//parsing of the extension file
ExtensionParser ep = ExtensionParser(clh.getInstanceFile());
ep.parseInstance();
//ep.printArgs();

//getting of the of the arguments
VarMapP vm = ep.getArguments();

//creating of the attacks and the defeated
VarMapAtt attmap = VarMapAtt(vm);
VarMapDet detmap = VarMapDet(vm);

//TO DO: store in file
vector<string> args = ep.getArgs();
for (unsigned int i =0;i<args.size();i++){
	for (unsigned int j = 0; j<args.size();j++){
		attmap.addEntry(args[i],args[j]);
		detmap.addEntry(args[i],args[j]);
	}
}

vector<vector<int> > atts = attmap.getAttacks();


vector<vector<int> > test = phi_sigma_S(vm,attmap,detmap);
//essai de remplir le solver : 

//initialisation of the solver
MaxSATSolver maxsat(test.size(), 0);
cout << " solver: " << maxsat.getSolverName () << " implementing version " << maxsat.getVersion() << endl;
cout<<"taille de test "<<test.size()<<endl;
cout << vm.nVars() << endl;
/*
for (unsigned int i=0;i<test.size();i++){
	maxsat.addClause(test[i]);
	cout<<"taille de test[i] "<<test[i].size()<<endl;
}
cout<<"solver rempli"<<endl;
//solving


vector<int> model;
  uint64_t core = 0;
  MaxSATSolver::ReturnCode ret = maxsat.compute_maxsat(model, core);

	if(ret == MaxSATSolver::ReturnCode::SATISFIABLE)
		cout << "satisfiable" << endl;
  	else 
		if(ret == MaxSATSolver::ReturnCode::UNSATISFIABLE)
		cout << "unsatisfiable" << endl;
  	else 
		if(ret == MaxSATSolver::ReturnCode::UNKNOWN)
		cout << "unknown" << endl;
  	else 
		if(ret == MaxSATSolver::ReturnCode::OPTIMAL)
		cout << "optimal" << endl;
 	else
		cout << "unknown result" << endl;

  cout << "returned core of size " << model.size() << endl;

  //assert (ret == MaxSATSolver::ReturnCode::OPTIMAL);
//affichage des models de la formule:

for (unsigned int i =0;i<model.size();i++){
	cout<<"model["<<i<<"]"<<model[i]<<endl;
}*/

QdimacsParser qd = QdimacsParser();

qd.parseToFile(test, vm.nVars());

string command = "./resources/CAQE/caqe --qdo " + qd.getFile();
char buffer[128];
string result = "";

// Open pipe to file
FILE* pipe = popen(command.c_str(), "r");
if (!pipe) {
   cout << "popen failed!" << endl;
}

// read till end of process:
while (!feof(pipe)) {

  // use buffer to read and add to result
  if (fgets(buffer, 128, pipe) != NULL)
    result += buffer;
  }

pclose(pipe);
cout << result << endl;
//execlp("./resources/CAQE/caqe", "--qdo" ,qd.getFile().c_str(), ">>", "sortie.qdimacs");



/*
int nargs = ep.getNumVar();
int debutIndicesAttaque = nargs+1;
int finIndicesAttaque = ((nargs*nargs)+nargs);
vector<int> attModel;
if(model.size()>0){
	for (int i=debutIndicesAttaque; i<finIndicesAttaque+1;i++){
	  cout << "i: " << i << " " << attmap.getName(i) << endl;
	  if(model[i] > 0){
	    attModel.push_back(model[i]);
	  }
	}
}
cout<<"fin attmodel"<<endl;

AspartixParser ap = AspartixParser(clh.getOutputFile(), ep.getArgs(), attModel);
ap.parseFile(attmap);
cout<<"parsing de sortie"<<endl;
*/
return 0;

}
