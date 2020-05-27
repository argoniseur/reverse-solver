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
int max = 0;
for(unsigned int i=0;i<test.size();i++){
    for(unsigned int j=0;j<test[i].size();j++){
      if (max < abs(test[i][j])){
        max = abs(test[i][j]);
      }
    }
  }

QdimacsParser qd = QdimacsParser(vm.nVars());

qd.parseToFile(test, max);

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

vector<int> attModel = qd.parseFromFile(result);

if(attModel[0] == 1){
  attModel.erase(attModel.begin());
  AspartixParser ap = AspartixParser(clh.getOutputFile(), ep.getArgs(), attModel);
  ap.parseFile(attmap);
  cout << "Fichier généré" << endl;
}else{
  cout << "Insatisfiable" << endl;
}


return 0;

}
