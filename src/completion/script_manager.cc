#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "script_manager.h"

using std::string;
using std::ifstream;
using std::ofstream;

namespace clidoc{

ScriptManager::ScriptManager(const std::string& script_name_){
	this->script_name_ = script_name_;
	this->script_path_ = "/etc/bash_completion.d/"; 
}

ScriptManager::ScriptManager(const std::string& script_name_, const std::string& script_path_){
	this->script_name_ = script_name_;
	this->script_path_ = script_path_; 
	if(this->script_path_.back()!='/')
		this->script_path_+='/';
}


void ScriptManager::InstallScript(){
	//std::string str =  "sudo mv "+this->script_name_+" "+this->script_path_+"/";
	//const char* cmdmv = str.data();
	//std::system(cmdmv);
	std::string source_script = this->script_name_;
	std::string target_script = this->script_path_+this->script_name_;
	std::cout<<"target_script: "<<target_script<<std::endl;
	if(!IsExist(source_script))
	{
		std::cout<<"not found!"<<std::endl;
		throw("Script not found!");
	}
	if(IsExist(target_script))
	{	
		std::cout<<"target exist!"<<std::endl;
		throw("Target script has existed!");
	}
	ifstream fin(source_script,ifstream::binary|ifstream::in);
	ofstream fout(target_script, ofstream::binary|ofstream::out);
	fout<<fin.rdbuf();
	fout.close();
	fin.close();
	std::cout<<"Script copy finished!"<<std::endl;
}

bool ScriptManager::IsExist(const std::string& filename){
	ifstream ifs(filename);
	if(!ifs)
		return false;
	else{
		ifs.close();
		return true;
	}
}
}
