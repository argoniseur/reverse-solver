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
  QdimacsParser(int nargs);

  void parseToFile(vector<vector<int>> CNF, int max);

  vector<int> parseFromFile(string sortie);
  
  string getFile();

 private:
  string temporary;
  int nargs;
};
#endif
