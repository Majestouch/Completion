#ifndef	SRC_COMPLETION_SCRIPT_MANAGER_H_ 
#define SRC_COMPLETION_SCRIPT_MANAGER_H_ 

#include<string>

using std::string;

namespace clidoc{
class ScriptManager{
public:
	ScriptManager(const std::string& script_name_);
	ScriptManager(const std::string& script_name_,const std::string& script_path_);
	ScriptManager();
	
	void InstallScript(); 

private:
	void CopyScript();
	bool IsExist(const std::string& filename);
	std::string script_name_;
	std::string script_path_;
};
}
#endif
