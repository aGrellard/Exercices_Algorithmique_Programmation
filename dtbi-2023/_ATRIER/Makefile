CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -Wconversion -Wfloat-conversion -Wsign-conversion -Wpedantic -g
CXXXFLAGS = -static-libstdc++ -static-libgcc -static

SOURCES = $(wildcard *.cpp)

EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(CXXXFLAGS)

clean:
	rm -f $(EXECUTABLES)
	
.PHONY: all clean