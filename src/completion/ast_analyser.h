#ifndef SRC_COMPLETION_AST_ANALYSER_H_
#define SRC_COMPLETION_AST_ANALYSER_H_

#include <string>

#include "ast/ast_build.h"

using std::string;

namespace clidoc{

struct AstInfo{
std::string util_name_;
std::string words_list_;
};

class AstAnalyser{
 public:
  AstAnalyser(const CodeGenInfo& cgi);
  AstInfo GetAstInfo();

  std::string ExtractUtilityName(std::string doc_text);
  std::string OmitTheFirstLine(std::string str);
  std::string ExtractTheFirstNotEmptyLine(std::string str);
  std::string ExtractTheFirstString(std::string str);

  std::string ExtractWordsList(const CodeGenInfo& cgi);
  std::string trim(std::string str);
 private:
  AstInfo ai;
};

}
#endif
