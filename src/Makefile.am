AM_CPPFLAGS = -g -Wall -Wno-parentheses -Werror -I$(srcdir)/specs -I$(srcdir)/parser

## Register new classes here
specsDirSources = ./specs/VarMap.cc ./specs/Attacks.cc
parserDirSources = ./parser/AspartixFormatParser.cc ./parser/CNFFormatParser.cc ./parser/TrivialGraphFormatParser.cc
srcDirSources = ./Main.cc


bin_PROGRAMS = ReverseSolver
ReverseSolver_SOURCES = $(srcDirSources) $(specsDirSources) $(parserDirSources)
#CoQuiAAS_LDFLAGS =-lpthread
