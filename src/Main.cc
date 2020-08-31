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
//ep.printExtensions();

//getting of the of the arguments
VarMapP vm = ep.getArguments();



//TO DO: store in file
vector<string> args = ep.getArgs();

//ici jai la varmap des arguments et le vector de string deja rempli par les non additionnels

//eventuel ajout des arguments additionnels:

//TO DO : modifier le constructeur de ExtensionParser en enlevant le k //DONE
// et le rajouter ici (petit bout de code qui instancie les arguments auxiliaires)
//if clh.getK() > 0 petit bout de code de taches additionnelles 

if (clh.getK() > 0) {
	int k = clh.getK();
	string tmpAux = "aux";
  	for(int i=0;i<k;i++){ //on devrait mettre ce code avant de lire le fichier des extensions (dans une fonction à part)
  		vm.addEntry(tmpAux + to_string(i));
  		args.push_back(tmpAux + to_string(i));
	}
}

/*vector<vector<int> > extensionss = vm.getExtensions();
for (unsigned int i = 0; i<extensionss.size(); i++){
	for (unsigned int j = 0; j<extensionss[i].size(); j++){
		cout<<vm.getName(extensionss[i][j]);
	}
	cout<<endl;
}*/

//creating of the attacks and the defeated
VarMapAtt attmap = VarMapAtt(vm);
VarMapDet detmap = VarMapDet(vm);

//iteration sur args avant de remplir les map dattacks et de defeated
//for (unsigned int i = 0; i<args.size();i++){
//	cout<<args[i]<<endl;
//}

for (unsigned int i =0;i<args.size();i++){
	for (unsigned int j = 0; j<args.size();j++){
		attmap.addEntry(args[i],args[j]);
		detmap.addEntry(args[i],args[j]);
	}
}


/*vector<vector<int> > atts = attmap.getAttacks();
vector<vector<int> > dets = detmap.getDets();
for (unsigned int i = 0;i<args.size();i++){
	for (unsigned int j = 0; j<args.size();j++){
		cout<<"att "<<args[i]<<" "<<args[j]<<" : "<<atts[i][j]<<endl;
		cout<<"det "<<args[i]<<" "<<args[j]<<" : "<<dets[i][j]<<endl;
	}
}*/
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
  AspartixParser ap = AspartixParser(clh.getOutputFile(), args, attModel);
  ap.parseFile(attmap);
  cout << "DONE" << endl;
}else{
  cout << "UNSAT" << endl;
}

remove("tmp.qdimacs");
return 0;

}
