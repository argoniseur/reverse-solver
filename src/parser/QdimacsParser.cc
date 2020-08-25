#include "QdimacsParser.h"

QdimacsParser::QdimacsParser(int nargs){
	temporary = "tmp.qdimacs";
	this->nargs = nargs;
}

void QdimacsParser::parseToFile(vector<vector<int>> CNF, int max){
	ofstream file(temporary, ios::out);
	file << "p cnf " << max << " " << CNF.size() << endl;
	file << "e ";
	for(int i=nargs+1;i<=nargs*nargs+nargs;i++){
		 file << i << " ";
	}
	file << "0" << endl;

	file << "a ";
	for(int i=1;i<=nargs;i++){
		 file << i << " ";
	}
	file << "0" << endl;
	file << "e ";
	for(int i=nargs*nargs+nargs+1;i<=max;i++){
		 file << i << " ";
	}
	file << "0" << endl;
	for(unsigned int i=0;i<CNF.size();i++){
		for(unsigned int j=0;j<CNF[i].size();j++){
			file << CNF[i][j] << " ";
		}
		file << "0" << endl;
	}
	file.close();
}

vector<int> QdimacsParser::parseFromFile(string sortie){
	ofstream file("tmp", ios::out);
	file << sortie << endl;
	file.close();

	unsigned long spaceIndex;
	unsigned long spaceIndex2;
	vector<int> ret;
	string line;
	ifstream file2("tmp", ios::in);
	while(getline(file2,line)){
    	// If the line isn't empty

      	if(!line.empty()){
			if((line.at(0) == 'c')){
				//ignore comment
			}else if((line.at(0) == 's')){
				char a = line[6];
				ret.push_back(a-48);
			}else if((line.at(0) == 'V')){
				spaceIndex = line.find(" ");
				string tmpline = line.substr(spaceIndex+1);
				spaceIndex2 = tmpline.find(" ");
				string number = tmpline.substr(0,spaceIndex2);
				
				int n = atoi(number.c_str());
				if(n > 0 && abs(n)>=nargs+1 && abs(n) <= nargs*nargs+nargs){
					ret.push_back(n);
				}
			}
		}
	}
	file2.close();
	remove("tmp");
	return ret;
}

string QdimacsParser::getFile(){
	return temporary;
}
