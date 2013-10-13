CXX=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-MM 

MAIN=P1app.cpp
SOURCES=$(MAIN) Library.cpp Asset.cpp Book.cpp Periodical.cpp Member.cpp Date.cpp DateConversion.cpp LibraryIO.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(MAIN:.cpp=.out)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean: 
	rm -rf $(OBJECTS) $(EXECUTABLE)
