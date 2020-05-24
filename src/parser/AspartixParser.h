#ifndef __ASPARTIX_PARSER__
#define __ASPARTIX_PARSER__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "VarMapP.h"
#include "VarMapAtt.h"
using namespace std;

class AspartixParser {

 public:
  AspartixParser(string outputFile, vector<string> args, vector<int> attModel);

  void parseFile(VarMapAtt attmap);
  
 private:
  vector<int> attModel;
  string outputFile;
  vector<string> args;
};
#endif
