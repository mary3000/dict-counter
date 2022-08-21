#!/bin/bash

OUT="test_huge_out.txt"
BUILD_DIR="build"

rm -rf $OUT

if [ ! -d $BUILD_DIR ]; then
  mkdir $BUILD_DIR
  cd $BUILD_DIR || exit
  cmake ..
  cmake --build .
  cd ..
fi

./$BUILD_DIR/src/dict_counter huge.txt $OUT

DIFF=$(diff -q out_huge.txt $OUT 2>&1)
if [ "$DIFF" != "" ]; then
  echo "FAIL"
else
  echo "SUCCESS"
fi
