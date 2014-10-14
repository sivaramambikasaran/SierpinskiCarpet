#!/bin/bash
rm ./images/*.gif
rm ./images/*.tex
rm ./images/*.pdf
echo "Enter number of levels of Sierpinski carpet:"
read i
g++ SierpinskiCarpet.cpp
for j in `seq 0 $i`;
do
	./a.out $j
done
cd images/
for j in `seq 0 $i`;
do
	pdflatex SierpinskiCarpet_$j.tex
	convert SierpinskiCarpet_$j.pdf SierpinskiCarpet_$j.gif
done
rm *.aux
rm *.log
cd ./../
gifsicle --delay=100 --loop ./images/SierpinskiCarpet_*.gif > animationSierpinskiCarpet.gif
rm a.out