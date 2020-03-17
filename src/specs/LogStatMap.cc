#include "LogStatMap.h"


LogStatMap::LogStatMap(File *outFile){
  outfile = outFile;
}


void LogStatMap::setStat(string name, string value) {
  
  fprintf(outfile, "c %s : %s\n", name.c_str(), value.c_str());
}


void LogStatMap::setStat(string name, int value) {

  fprintf(outfile, "c %s : %d\n", name.c_str(), value);
}


void LogStatMap::setStat(string name, double value) {

  fprintf(outfile, "c %s : %.3f\n", name.c_str(), value);
}


void LogStatMap::incCounterStat(string name, int value) {
  // must NOT be used in this class
}


void LogStatMap::printStats(FILE *outputFile) {}

LogStatMap::~LogStatMap() {}
