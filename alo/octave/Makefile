CXX    := g++3 
CXXFLAGS := -g -Wall -Wno-missing-braces -MD
CXXINCLUDES := -I.. -I../../include -I../../include/boost_1_30_0 -I../../lang  -I../../llir  -I../../llir/octave/
 
#Yuck.. Fixme...
#GCCINCLUDES := -DIN_GCC -DCROSS_COMPILE   -g -O2 -W -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wtraditional -pedantic -Wno-long-long  -DHAVE_CONFIG_H   -DIN_GCC -I../../../../../../cs-build/gcc -I../../../../../../cs-gcc-3-1-branch/gcc  -I../../../../../../cs-gcc-3-1-branch/gcc/config -I../../../../../../cs-gcc-3-1-branch/gcc/../include -I../../../../../../cs-gcc-3-1-branch/gcc/alo


OBJ_DIR := ../$(MAKER_SYSTYPE)-$(MAKER_CHIP)

#OCTAVE_SRCS := $(wildcard *.cpp)

OCTAVE_SRCS := OctaveAlo.cpp  OctaveDelaySlotAnalyzer.cpp  OctaveDriver.cpp  OctaveSemanticVisitor.cpp
ifdef GCCBUILD
OCTAVE_SRCS += OctaveBranchInsnVisitor.cpp OctaveGenRtlVisitor.cpp OctaveSequenceAnalyzer.cpp OctaveRtlPrintVisitor.cpp OctaveUpdateOpndVisitor.cpp
CXXINCLUDES += -I../../gcc/gcc/alo
endif


#OCTAVE_OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))

OCTAVE_OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(OCTAVE_SRCS))
OCTAVE_DEPS := $(OCTAVE_OBJS:%.o=%.d)


ifeq ($(MAKER_CHIP), cx27470)
all :  m470_make  $(OCTAVE_OBJS)
else
ifeq ($(MAKER_CHIP), m27480)
all :  m480_make  $(OCTAVE_OBJS)
else
$(shell echo "*** Error: You must define MAKER_CHIP" > /dev/tty)
stop
endif
endif


$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

m470_make :
	cd m470 && $(MAKE)

m480_make :
	cd m480 && $(MAKE)

echo_objs:
ifeq ($(MAKER_CHIP), cx27470)
	@echo $(OCTAVE_OBJS) $(shell cd m470 && make --no-print-directory echo_objs)
else
ifeq ($(MAKER_CHIP), m27480)
	@echo $(OCTAVE_OBJS) $(shell cd m480 && make --no-print-directory  echo_objs)
else
$(shell echo "*** Error: You must define MAKER_CHIP" > /dev/tty)
stop
endif
endif


.PHONY : clean
clean: m470_clean m480_clean
	- rm -rf $(OCTAVE_OBJS) $(OCTAVE_DEPS)

m470_clean :
	cd m470 && $(MAKE) clean

m480_clean :
	cd m480 && $(MAKE) clean

-include $(OCTAVE_DEPS)

