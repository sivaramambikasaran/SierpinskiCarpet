#include <iostream>
#include <fstream>
#include <cmath>

std::ofstream myfile;
int nMaxLevels;
double sqrt3	=	sqrt(3.0);
double sqrt32	=	0.5*sqrt(3.0);

void SierpinskiDust(double a, double b, double size, int nLevels) {
	++nLevels;
	double size2	=	size/2.0;
	double size6	=	size/6.0;
	double size3	=	size/3.0;
	//	(a-size2,b+size6) -- (a-size6,b+size6) -- (a-size6,b+size2) -- (a+size6,b+size2) -- (a+size6,b+size6) -- (a+size2,b+size6) -- (a+size2, b-size6) -- (a+size6,b-size6) -- (a+size6,b-size2) -- (a-size6,b-size2) -- (a-size6, b-size6) -- (a-size2,b-size6)
	myfile << "\\draw [draw=white, ultra thin, fill=white] (" << a-size2 << "," << b+size6 << ") -- (" << a-size6 << "," << b+size6 << ") -- (" << a-size6 << "," << b+size2 << ") -- (" << a+size6 << "," << b+size2 << ") -- (" << a+size6 << "," << b+size6 << ") -- (" << a+size2 << "," << b+size6 << ") -- (" << a+size2 << "," << b-size6 << ") -- (" << a+size6 << "," << b-size6 << ") -- (" << a+size6 << "," << b-size2 << ") -- (" << a-size6 << "," << b-size2 << ") -- (" << a+size6 << "," << b-size2 << ") -- (" << a-size6 << "," << b-size2 << ") -- (" << a-size6 << "," << b-size6 << ") -- (" << a-size2 << "," << b-size6 << ");" << std::endl;
	if (nLevels < nMaxLevels) {
		SierpinskiDust(a-size3, b-size3, size3, nLevels);
		SierpinskiDust(a-size3, b+size3, size3, nLevels);
		SierpinskiDust(a+size3, b+size3, size3, nLevels);
		SierpinskiDust(a+size3, b-size3, size3, nLevels);
	}
}

int main(int argc, char* argv[]) {
	nMaxLevels	=	atoi(argv[1]);
	std::string filename	=	"./images/SierpinskiDust_" + std::to_string(nMaxLevels) + ".tex";
	myfile.open(filename.c_str(), std::ios::out);
	myfile << "\\documentclass{standalone}" << std::endl;
	myfile << "\\usepackage{tikz}" << std::endl;
	myfile << "\\begin{document}" << std::endl;
	double scale	=	pow(3.0, nMaxLevels-2);
	myfile << "\\begin{tikzpicture}[scale=" << 81.0/scale << "]" << std::endl;
	double a	=	0.0;
	double b	=	0.0;
	myfile << "\\draw [draw=white, ultra thin, fill=purple] (" << a-0.5*scale << "," << b-0.5*scale << ") rectangle (" << a+0.5*scale << "," << b+0.5*scale << ");" << std::endl;
	if (nMaxLevels > 0) {
		SierpinskiDust(a, b, scale, 0);
	}
	myfile << "\\end{tikzpicture}" << std::endl;
	myfile << "\\end{document}" << std::endl;
	myfile.close();
}