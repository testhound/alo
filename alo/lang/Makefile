#
# ALO top-level Makefile.
#

CXX  := g++3
LD   := g++3
YACC := bison
LEX  := flex

CXXFLAGS := -g -Wall -Wno-missing-braces -MD

ifdef GCCBUILD
CXXFLAGS += -DGCCBUILD=1
endif


OBJ_DIR := ../$(MAKER_SYSTYPE)-$(MAKER_CHIP)

LANG_INCLUDES := -I.. -I../octave -I../octave/m470 -I../octave/m480 -I../../llir -I../../llir/octave -I../../llir/octave/m470 -I../../llir/octave/m480 -I../../include/boost_1_30_0 -I../../include -I.

LANG_SRCS := alolang.tab.c alolang.yy.c alolang_keywords.c aloutil.cpp conditionals.cpp cbridge.cpp \
	defmacro.cpp defmacro_lang.tab.c

ifeq ($(MAKER_CHIP), cx27470)
CHIP_Y_FILE=m470.y.in
GPERF_FILE=m470.gperf
else
ifeq ($(MAKER_CHIP), m27480)
CHIP_Y_FILE=m480.y.in
GPERF_FILE=m480.gperf
LANG_SRCS += reg_alloc.cpp
# There are a few bits in alolang.y.in and aloutil.cpp that are hard to 
# separate out, so we make them conditional on OPTIMIZING_ALO.
CXXFLAGS += -DOPTIMIZING_ALO=1
endif
endif

LANG_OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(LANG_SRCS))
LANG_OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(LANG_OBJS))
LANG_DEPS := $(LANG_OBJS:%.o=%.d)


all: $(LANG_OBJS)

$(OBJ_DIR)/alolang.yy.c: alolang.l $(OBJ_DIR)/alolang.tab.c $(OBJ_DIR)/defmacro_lang.tab.c
	flex -o$@ -Palo_ $<

# Compile with -Wno-unused because yy_flex_realloc() is defined but not used.
$(OBJ_DIR)/alolang.yy.o: $(OBJ_DIR)/alolang.yy.c Makefile
	$(CXX) $(CXXFLAGS) -Wno-unused $(LANG_INCLUDES) -c -o $@ $<


$(OBJ_DIR)/alolang_keywords.c: $(GPERF_FILE) $(OBJ_DIR)/alolang.tab.h yystypes.h
# Have to remove the __inline, otherwise gcc discards in_word_set().
	gperf -t -D -L ANSI-C $(GPERF_FILE) | sed -e 's,^__inline,,g' > $(OBJ_DIR)/alolang_keywords.c

$(OBJ_DIR)/alolang_keywords.o: $(OBJ_DIR)/alolang_keywords.c
	$(CXX) $(LANG_INCLUDES) -fno-inline -O -c -o $@ $<

$(OBJ_DIR)/alolang.y: alolang.y.in $(CHIP_Y_FILE)
	if [ -f $@ ]; then chmod u+w $@; fi
	./ycombine.py $^ > $@
# Make this read-only as a hint that it shouldn't be edited directly.
	chmod a-w $@

$(OBJ_DIR)/alolang.tab.c $(OBJ_DIR)/alolang.tab.h: $(OBJ_DIR)/alolang.y yystypes.h Makefile
	$(YACC) -d -t -v -p alo_ $(OBJ_DIR)/alolang.y -o $@
	./clean_tab_h $(OBJ_DIR)/alolang.tab.h

$(OBJ_DIR)/alolang.tab.o: $(OBJ_DIR)/alolang.tab.c
	$(CXX) $(CXXFLAGS) $(LANG_INCLUDES) -c -o $@ $<

$(OBJ_DIR)/defmacro_lang.tab.c: defmacro_lang.y Makefile
	$(YACC) -p defmacro_ -d -t -v $< -o $@
	./clean_tab_h $(OBJ_DIR)/defmacro_lang.tab.h

$(OBJ_DIR)/defmacro_lang.tab.o: $(OBJ_DIR)/defmacro_lang.tab.c
	$(CXX) $(CXXFLAGS) $(LANG_INCLUDES) -c -o $@ $<

# This rule matches all .cpp files.
$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(LANG_INCLUDES) -c -o $@ $<

echo_objs:
	@echo $(LANG_OBJS)

clean:
	- rm -f $(OBJ_DIR)/$(LANG_OBJS) $(LANG_DEPS) $(OBJ_DIR)/*.output \
          $(OBJ_DIR)/*.yy.c $(OBJ_DIR)/*.tab.c $(OBJ_DIR)/alolang_keywords.c


# Include auto-generated dependencies
-include $(LANG_DEPS)
