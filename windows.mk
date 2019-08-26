.PHONY: all before after clean
.ONESHELL: progressbar.lib

CXX=cl.exe
AR=lib.exe

OBJECTS=\
	ProgressBarManager.obj

all: before progressbar.lib after

before:
	if not exist out\ md out\ > nul 2>&1
	if not exist progressbar\ md progressbar\ > nul 2>&1
	if not exist progressbar\lib\ md progressbar\lib\ > nul 2>&1
	if not exist progressbar\include\ md progressbar\include\ > nul 2>&1

after:
	copy *.h progressbar\include\ > nul 2>&1
	copy out\progressbar.lib progressbar\lib\ > nul 2>&1

progressbar.lib: $(OBJECTS)
	cd out\ 
	$(AR) $? /out:$@

%.obj: %.cpp
	$(CXX) /c /EHsc /std:c++17 $? /Fo:$@
	move $@ out\ > nul 2>&1

clean:
	if exist out\ rd /s /q out\ > nul 2>&1
	if exist out\ rd /s /q out\ > nul 2>&1
