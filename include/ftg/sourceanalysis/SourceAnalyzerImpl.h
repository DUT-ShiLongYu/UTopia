#ifndef FTG_SOURCEANALYSIS_SOURCEANALYZERIMPL_H
#define FTG_SOURCEANALYSIS_SOURCEANALYZERIMPL_H

#include "ftg/sourceanalysis/SourceAnalysisReport.h"
#include "ftg/sourceanalysis/SourceAnalyzer.h"
#include "ftg/sourceloader/SourceCollection.h"

namespace ftg {
//SourceAnalyzerImpl 通过分析抽象语法树 (AST)，提取出与源代码结构相关的各种信息，生成一个详细的分析报告。这些信息包括源代码中的 main 函数位置、文件的结束偏移量、以及包含的头文件等。

class SourceAnalyzerImpl : public SourceAnalyzer {
public:
  SourceAnalyzerImpl(const SourceCollection &SC);
  std::unique_ptr<AnalyzerReport> getReport() override;
  const SourceAnalysisReport &getActualReport() const;

private:
  SourceAnalysisReport Report;
  unsigned getEndOffset(const clang::ASTUnit &U) const;
  std::vector<std::string> getIncludes(const clang::ASTUnit &U) const;
  const clang::FunctionDecl *getMainFuncDecl(const clang::ASTUnit &U) const;
};

} // namespace ftg

#endif // FTG_SOURCEANALYSIS_SOURCEANALYZERIMPL_H
