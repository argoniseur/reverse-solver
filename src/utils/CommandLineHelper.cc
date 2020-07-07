#include "CommandLineHelper.h"


using namespace std;
#define USAGE "Help:\n\
-o: Output file\n\
-f: Input file\n\
-k: Additionnal arguments"
CommandLineHelper::CommandLineHelper(int argc, char** argv) {
  instanceFile = "";
  outputFile = "output.apx";
  k = 0;
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
    if(!args[i].compare("-k")) {
      i++;
      k = stoi(args[i]);
      continue;
    }
    if(!args[i].compare("-h")) {
      cout << USAGE << endl;
      exit(0);
    }
  }
}

string CommandLineHelper::getInstanceFile(){
    return instanceFile;
  }

string CommandLineHelper::getOutputFile(){
    return outputFile;
  }

int CommandLineHelper::getK(){
  return k;
}