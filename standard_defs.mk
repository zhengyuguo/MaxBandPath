PACKAGE:=CSCE629_Project
INCLUDES:=-I$(abspath $(find_upwards include))
SRC_DIR:=$(find_upwards src)
#LDLIBS:=-lgtest -lrt
CXXFLAGS:=-std=c++11
PKG_LIBS:=-lstdc++ -lrt
