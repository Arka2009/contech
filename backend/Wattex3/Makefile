CC=gcc
CXX=g++
CXXFLAGS=-std=c++14
SRCDIR:=${PWD}
OBJDIR:=${PWD}/build
SOURCES:=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS:=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
LDFLAGS:=-L../../common/taskLib/ \
         -L../CommTracker \
		 -L/home/amaity/Desktop/ecotools/build/
LIBS:=-lTask  -lCommTracker -lz -lecotools
RLIBSPATH:=-Wl,-rpath=$(CONTECH_HOME)/common/taskLib/
EXE:=wattex3

$(EXE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $(EXE) $(LIBS) $(RLIBSPATH)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp MKDIR_P
	$(CXX) $(CXXFLAGS) -c $< -o $@

MKDIR_P :
	mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJDIR) $(EXE)