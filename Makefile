CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Iinclude

OBJS =	src/blink.o\
		src/pwm.o\
		src/isr.o

TARGETS =	bin/blink\
			bin/pwm\
			bin/isr

LIBS = -lwiringPi

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
	
# pwm
bin/pwm: src/pwm.o
	$(CXX) -o bin/pwm src/pwm.o $(LIBS)
	
# isr
bin/isr: src/isr.o
	$(CXX) -o bin/isr src/isr.o $(LIBS)