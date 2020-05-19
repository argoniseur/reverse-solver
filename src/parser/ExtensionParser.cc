#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include "ExtensionParser.h"

ExtensionParser::ExtensionParser(string inputFile){
	instanceFile = inputFile;
}

void ExtensionParser::parseInstance(){

  	ifstream file(instanceFile,ios::in);
    string line ;
    int end = 0;
    unsigned long commaIndex;

    // Reading the args
    while(getline(file,line)){
    	// If the line isn't empty

      	if(!line.empty()){
			if((line.find("[\n") == 0)){
	  			//Start of file
	  		}
	  		if((line.find("[]") == 0)){
	  			cout << "pas d'extension" << endl;
	  		} else if((line.find("[") == 0)){
	  			//We remove the [
	  			line = line.substr(1);
	  			end = 0;

	  			// We read the line comma by comma
	  			while(end == 0){
	  				commaIndex = line.find(",");
	  				if(commaIndex != string::npos){
	  					string tmp = line.substr(0, commaIndex);
	  					line = line.substr(commaIndex+1);
	  					if(!containsArg(tmp)){

	  						args.push_back(tmp);
	  					}
	  				}else{
	  					commaIndex = line.find("]");
	  					string tmp = line.substr(0, commaIndex);
	  					end = 1;
	  					if(!containsArg(tmp)){
	  						args.push_back(tmp);
	  					}
	  				}
	  			}
	  		}else if((line.find("]\n") == 0)){
	  			cout << "fichier fini" << endl;
	  		}
  		}
  	}
  	if(args.size() > 0){
  		args.erase (args.begin());
  		parseArgsToAccepted();
  	}
  	file.close();
}

void ExtensionParser::parseArgsToAccepted(){
	for (int i = 0; (unsigned int)i < args.size(); i++) {
		acceptedArgs.addEntry(args.at(i));
		cout << acceptedArgs.getName(i) << endl;
	}
}

int ExtensionParser::containsArg(string key){
	if (std::find(args.begin(), args.end(), key) != args.end())
		return 1;
	else
		return 0;
}

void ExtensionParser::printArgs(){
	for (int i = 0; (unsigned int)i < args.size(); i++) {
		cout << args.at(i) << ' ';
	}
	cout << endl;
}