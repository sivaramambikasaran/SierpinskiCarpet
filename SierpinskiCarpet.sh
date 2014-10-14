#!/bin/bash
rm *.gif
rm *.tex
rm *.pdf
echo "Enter number of levels of Sierpinski carpet:"
read i
g++ SierpinskiCarpet.cpp
for j in `seq 0 $i`;
do
	./a.out $j
	pdflatex SierpinskiCarpet_$j.tex
	convert SierpinskiCarpet_$j.pdf SierpinskiCarpet_$j.gif
done
gifsicle --delay=100 --loop SierpinskiCarpet_*.gif > animationSierpinskiCarpet.gif
rm *.aux
rm *.log
rm a.out