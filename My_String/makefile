# CXX   = g++ by default
# FLAGS = -O2 by default
# make -f makefile clean
# make -f makefile 


ifeq ($(origin CXX),default)
	CXX = g++
endif

FLAGS ?= -O2

COMMONINC = -I./include

override FLAGS += $(COMMONINC)


.PHONY: final
final: My_String.o main.o
	 $(CXX)  $^  -o $@ $(LDFLAGS)

My_String.o: ./source/My_String.cpp
	 $(CXX) $(FLAGS)  -c $^ -o $@

main.o:  main.cpp
	 $(CXX) $(FLAGS)  -c $^ -o $@

.PHONY: clean
clean:
	rm *.o final
