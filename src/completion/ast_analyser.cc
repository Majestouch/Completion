#include<string>

#include "ast/ast_node_interface.h"
#include "ast_analyser.h"


namespace clidoc{

AstAnalyser::AstAnalyser(const CodeGenInfo& cgi){
	this->ai.util_name_ = ExtractUtilityName(cgi.doc_text_);
	this->ai.words_list_ = ExtractWordsList(cgi);
}

AstInfo AstAnalyser::GetAstInfo(){
	return this->ai;
}

std::string AstAnalyser::ExtractUtilityName(std::string doc_text){
	std::string str = doc_text;
	//
	str = OmitTheFirstLine(str);
	//
	str = ExtractTheFirstNotEmptyLine(str);
	// 
	str = ExtractTheFirstString(str);
	return str;
}

std::string AstAnalyser::OmitTheFirstLine(std::string str){
	std::string tmp;
	unsigned int i=0;
	for(i=0;i<str.size();i++)
	{
		if(str[i]!='\n')
			continue;
		else
			break;
	}
	tmp = str.substr(i+1);
	return tmp;
}

std::string AstAnalyser::ExtractTheFirstNotEmptyLine(std::string str){
	std::string tmp="";
	bool isEmpty = true;
	unsigned begin = 0, end = 0;
	for(begin=0,end=0;end<str.size();end++)
	{
		begin = end;
		for(;end<str.size();end++)
		{
			if(str[end]=='\n')
				break;
			if(str[end]!=' ')
				isEmpty = false;
		}
		if(isEmpty)
			continue;
		tmp = str.substr(begin,end-begin+1);
		break;
	}
	return tmp;
}

std::string AstAnalyser::ExtractTheFirstString(std::string str)
{
	unsigned int begin=0;
	for(begin=0;begin<str.size();begin++)
	{
		if(str[begin]!=' ')
			break;
	}
	unsigned int length=begin;
	for(;length<str.size();length++)
	{
		if(str[length]==' ')
			break;
	}
	length = length - begin;
	return str.substr(begin,length);
}

std::string AstAnalyser::ExtractWordsList(const CodeGenInfo& cgi){
	std::string words_list="";
	for(Token element:cgi.bound_options_)
	{
		words_list+=element.value()+" ";
	}

        for(Token element:cgi.unbound_options_)
        {
                words_list+=element.value()+" ";
        }

        for(Token element:cgi.oom_bound_options_)
        {
                words_list+=element.value()+" ";
        }

        for(Token element:cgi.commands_)
        {
                words_list+=element.value()+" ";
        }

	words_list = trim(words_list);
	return words_list;
}

std::string AstAnalyser::trim(std::string str){
	if (str.empty())   
	{  
		return str;  
	}  
  
	str.erase(0,str.find_first_not_of(" "));  
	str.erase(str.find_last_not_of(" ") + 1);  
	return str;
}

}
