#!/bin/bash
if [ -z $1 ]
then wc -l
else cut -d ";" -f 3 | grep -i $1
fi
