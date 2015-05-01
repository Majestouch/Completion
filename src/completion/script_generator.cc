#include "script_generator.h"
#include<string>


using std::string;
using std::ofstream;

namespace clidoc{

ScriptGenerator::ScriptGenerator(const AstInfo& ai)
{
	this->ai = ai;
}

std::string ScriptGenerator::GenerateScript()
{
	std::string filename = this->ai.util_name_+"_script.sh";
	if(this->ofs.is_open())
		ofs.close();
	this->ofs.open(filename, std::ofstream::out);
	ofs<<
	"_"+this->ai.util_name_+"()\n"
	"{\n"
	"	local cur\n"
	"	cur=\"${COMP_WORDS[COMP_CWORD]}\"\n"

	"	if [ ${COMP_CWORD} -ge 1 ]; then\n"
		"		COMPREPLY=( $( compgen -W \'"+this->ai.words_list_+"\' -- ${cur}) )\n"
	
	"	fi\n"
	"}\n"
	"complete -F _"+this->ai.util_name_+" "+this->ai.util_name_;
	ofs.close();
	return filename;
}

}
