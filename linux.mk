.PHONY: all before after clean
.ONESHELL: libprogressbar.a

CXX=g++
AR=ar

OBJECTS=\
	ProgressBarManager.o

all: before libprogressbar.a after

before:
	if [ ! -d "out/" ]; then mkdir out/; fi
	if [ ! -d "progressbar/" ]; then mkdir progressbar/; fi
	if [ ! -d "progressbar/lib/" ]; then mkdir progressbar/lib/; fi
	if [ ! -d "progressbar/include/" ]; then mkdir progressbar/include/; fi

after:
	cp *.h progressbar/include/
	cp out/libprogressbar.a progressbar/lib/

libprogressbar.a: $(OBJECTS)
	cd out/
	$(AR) rcs $@ $?

%.o: %.cpp
	$(CXX) -c -std=c++17 $? -o $@
	mv $@ out/

clean:
	rm -rf out/ progressbar/
