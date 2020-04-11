AM_CPPFLAGS = -g -std=c++11 -Wall -Wno-parentheses -Werror -I$(srcdir)/specs -I$(srcdir)/parser -I$(smaxIncludeDirectory) -I$(srcdir)/solver

## Register new classes here
specsDirSources = ./specs/VarMapP.cc ./specs/Attacks.cc ./specs/Accepted.cc ./specs/Defeated.cc ./specs/VarMapAtt.cc ./specs/VarMapDet.cc
parserDirSources = ./parser/AspartixFormatParser.cc ./parser/CNFFormatParser.cc ./parser/TrivialGraphFormatParser.cc
solverDirSources = ./solver/compute_formula_stable.cc
srcDirSources = ./Main.cc
smaxLibDirectory = ../resources/smax/lib
smaxIncludeDirectory = ../resources/smax/include

bin_PROGRAMS = ReverseSolver
ReverseSolver_SOURCES = $(srcDirSources) $(specsDirSources) $(parserDirSources) $(solverDirSources)
#CoQuiAAS_LDFLAGS =-lpthread
ReverseSolver_LDFLAGS = -L$(smaxLibDirectory) -lsmax -lz -lgmp -O0
ReverseSolver_LDADD = $(smaxLibDirectory)/libsmax.so
