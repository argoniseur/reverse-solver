#ifndef __COMMAND_LINE_HELPER_H__
#define __COMMAND_LINE_HELPER_H__

#include <iostream>
#include <vector>
#include <map>


using namespace std;

/** 
 * \class CommandLineHelper
 * \brief Class used to parse the command line variables provided to the main function
 */
class CommandLineHelper {

 public:
  /**
   * \fn CommandLineHelper
   * \brief Constructor
   * \param argc : the number of program's arguments passed in main function
   * \param argv : the program's arguments passed in main function
   */
  CommandLineHelper(int argc, char** argv);

  /**
   * \fn parseCommandLine
   * \brief Constructor
   */  
  void parseCommandLine();

  string getInstanceFile();
  
  string getOutputFile();
  
  int getK();
  
 private:
  vector<string> args;
  bool mustExit;
  //  bool errorOccured;
  string instanceFile;
  string outputFile;
  map<string,string> additionalParams;
  int k;
};
#endif
