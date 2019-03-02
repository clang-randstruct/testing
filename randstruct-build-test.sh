#!/bin/bash
BUILDIR=/media/jordan/transferinator/llvm/llvm-project/build
CLEAN=0
CORES=24
BRANCH=develop

cd "$BUILDIR"
hashes=(
57b2e55
f32833e
63da06b
e887a66
10c8ecf
4a23993
d655987
8792a60
8c53993
9a3c950
74da875
ec84f05
)

for i in "${hashes[@]}"
do
  git checkout "$i"
  if $CLEAN;
  then
    rm -rf *
    cmake -DLLVM_ENABLE_PROJECTS=clang -G "Unix Makefiles" ../llvm
  fi
  make -j "$CORES" >makeout 2>makerrs
  EXIT="$?"
  echo "$?" >>makelog
  if $EXIT;
  then
    echo "Build of $i passed"
  else
    echo "Build of $i failed; see makeout and makerrs"
  fi
done

