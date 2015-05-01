#ifndef SRC_COMPLETION_SCRIPT_GENERATOR_H_
#define SRC_COMPLETION_SCRIPT_GENERATOR_H_

#include<string>
#include<fstream>

#include "ast_analyser.h"

using std::string;
using std::ofstream;

namespace clidoc{

class ScriptGenerator{
public:
	ScriptGenerator(const AstInfo& ai);

	std::string GenerateScript();

	~ScriptGenerator()
	{
		if(!ofs.is_open())
			ofs.close();
	}

private:
	AstInfo ai;
	std::ofstream ofs;
};

}


#endif
