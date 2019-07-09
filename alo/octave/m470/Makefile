CXX    := g++3 
CXXFLAGS := -g -Wall -Wno-missing-braces -MD 
CXXINCLUDES := -I.. -I../.. -I../../../include -I../../../include/boost_1_30_0 -I../../../lang  -I../../../llir  -I../../../llir/octave/  -I../../../llir/octave/m470

OBJ_DIR := ../../$(MAKER_SYSTYPE)-$(MAKER_CHIP)

M470_SRCS := M470Alo.cpp  M470Driver.cpp  M470SemanticVisitor.cpp
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(M470_SRCS))
M470_DEPS := $(OBJS:%.o=%.d)

all : $(OBJS) 

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

echo_objs:
	@echo $(OBJS)

.PHONY : clean
clean:
	- rm -f $(OBJS) $(M470_DEPS)

-include $(M470_DEPS)
