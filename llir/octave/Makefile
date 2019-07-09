CXX    := g++3 
CXXFLAGS := -g -Wall -Wno-missing-braces -MD -I. -I..  -I./m470 -I./m480 -I../../include -I../../include/boost_1_30_0

OBJ_DIR := ../$(MAKER_SYSTYPE)-$(MAKER_CHIP)

OCTAVE_SRCS := $(wildcard *.cpp)
OCTAVE_OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))

all :  m470_make  m480_make  $(OCTAVE_OBJS)

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

echo_objs:
	@echo $(OCTAVE_OBJS) $(shell cd m470 && make --no-print-directory echo_objs) $(shell cd m480 && make --no-print-directory echo_objs)


OCTAVE_DEPS := $(OCTAVE_OBJS:%.o=%.d)
-include $(OCTAVE_DEPS)

m470_make :
	cd m470 && $(MAKE)

m480_make :
	cd m480 && $(MAKE)

.PHONY : clean
clean: m470_clean m480_clean
	- rm -rf $(OCTAVE_OBJS) $(OCTAVE_DEPS)

m470_clean:
	cd m470 && $(MAKE) clean

m480_clean:
	cd m480 && $(MAKE) clean

