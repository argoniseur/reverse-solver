#ifndef __ASPARTIX_PARSER__
#define __ASPARTIX_PARSER__


#include <iostream>
#include <string>

using namespace std;

class AspartixParser {
	public:
		AspartixParser(VarMapP vm);

		virtual ~AspartixParser();
		void parseInstance();

	private:
		VarMapP vm;
		string outputName;
}

#endif