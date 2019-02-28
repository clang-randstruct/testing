SHELL := /bin/bash
PROJDIR := $(HOME)/projects/llvm-project/Autoselect
RANDSTRUCT := $(PROJDIR)/build/bin/clang
REGULAR    := /usr/bin/clang

all: reg rand0 diff

reg: poc.c
	$(REGULAR) -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

rand0: poc.c
	$(RANDSTRUCT) -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

rand1: poc.c
	$(RANDSTRUCT) -randstruct-seed=generalkenobi -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

rand2: poc.c
	$(RANDSTRUCT) -randstruct-seed=hellothere -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

auto: poc.c
	$(RANDSTRUCT) -randstruct-auto poc.c -o auto
	@pahol $@ >> $@.layout

diff: reg rand0 rand1 rand2
	diff <( pahole ./reg ) <( pahole ./rand0 ) | tee diffout
	diff <( pahole ./reg ) <( pahole ./rand1 ) | tee diffout
	diff <( pahole ./reg ) <( pahole ./rand2 ) | tee diffout
	diff <( pahole ./rand0 ) <( pahole ./rand1 ) | tee diffout
	diff <( pahole ./rand0 ) <( pahole ./rand2 ) | tee diffout
	diff <( pahole ./rand1 ) <( pahole ./rand2 ) | tee diffout

.PHONY: clean
clean: 
	@rm -f reg rand{,0,1,2} rand{,0,1,2}.layout reg.layout
