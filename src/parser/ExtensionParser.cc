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
    vector<string> stringAcc;
    int i = 0;
    extensions.clear();
    // Reading the args
    while(getline(file,line)){
    	// If the line isn't empty

      	if(!line.empty()){
			if((line.back() == '[')){
	  			//Start of file
	  			cout << "debut de fichier" << endl;
	  		}else if((line.find("[]") == 0)){
	  			cout << "pas d'extension" << endl;
	  		} else if((line.find("[") == 0)){
	  			//We remove the [
	  			line = line.substr(1);
	  			end = 0;
	  			
	  			stringAcc.clear();
	  			// We read the line comma by comma
	  			while(end == 0){
	  				commaIndex = line.find(",");
	  				if(commaIndex != string::npos){
	  					string tmp = line.substr(0, commaIndex);
	  					line = line.substr(commaIndex+1);
	  					//tmp is our arg
	  					stringAcc.push_back(tmp);
	  					if(!containsArg(tmp)){
	  						arguments.addEntry(tmp);
	  						args.push_back(tmp);
	  					}
	  				}else{
	  					commaIndex = line.find("]");
	  					string tmp = line.substr(0, commaIndex);
	  					end = 1;
	  					stringAcc.push_back(tmp);
	  					//tmp isour arg
	  					if(!containsArg(tmp)){
	  						arguments.addEntry(tmp);
	  						args.push_back(tmp);
	  					}
	  				}
	  			}
	  			extensions.push_back(stringAcc);
	  			i++;
	  		}else if((line.find("]\n") == 0)){
	  			cout << "fichier fini" << endl;
	  		}
  		}
  	}
  	parseExtensionsVector();
  	file.close();
}

void ExtensionParser::parseExtensionsVector(){
	for(unsigned int i=0;i<extensions.size();i++){
		vector<int> n(extensions[i].size());
		for(unsigned int j=0;j<extensions[i].size();j++){
			n[j] = arguments.getVar(extensions[i][j]);
		}
		
		arguments.addExtension(n);
	}
}

VarMapP ExtensionParser::getArguments(){
	return arguments;
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

void ExtensionParser::printExtensions(){
	for (int i = 0; (unsigned int)i < extensions.size(); i++) {
		for(unsigned int j=0;j<extensions[i].size();j++){
			cout << extensions[i][j] << ' ';
		}
		cout << endl;	
	}
}