export CC     := gcc3 
export CXX    := g++3
export LD     := g++3
export AR     := ar
export YACC   := bison
export LEX    := flex
export RANLIB := ranlib

CXXFLAGS := -g -Wall -Wno-missing-braces -MD -I. -I./octave -I./octave/m470 -I./octave/m480 -I../include -I../include/boost_1_30_0

OBJ_DIR := $(MAKER_SYSTYPE)-$(MAKER_CHIP)
TEMP := $(shell test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR))

LLIR_SRCS := $(wildcard L*.cpp)
LLIR_OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(LLIR_SRCS))


all: octave_make $(OBJ_DIR)/LlirOctave.a

# This shell statement here makes the "echo_objs" targets in octave/ and below which
# simply print out the names of the ".o" files that the Makefiles there produce.  
# "--no-print-directory" is required, otherwise make will set MAKEFLAGS=w which
# produces 'Entering.../Leaving' messages which seriously confuse the shell evaluation.
#
# The alternative to this is to have, in this file, a redundant (yecch) listing of
# octave/*.cpp and  octave/m4?0/*.cpp, and recalculate the .o names.
LLIR_OCTAVE_OBJS := $(shell cd octave && make --no-print-directory echo_objs | sed 's,\.\./,,g')


###########################
# build llir specific stuff
###########################

$(OBJ_DIR)/LlirOctave.a: $(LLIR_OBJS) $(LLIR_OCTAVE_OBJS)
#	echo $(LLIR_OBJS)
	rm -f $@
	$(AR) rvu $@ $(LLIR_OBJS) $(LLIR_OCTAVE_OBJS)
	ranlib $@

$(OBJ_DIR)/%.o : %.cpp 
	$(CXX) -c $(CXXFLAGS) -o $@ $<

echo_objs:
	@echo $(LLIR_OBJS) $(LLIR_OCTAVE_OBJS) 

octave_make :
	cd octave && $(MAKE)

LLIR_DEPS := $(LLIR_OBJS:%.o=%.d)


#################################
# link  with LlirOctave.a
#################################

#alo_test: main.o LlirOctave.a
#	$(LD) $(CXXFLAGS) -o $@ main.o LlirOctave.a 

.PHONY : tags
tags:
#	generate tags with tags in the header files first
	find . -name "*.h" -print | etags --c++ -o LlirTAGS -
	find . -name "*.cpp" -print | etags --c++ --append -o LlirTAGS -

.PHONY : clean
clean: octave_clean
	- rm -f $(LLIR_OBJS) $(LLIR_DEPS)

octave_clean:
	cd octave && $(MAKE) clean

-include $(LLIR_DEPS)

