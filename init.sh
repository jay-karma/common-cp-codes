#!/bin/bash

for f in {a..e}
do
	cp ../cp_template.cpp ${f}.cpp
done

for f in {a..e}
do
	geany ${f}.cpp
done
