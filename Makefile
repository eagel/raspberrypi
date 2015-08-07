CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Iinclude

OBJS = src/blink.o

LIBS = -lwiringPi

TARGETS = bin/blink

.PHONY: all
all: $(OBJS)

.PHONY: link
link: $(TARGETS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGETS)

# blink
bin/blink: src/blink.o
	$(CXX) -o bin/blink src/blink.o $(LIBS)