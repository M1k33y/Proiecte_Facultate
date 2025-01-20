#!/bin/bash

echo "compiling $1"
rm -f lex.yy.c
rm -f $1.tab.c
rm -f $1
bison -Wcounterexamples -d -t $1.y
#bison  -d -t $1.y
lex $1.l
g++ -g functii.cpp lex.yy.c  $1.tab.c SymTable.cpp -o $1
