RANDSTRUCT := $(HOME)/llvm-project/build/bin/clang
REGULAR    := /usr/bin/clang

all: reg rand

reg: poc.c
	$(REGULAR) -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

rand: poc.c
	$(RANDSTRUCT) -g -Wno-format $^ -o $@
	@pahole $@ >> $@.layout

.PHONY: clean
clean: 
	@rm -f reg rand rand.layout reg.layout
