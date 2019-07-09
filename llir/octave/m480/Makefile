CXX    := g++3 
CXXFLAGS := -g -Wall -Wno-missing-braces -MD -I.. -I../.. -I../../../include -I../../../include/boost_1_30_0
OBJ_DIR := ../../$(MAKER_SYSTYPE)-$(MAKER_CHIP)

M480_SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))
M480_DEPS := $(OBJS:%.o=%.d)

all : $(OBJS) 

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

echo_objs:
	@echo $(OBJS)

.PHONY : clean
clean:
	- rm -f $(OBJS) $(M480_DEPS)

-include $(M480_DEPS)

