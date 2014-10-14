#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

std::ofstream myfile;
std::string color[9]	=	{"indigo", "black","red","green","blue","orange","yellow","violet","magenta"};
int nMaxLevels;

// void make_Movie() {
// 	std::ofstream myfile;
// 	myfile.open("movie.tex", std::ios::out);
// 	myfile << "\\documentclass{standalone}" << std::endl;
// 	myfile << "\\usepackage{animate}" << std::endl;
// 	myfile << "\\begin{document}" << std::endl;
// 	myfile << "\\begin{frame}" << std::endl << std::endl;
// 	myfile << "\\animategraphics[controls,scale=1]{1}{./finished}{}{}" << std::endl << std::endl;
// 	myfile << "\\end{frame}" << std::endl;
// 	myfile << "\\end{document}" << std::endl;
// 	myfile.close();
// }

void SierpinskiCarpet(double a, double b, double size, int nLevels) {
	++nLevels;
	double size3	=	size/3.0;
	double size6	=	size/6.0;
	myfile << "\\draw [draw=white, fill=white] (" << a-size6 << "," << b-size6 << ") rectangle (" << a+size6 << "," << b+size6 << ");" << std::endl;

	if (nLevels < nMaxLevels) {
		SierpinskiCarpet(a-size3, b-size3, size3, nLevels);
		SierpinskiCarpet(a, b-size3, size3, nLevels);
		SierpinskiCarpet(a+size3, b-size3, size3, nLevels);
		SierpinskiCarpet(a-size3, b, size3, nLevels);
		SierpinskiCarpet(a+size3, b, size3, nLevels);
		SierpinskiCarpet(a-size3, b+size3, size3, nLevels);
		SierpinskiCarpet(a, b+size3, size3, nLevels);
		SierpinskiCarpet(a+size3, b+size3, size3, nLevels);
	}
}

// void SierpinskiCarpet(int nLevels) {
// 	std::vector<std::vector<double> > left;
// 	std::vector<std::vector<double> > right;
//
// 	int n			=	1;
//
// 	double scale	=	pow(3.0, nLevels-1);
//
// 	for (int i=0; i<nLevels; ++i) {
// 		std::vector<double> temp1;
// 		std::vector<double> temp2;
// 		for (int j=0; j<n; ++j) {
// 			temp1.push_back((3.0*j+1.05)*scale/3.0/n);
// 			temp2.push_back((3.0*j+1.95)*scale/3.0/n);
// 		}
// 		n*=3;
// 		left.push_back(temp1);
// 		right.push_back(temp2);
// 	}
//
// 	for (int i=0; i<left.size(); ++i) {
// 		for (int j=0; j<left[i].size(); ++j) {
// 			std::cout << "(" << left[i][j] << "," << right[i][j] << ");" << std::endl;
// 		}
// 	}
//
// 	std::ofstream myfile;
// 	std::string filename	=	"SierpinskiCarpet_" + std::to_string(nLevels);
// 	myfile.open(filename.c_str(), std::ios::out);
// 	myfile << "\\documentclass{standalone}" << std::endl;
// 	myfile << "\\usepackage{tikz}" << std::endl;
// 	myfile << "\\begin{document}" << std::endl;
// 	myfile << "\\begin{tikzpicture}[scale=" << 9/scale << "]" << std::endl;
//
// 	myfile << "\\draw [draw=white] (0,0) rectangle (" << scale << "," << scale << ");" << std::endl;
// 	for (int i=0; i<left.size(); ++i) {
// 		for (int j=0; j<left[i].size(); ++j) {
// 			for (int k=0; k<left[i].size(); ++k) {
// 				myfile << "\\draw [fill=black] (" << left[i][j] << ", " << left[i][k] << ") rectangle (" << right[i][j] << "," << right[i][k] << ");" << std::endl;
// 			}
// 		}
// 	}
// 	myfile << "\\end{tikzpicture}" << std::endl;
// 	myfile << "\\end{document}" << std::endl;
// 	myfile.close();
// }

int main(int argc, char* argv[]) {
	nMaxLevels	=	atoi(argv[1]);
	std::string filename	=	"./images/SierpinskiCarpet_" + std::to_string(nMaxLevels) + ".tex";
	myfile.open(filename.c_str(), std::ios::out);
	myfile << "\\documentclass{standalone}" << std::endl;
	myfile << "\\usepackage{tikz}" << std::endl;
	myfile << "\\begin{document}" << std::endl;
	double scale	=	pow(3.0, nMaxLevels-1);
	myfile << "\\begin{tikzpicture}[scale=" << 81.0/scale << "]" << std::endl;
	myfile << "\\draw [draw=white, fill=purple] (" << -0.5*scale << "," << -0.5*scale << ") rectangle (" << 0.5*scale << "," << 0.5*scale << ");" << std::endl;
	if (nMaxLevels > 0) {
		SierpinskiCarpet(0, 0, scale, 0);		
	}
	myfile << "\\end{tikzpicture}" << std::endl;
	myfile << "\\end{document}" << std::endl;
	myfile.close();
}