# Top-level ALO Makefile.  

export CC     := gcc3 
export CXX    := g++3
export LD     := g++3
export AR     := ar
export YACC   := bison
export LEX    := flex
export RANLIB := ranlib

CXXFLAGS := -g -Wall -Wno-missing-braces -MD -I. -I./octave -I./octave/m470 -I./octave/m480 -I../include -I../include/boost_1_30_0
CXXINCLUDES := -I../include -I../include/boost_1_30_0 -I../lang  -I../llir  -I../llir/octave/  -I../llir/octave/m470


# MRBUILD is defined for MAKER_ROOT builds.  If set, link statically and strip.
ifdef MRBUILD
LDEXTRA = -static
STRIP=strip
else
LDEXTRA =
STRIP=echo 'Done building'
endif

ifdef GCCBUILD
CXXFLAGS += -DGCCBUILD=1
endif

TEMP := $(shell env > /tmp/env.txt)

ALO_SRCS := AloErrorWarningVisitor.cpp  AloException.cpp main.cpp cmdline.cpp
ifeq ($(MAKER_CHIP), cx27470)
ALO_SRCS += CreateM470Alo.cpp  
else
ifeq ($(MAKER_CHIP), m27480)
ALO_SRCS +=CreateM480Alo.cpp 
else
$(shell echo "*** Error: You must define MAKER_CHIP" > /dev/tty)
stop
endif
endif

OBJ_DIR := $(MAKER_SYSTYPE)-$(MAKER_CHIP)
TEMP := $(shell test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR))

ALO_OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(ALO_SRCS))
ALO_OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(ALO_OBJS))
ALO_DEPS := $(ALO_OBJS:%.o=%.d)

# See comments in llir/Makefile regarding the echo_objs targets.
OCTAVE_OBJS := $(shell cd octave && make --no-print-directory echo_objs | sed 's,\.\./,,g' )
LANG_OBJS := $(shell cd lang && make --no-print-directory echo_objs | sed 's,\.\./,,g' )
LLIR_OBJS :=  $(shell cd ../llir && make --no-print-directory echo_objs | sed 's,[^ ]*[ ]*,../llir/&,g')

FLEX_LIBS :=  -L/usr/local/lib -lfl
LIBS := ../llir/$(MAKER_SYSTYPE)-$(MAKER_CHIP)/LlirOctave.a $(FLEX_LIBS)
LLIR_LIB := ../llir/$(MAKER_SYSTYPE)-$(MAKER_CHIP)/LlirOctave.a 


# build alo executable by default
all: llir_make octave_make lang_make $(OBJ_DIR)/alo

# rule to be called from gcc build
gcc-all: llir_make octave_make lang_make $(OBJ_DIR)/alo_fe.a

$(OBJ_DIR)/alo: $(LANG_OBJS) $(OCTAVE_OBJS) $(ALO_OBJS) $(LLIR_LIB)
	$(LD) -o $@ $(LANG_OBJS) $(OCTAVE_OBJS) $(ALO_OBJS) $(LIBS) $(LDEXTRA)
	$(STRIP) $@

# alo_fe.a contains *both* LANG and LLIR object files.
$(OBJ_DIR)/alo_fe.a: $(LANG_OBJS) $(OCTAVE_OBJS) $(ALO_OBJS) $(LLIR_OBJS)
	$(AR) rvu $@ $(LANG_OBJS) $(OCTAVE_OBJS) $(ALO_OBJS) $(LLIR_OBJS)
	ranlib $@


ifdef MRBUILD
install: all
	cp -p $(OBJ_DIR)/alo $(MAKER_ROOT)/$(MAKER_REV)/$(MAKER_SYSTYPE)/$(MAKER_CHIP)-elf/bin/alo
endif


###########################
# build alo specific stuff
###########################

$(OBJ_DIR)/%.o : %.cpp 
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

$(OBJ_DIR)/%.o : %.c
	$(CC) -c $(CXXFLAGS) $(CXXINCLUDES) -o $@ $<

octave_make :
	cd octave && $(MAKE) 

lang_make :
	cd lang && $(MAKE)

llir_make :
	cd ../llir && $(MAKE)

.PHONY : clean
clean: octave_clean lang_clean llir_clean
	- rm -f $(ALO_OBJS) $(ALO_DEPS)

octave_clean:
	cd octave && $(MAKE) clean

lang_clean:
	cd lang && $(MAKE) clean

llir_clean:
	cd ../llir && make clean

.PHONY : gcc-clean
gcc-clean:
	- rm -f $(MAKER_SYSTYPE)-$(MAKER_CHIP)/M480Alo.o 
	- rm -f $(MAKER_SYSTYPE)-$(MAKER_CHIP)/cbridge.o 
	- rm -f $(MAKER_SYSTYPE)-$(MAKER_CHIP)/main.o
	- rm -f $(MAKER_SYSTYPE)-$(MAKER_CHIP)/alo_fe.a

-include $(ALO_DEPS)
