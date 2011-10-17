#!/bin/bash

for dir in $@; do
	cd $dir
	make && make && mv present.pdf ../$dir.pdf
	cd ..
done
