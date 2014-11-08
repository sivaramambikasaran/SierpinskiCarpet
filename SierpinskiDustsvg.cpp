#include <iostream>
#include <fstream>
#include <cmath>

std::ofstream myfile;
int nMaxLevels;
double sqrt3	=	sqrt(3.0);
double sqrt32	=	0.5*sqrt(3.0);

void SierpinskiDust(double a, double b, double size, int nLevels) {
	++nLevels;
	// double size2	=	size/2.0;
	// double size6	=	size/6.0;
	double size3	=	size/3.0;
	double size2_3	=	2.0*size/3.0;
	myfile << "<rect x= \"" << a-size3 << "\" y= \"" << b-size3 << "\" width= \"" << 2*size3 << "\" height= \"" << 2*size3 << "\" fill= \"white\" stroke=\"black\" stroke-width=\"1\" />" << std::endl;
	if (nLevels < nMaxLevels) {
		SierpinskiDust(a-size2_3, b-size2_3, size3, nLevels);
		SierpinskiDust(a-size2_3, b+size2_3, size3, nLevels);
		SierpinskiDust(a+size2_3, b+size2_3, size3, nLevels);
		SierpinskiDust(a+size2_3, b-size2_3, size3, nLevels);
		SierpinskiDust(a, b-size2_3, size3, nLevels);
		SierpinskiDust(a, b+size2_3, size3, nLevels);
		SierpinskiDust(a-size2_3, b, size3, nLevels);
		SierpinskiDust(a+size2_3, b, size3, nLevels);
	}
}

int main(int argc, char* argv[]) {
	nMaxLevels	=	atoi(argv[1]);
	std::string filename	=	"./images/SierpinskiDust_" + std::to_string(nMaxLevels) + ".svg";
	myfile.open(filename.c_str(), std::ios::out);
	double size	=	729;
	double a	=	0.0;
	double b	=	0.0;
	myfile << "<?xml version=\"1.0\"?>" << std::endl;
	myfile << "<svg viewBox = \" " << a-size << " " << b-size << " " << 2*size << " " << 2*size << "\"" << std::endl;
	myfile << "xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
	myfile << "<rect x= \"" << a-size << "\" y= \"" << b-size << "\" width= \"" << 2*size << "\" height= \"" << 2*size << "\" fill= \"black\" stroke=\"black\" stroke-width=\"1\" />";
	if (nMaxLevels > 0) {
		SierpinskiDust(a, b, size, 0);
	}
	myfile << "</svg>" << std::endl;
	myfile.close();
}