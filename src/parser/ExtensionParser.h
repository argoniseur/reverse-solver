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
  /**
   * \fn CommandLineHelper
   * \brief Constructor
   * \param argc : the number of program's arguments passed in main function
   * \param argv : the program's arguments passed in main function
   */
  ExtensionParser(string inputFile);

  /**
   * \fn parseCommandLine
   * \brief Constructor
   */  
  void parseInstance();

  int containsArg(string key);

  void printArgs();
  
  VarMapP getArguments();

  void parseExtensionsVector();

  void printExtensions();

	vector<string> getArgs();	

 private:
  vector<string> args;
  vector<vector<string>> extensions;
  VarMapP arguments;
  string instanceFile;
  string outputFile;

};
#endif
