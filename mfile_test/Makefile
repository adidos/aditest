#get the current directory
CUR_DIR=$(shell pwd)

#object file ,out file directory
OUT_DIR=$(CUR_DIR)/bin
#check if the out dirctory exist, if not create it
CHECK_OUT_DIR:=$(shell if [ ! -d $(OUT_DIR) ] ;then mkdir $(OUT_DIR); fi)

#the pragram out file
OUT_FILE=test

#include path, library path, used library
FLAG_INC_PATH=-I./include
FLAG_LIB_PATH=-L./
FLAG_LIB=


FLAG_COMPILE=-c -g
FLAG_LINK=
#if out file is library
#FLAG_COMPILE=$(FLAG_COMPILE) -fPIC
#FLAG_LINK=$(FLAG_LINK) -fPIC -shared

VPATH=src
vpath %.cpp $(CUR_DIR)/src
vpath %.h $(CUR_DIR)/include

CPPFILES:=$(notdir $(wildcard $(CUR_DIR)/src/*.cpp))
OBJECTS:=$(patsubst %.cpp,%.o, $(CPPFILES))

all:$(OUT_FILE)
$(OUT_FILE):$(OBJECTS)
	$(CXX) $(FLAG_LINK) -o $(OUT_DIR)/$@ $(addprefix $(OUT_DIR)/,$(notdir $^)) $(FLAG_LIB_PATH) $(FLAG_LIB)

%.o:%.cpp
	$(CXX) $(FLAG_COMPILE) $< -o $(OUT_DIR)/$@ $(FLAG_INC_PATH)

.PHONY:clean
clean:
	rm -rf $(OUT_DIR)/*
