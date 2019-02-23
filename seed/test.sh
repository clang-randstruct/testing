#!/bin/bash
COMPILER=~/llvm-project/seedarg/build/bin/clang
$COMPILER -g poc.c -o poc1
$COMPILER -g poc.c -o poc2
$COMPILER -g poc.c -o poc3 -frandstruct-seed=7
$COMPILER -g poc.c -o poc4 -frandstruct-seed=7
$COMPILER -g poc.c -o poc5 -frandstruct-seed=8
$COMPILER -g poc.c -o poc6 -frandstruct-seed=8

diff <(pahole ./poc1) <(pahole ./poc2) # Should be same
diff <(pahole ./poc1) <(pahole ./poc2) # Should be same
diff <(pahole ./poc1) <(pahole ./poc2) # Should be same
diff <(pahole ./poc1) <(pahole ./poc2) # Should be different
diff <(pahole ./poc1) <(pahole ./poc2) # Should be different
diff <(pahole ./poc1) <(pahole ./poc2) # Should be different
