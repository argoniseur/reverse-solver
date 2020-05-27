#ifndef __QDIMACS_PARSER__
#define __QDIMACS_PARSER__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "VarMapP.h"
#include "VarMapAtt.h"
using namespace std;

class QdimacsParser {

 public:
  QdimacsParser();

  void parseToFile(vector<vector<int>> CNF, int args);

  void parseFromFile();
  
  string getFile();
  
 private:
  string temporary;
};
#endif
