all: clean directories libProgressBar.a *.h
	cp *.h out/include/

clean:
	rm -rf out/

directories:
	mkdir out/ out/lib/ out/include/

libProgressBar.a: ProgressBarManager.o
	ar rcs out/lib/libProgressBar.a out/ProgressBarManager.o 

ProgressBarManager.o: ProgressBarManager.h ProgressBarManager.cpp
	g++ -c ProgressBarManager.cpp -o out/ProgressBarManager.o