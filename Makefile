CXX=g++
LD=ld
CFLAGS=-c -Wall -std=c++11 -MD
LDFLAGS=

MAIN=main.cpp
SOURCES=Library.cpp Asset.cpp Book.cpp Periodical.cpp Member.cpp Date.cpp DateConversion.cpp LibraryIO.cpp $(MAIN) 
OBJECTS=$(SOURCES:.cpp=.o)
DEPS=$(OBJECTS:.o=.d)
EXECUTABLE=$(MAIN:.cpp=.out)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean: 
	rm -rf $(OBJECTS) $(DEPS) $(EXECUTABLE)
