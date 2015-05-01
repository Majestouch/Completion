#include<iostream>
#include<fstream>
#include<string>
#include<streambuf>

#include "ast/ast_build.h"
#include "ast/ast_node_interface.h"
#include "ast_analyser.h"
#include "script_generator.h"
#include "script_manager.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::istreambuf_iterator;
using clidoc::Token;


int main()
{
	string input =
                "Usage:\n"
		"  example -abc"
                "  example --hello-world\n"
                "  example --output-file=<filename>\n"
                "  example -n <names>...\n";
	
        clidoc::CodeGenInfo info;
        info.Prepare(input);

	//Collect informaton from AST
	clidoc::AstAnalyser aa(info);
	clidoc::AstInfo ai = aa.GetAstInfo();
	//std::cout<<"name: "<<ai.util_name_<<std::endl;
	//std::cout<<"words_list: "<<ai.words_list_<<std::endl;
	
	//Generate script
	clidoc::ScriptGenerator sg(ai);
	std::string script_name_ = sg.GenerateScript();
	//std::cout<<"filename: "+script_name_<<std::endl;

	//Install Script. 
	//Administrator permission is required.
	clidoc::ScriptManager sm(script_name_);
	sm.InstallScript();
	return 0;
}
