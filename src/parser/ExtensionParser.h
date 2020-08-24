#ifndef __EXTENSION_PARSER__
#define __EXTENSION_PARSER__

#include <iostream>
#include <vector>
#include <map>
#include "VarMapP.h"

using namespace std;

/** 
 * \class CommandLineHelper
 * \brief Class used to parse the command line variables provided to the main function
 */
class ExtensionParser {

 public:

  ExtensionParser(string inputFile);

  void parseInstance();

  int containsArg(string key);

  void printArgs();
  
  VarMapP getArguments();

  void parseExtensionsVector();

  void parseArgumentVector();

  void printExtensions();

	vector<string> getArgs();	

  int getNumVar();

 private:
  vector<string> args;
  vector<vector<string>> extensions;
  VarMapP arguments;
  string instanceFile;
  string outputFile;
  int k;
};
#endif
