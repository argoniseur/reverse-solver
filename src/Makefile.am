AM_CPPFLAGS = -g -std=c++11 -Wall -Wno-parentheses -Werror -I$(srcdir)/specs -I$(srcdir)/parser -I$(smaxIncludeDirectory)

## Register new classes here
specsDirSources = ./specs/VarMapP.cc ./specs/Attacks.cc
parserDirSources = ./parser/AspartixFormatParser.cc ./parser/CNFFormatParser.cc ./parser/TrivialGraphFormatParser.cc
srcDirSources = ./Main.cc
smaxLibDirectory = ../resources/smax-master/lib
smaxIncludeDirectory = ../resources/smax-master/include

bin_PROGRAMS = ReverseSolver
ReverseSolver_SOURCES = $(srcDirSources) $(specsDirSources) $(parserDirSources)
#CoQuiAAS_LDFLAGS =-lpthread
ReverseSolver_LDFLAGS = -L$(smaxLibDirectory) -lsmax -lz -lgmp -O0
