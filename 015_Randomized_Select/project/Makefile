# http://citforum.ru/operating_systems/gnumake/index.shtml

CXX := g++
program_name := randomizedselect
source_dirs  := .
include_dirs :=
link_flags   := -static
source_dirs  := $(addprefix ../../src/, $(source_dirs) )
source_files := $(wildcard   $(addsuffix /*.cpp, $(source_dirs) ) )
object_files := $(notdir $(source_files) )
object_files := $(object_files:.cpp=.o)

$(program_name): $(object_files)
	$(CXX) $^ -o $@ $(link_flags) -pipe

VPATH   := $(source_dirs)
%.o: %.cpp
	$(CXX) $< -c $(compile_flags) $(addprefix -I , $(include_dirs)) -MD -pipe 2>log

include $(wildcard   *.d)
