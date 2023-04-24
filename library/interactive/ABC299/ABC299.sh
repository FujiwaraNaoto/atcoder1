#! /bin/bash

if [ -f "aaa" ] ; then
    sudo rm aaa
fi


if [ -f "A.log" ] ; then
    rm A.log
fi


if [ -f "Q.log" ] ; then
    rm Q.log
fi

if [ -f "p" ] ; then
    rm p
fi

# $1=*.cpp

echo "compiling=" $1

g++ $1 -o p -std=c++17


mkfifo aaa

echo "using python3=" $2

python3 $2 5 < aaa | ./p > aaa
python3 $2 5 < aaa | tee A.log | ./p | tee Q.log > aaa
