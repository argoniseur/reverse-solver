#include "AspartixParser.h"

AspartixParser::AspartixParser(string outputFile, vector<string> args, vector<int> attModel){
	this->outputFile = outputFile;
	this->args = args;
	this->attModel = attModel;
}

void AspartixParser::parseFile(VarMapAtt attmap){
	ofstream file(outputFile, ios::out);
	unsigned long underscoreIndex;
	for(unsigned int i=0;i<args.size();i++){
		file << "arg(" + args[i] + ")." << endl;
	}

	for(unsigned int i=0;i<attModel.size();i++){
		string currentAtt = attmap.getName(attModel[i]);
		underscoreIndex = currentAtt.find("_");
		currentAtt = currentAtt.substr(underscoreIndex+1);
		underscoreIndex = currentAtt.find("_");
		string firstArg = currentAtt.substr(0,underscoreIndex);
		string secondArg = currentAtt.substr(underscoreIndex+1);
		file << "att(" << firstArg << "," << secondArg << ")." << endl;
	}
}