#ifndef _CMDLINE_H_
#define _CMDLINE_H_

struct CmdLine
{
  CmdLine();
  std::string m_cppPath;
  std::string m_cppOptions;
  int m_saveTemps;
  int m_noDslotWarn;
  int m_disableWarnings;
  bool m_explicitObjectFileSpecified;
  const char *m_objectFileName;
  int m_errorLimit;
  bool m_errorLimit_set;
  bool m_dumpCfg;
  int m_errors;
};

extern CmdLine aloCmdLine;

int cmdline_process_all_options(int argc, char *argv[]);

#endif
