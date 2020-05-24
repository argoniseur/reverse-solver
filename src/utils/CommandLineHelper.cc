#include "CommandLineHelper.h"


using namespace std;

CommandLineHelper::CommandLineHelper(int argc, char** argv) {
  instanceFile = "";
  outputFile = "output.apx";
  for(int i=1; i<argc; ++i) {
    args.push_back(string(argv[i]));
  }
}

void CommandLineHelper::parseCommandLine() {
  if(args.size() == 0) {
    cout << "Erreur sur les arguments" << endl ;
    mustExit = true;
    return;
  }

  for(unsigned int i=0; i<args.size(); i++) {
    
    if(!args[i].compare("-o")) {
      i++;
      outputFile = args[i];
      continue;
    }
    if(!args[i].compare("-f")) {
      i++;
      instanceFile = args[i];
      continue;
    }
  }
}

string CommandLineHelper::getInstanceFile(){
    return instanceFile;
  }

string CommandLineHelper::getOutputFile(){
    return outputFile;
  }