#!/bin/bash
for i in * 
do
    if test -f "$i" 
    then
       iconv -f Windows-1252 -t utf-8 "$i" > file && mv -f file "$i"
	echo "$i"
    fi
done
