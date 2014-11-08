#include <iostream>
#include <fstream>
#include <cmath>

std::ofstream myfile;
int nMaxLevels;
double sqrt3	=	sqrt(3.0);
double sqrt32	=	0.5*sqrt(3.0);

void SierpinskiTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double size, int nLevels) {
	++nLevels;
	double size2	=	size/2.0;
	double xnew1	=	(x2+x3)/2.0;
	double xnew2	=	(x3+x1)/2.0;
	double xnew3	=	(x1+x2)/2.0;
	double ynew1	=	(y2+y3)/2.0;
	double ynew2	=	(y3+y1)/2.0;
	double ynew3	=	(y1+y2)/2.0;
	myfile << "\\draw [draw=white, fill=white] (" << xnew1 << "," << ynew1 << ") -- (" << xnew2 << "," << ynew2 << ") -- (" << xnew3 << "," << ynew3 << ");" << std::endl;
	if (nLevels < nMaxLevels) {
		SierpinskiTriangle(x1, y1, xnew2, ynew2, xnew3, ynew3, size2, nLevels);
		SierpinskiTriangle(x2, y2, xnew3, ynew3, xnew1, ynew1, size2, nLevels);
		SierpinskiTriangle(x3, y3, xnew1, ynew1, xnew2, ynew2, size2, nLevels);
	}
}

int main(int argc, char* argv[]) {
	nMaxLevels	=	atoi(argv[1]);
	std::string filename	=	"./images/SierpinskiTriangle_" + std::to_string(nMaxLevels) + ".tex";
	myfile.open(filename.c_str(), std::ios::out);
	myfile << "\\documentclass{standalone}" << std::endl;
	myfile << "\\usepackage{tikz}" << std::endl;
	myfile << "\\begin{document}" << std::endl;
	double scale	=	pow(3.0, nMaxLevels-3);
	myfile << "\\begin{tikzpicture}[scale=" << 81.0/scale << "]" << std::endl;
	double x1	=	-0.5*scale;
	double y1	=	-sqrt32*scale/3.0;
	double x2	=	0.5*scale;
	double y2	=	-sqrt32*scale/3.0;
	double x3	=	0.0;
	double y3	=	sqrt3*scale/3.0;
	myfile << "\\draw [draw=white, fill=purple] (" << x1 << "," << y1 << ") -- (" << x2 << "," << y2 << ") -- (" << x3 << "," << y3 << ");" << std::endl;
	if (nMaxLevels > 0) {
		SierpinskiTriangle(x1, y1, x2, y2, x3, y3, scale, 0);		
	}
	myfile << "\\end{tikzpicture}" << std::endl;
	myfile << "\\end{document}" << std::endl;
	myfile.close();
}