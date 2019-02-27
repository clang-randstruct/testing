SHELL := /bin/bash
PROJDIR := $(HOME)/projects/llvm-project/skip-unions
RANDSTRUCT := $(PROJDIR)/build/bin/clang
REGULAR    := /usr/bin/clang

all: reg rand diff

reg: poc.c
	$(REGULAR) -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

rand: poc.c
	$(RANDSTRUCT) -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

diff: rand reg
	diff <( pahole ./reg ) <( pahole ./rand ) | tee diffout

.PHONY: clean
clean: 
	@rm -f reg rand rand.layout reg.layout
