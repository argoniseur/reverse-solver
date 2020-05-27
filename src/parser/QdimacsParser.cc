#include "QdimacsParser.h"

QdimacsParser::QdimacsParser(){
	temporary = "tmp.qdimacs";
}

void QdimacsParser::parseToFile(vector<vector<int>> CNF, int nargs, int max){
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

void QdimacsParser::parseFromFile(){

}

string QdimacsParser::getFile(){
	return temporary;
}