#!/bin/bash

rm -rf cscope.files cscope.out
rm -rf tags

find . \( -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.h' \) -print > cscope.files

ctags -R
cscope -i cscope.files
