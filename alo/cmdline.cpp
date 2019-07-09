/*
 * Command-line options.  This must be usable in both "plain" ALO
 * and GCC builds, so at one interface function has "C" linkage.
 */

#include <cstdio>
#include <string>
#include "cmdline.h"
#include "aloversion.h"

using namespace std;

CmdLine::CmdLine() : 
  m_cppPath(""),
  m_cppOptions(""),
  m_saveTemps(0),
  m_noDslotWarn(0),
  m_disableWarnings(0),
  m_explicitObjectFileSpecified(false),
  m_objectFileName(""),
  m_errorLimit(0),
  m_errorLimit_set(false),
  m_dumpCfg(false),
  m_errors(0)
{
}

CmdLine aloCmdLine;		// Global instance.

extern int alo_debug;		// We are using -palo_ option with bison, so all "yy*"
                                // variables are renamed.

static void alo_option_display_usage(const char *optarg_unused);

#if 0
char *object_file_name;
#endif

static void alo_option_yydebug(const char *optarg_unused)
{
  alo_debug = 1;
}

static void alo_option_error_limit(const char *optarg)
{
  aloCmdLine.m_errorLimit = atoi(optarg);
  aloCmdLine.m_errorLimit_set = true;
}

static void alo_option_object_file_name(const char *optarg)
{
  aloCmdLine.m_objectFileName = optarg;
  aloCmdLine.m_explicitObjectFileSpecified = true;
}

static void alo_option_save_temps(const char *optarg_unused)
{
  aloCmdLine.m_saveTemps = true;
}

static void alo_option_cpp_path(const char *optarg)
{
  aloCmdLine.m_cppPath = optarg;
}

static void alo_option_I(const char *optarg)
{
  aloCmdLine.m_cppOptions += string(" -I ") + optarg;
}

static void alo_option_D(const char *optarg)
{
  aloCmdLine.m_cppOptions += string(" -D ") + optarg;
}

static void alo_option_no_dslot_warn(const char *optarg)
{
  aloCmdLine.m_noDslotWarn = 1;
}

static void alo_option_show_version(const char *optarg_unused)
{
  fprintf(stderr, "ALO Version " ALO_VERSION "\n");
}

static void alo_dump_cfg_info(const char *optarg_unused)
{
  aloCmdLine.m_dumpCfg = true;
}


struct option 
{
  const char *str;
  const char *help;
  int takes_argument;
  const char *argstr;
  void (*func)(const char *arg);
};


// Command-line options.
// "--output" is required because cc1alo has its own interpretation of "-o"
// FIXME: I can't find an easy way to get at this from cc1alo for "--help"
// purposes.  The way that code works is to include lang-specs.h .
static struct option alo_options[] = 
{
  {"--yydebug",           "Turn on verbose parser debugging to stderr", 0, NULL, alo_option_yydebug},
  {"-e",                  "Limit number of errors", 1, "<n>", alo_option_error_limit},
  {"-o",                  "Set output filename", 1, "<filename>", alo_option_object_file_name},
  {"--output",            "Set output filename", 1, "<filename>", alo_option_object_file_name},
  {"-t",                  "Save intermediate assembly files", 0, NULL, alo_option_save_temps},
  {"--save-temps",        "Save intermediate assembly files", 0, NULL, alo_option_save_temps},
  {"--cpp_path",          "Define CPP path", 1, "<path>", alo_option_cpp_path},
  {"-I",                  "Add include path", 1, "<path>", alo_option_I},
  {"-D",                  "Define variable",  1, "<string>", alo_option_D},
  {"-h",                  "Display this help", 0, NULL, alo_option_display_usage},
  {"--help",              "Display this help", 0, NULL, alo_option_display_usage},
  {"--dump-cfg",          "Dump CFG per function", 0, NULL, alo_dump_cfg_info},
  {"-Wno-dslot-warn",     "Do not show invalid delay slot warnings", 0, NULL, alo_option_no_dslot_warn},
  {"--version",           "Show program version", 0, NULL, alo_option_show_version},
//    {"-W",              "", 0, NULL},
//    {"-v",              "", 0, NULL},
  // Table is terminated by a NULL string field.
  {NULL,              NULL, 0, NULL},
};

static void alo_option_display_usage(const char *optarg_unused)
{
  option *opt;

  fprintf(stderr, "Usage: alo [options] file.s\n\n");
  fprintf(stderr, "Options:\n");
  for (opt = alo_options; opt->str != NULL; opt++)
    {
      if (opt->takes_argument)
	fprintf(stderr, "  %-18s %s", opt->str, opt->argstr);
      else
	fprintf(stderr, "  %-18s", opt->str);
      fprintf(stderr, " %s\n", opt->help);
    }
}


/* This must be callable from the GCC infrastructure.  Look for alo-lang.c .
   Return number of arguments consumed. */
extern "C" int cmdline_process_one_option(int argc, char *argv[])
{
  option *opt;
  int consumed = 0;

  for (opt = alo_options; opt->str != NULL; opt++)
    {
      if (!strcmp(opt->str, argv[0]))
	{
	  consumed++;
	  if (opt->takes_argument)
	    {
	      if (argv[1] == NULL)
		{
		  // Oops! Need an argument!
		  fprintf(stderr, "option %s requires an argument (FIXME: this should stop compilation)\n", opt->str);
		      // What to do here?  ALO build can check m_errors.  Actually, that should be sufficient!
		  ++aloCmdLine.m_errors;
		}
	      else
		{
		  opt->func(argv[1]);
		  consumed++;
		}
	    }
	  else
	    {
	      opt->func(NULL);
	    }
	  break;
	}
      else if (!strncmp(opt->str, argv[0], strlen(opt->str))
	       && argv[0][2]
	       && opt->takes_argument
	       && opt->str[1] != '-')
	{
	  // Single-dash option, with no space between it and its argument.
	  // Pass argument part to function, and consume just one argument.
	  opt->func(argv[0]+2);
	  consumed++;
	  break;
	}
    }

  return consumed;
}

// This is only used in the non-GCC build, but calls the
// same code above.
int cmdline_process_all_options(int argc, char *argv[])
{
  int n;
  int i;

  // If there are no arguments, just return argc.
  if (argc == 1)
    {
      return 1;
    }

  i = 1;
  do
    {
      n = cmdline_process_one_option(argc-i, argv+i);
      i += n;
    }
  while ((i < argc) && n);

  return i;
}
