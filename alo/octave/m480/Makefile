CXX    := g++3 
CXXFLAGS := -g -Wall -Wno-missing-braces -MD 
CXXINCLUDES := -I.. -I../.. -I../../../include -I../../../include/boost_1_30_0 -I../../../lang  -I../../../llir  -I../../../llir/octave/  -I../../../llir/octave/m480

OBJ_DIR := ../../$(MAKER_SYSTYPE)-$(MAKER_CHIP)

#M480_SRCS := $(wildcard *.cpp)
#OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))
#M480_DEPS := $(OBJS:%.o=%.d)

M480_SRCS := BranchVisitor.cpp M480Alo.cpp  M480Driver.cpp  M480SemanticVisitor.cpp 

ifdef GCCBUILD
CXXFLAGS += -DGCCBUILD=1
M480_SRCS += M480BranchInsnVisitor.cpp M480GenRtlVisitor.cpp M480RtlPrintVisitor.cpp FindBranchLabelVisitor.cpp M480UpdateOpndVisitor.cpp
CXXINCLUDES += -I../../../gcc/gcc/alo -I../../../i386-linux-build/gcc
endif

OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(M480_SRCS))
M480_DEPS := $(OBJS:%.o=%.d)

all : $(OBJS) 

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

echo_objs:
	@echo $(OBJS)

.PHONY : clean
clean:
	- rm -f  $(OBJS) $(M480_DEPS)

-include $(M480_DEPS)

