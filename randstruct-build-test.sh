#!/bin/bash
#BUILDIR=/media/jordan/transferinator/llvm/llvm-project/build
BUILDIR=~/projects/llvm-project/develop/build
CLEAN=1 # set if you want to make clean in between each build
QUITONFAIL=0 # quit if a build fails, or continue to the next one?
CORES=24
BRANCH=rfcv1
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

cd "$BUILDIR"
echo "Randstruct test: running in "`pwd`
cmake -DLLVM_ENABLE_PROJECTS=clang -G "Unix Makefiles" ../llvm
echo "Randstruct test: cmake complete"
for i in "${hashes[@]}"
do
  echo "Randstruct test: Building $i"
  git checkout "$i"
  git branch | grep \*
  if [ "$CLEAN" -ne "0" ];
  then
    make clean
  fi
  #make -j "$CORES" >/tmp/makeout 2>/tmp/makerrs
  make -j "$CORES"
  #longjob make -j "$CORES"
  EXIT="$?"
  #echo "$?" >>/tmp/makelog
  echo "$?"
  if [ "$EXIT" -eq "0" ];
  then
    echo "Randstruct test: Build of $i passed"
  else
    echo "Randstruct test: Build of $i failed"
    if [ "$QUITONFAIL" -eq "1" ];
    then
      exit 2;
    fi
  fi
done
