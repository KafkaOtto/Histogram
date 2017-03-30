#include "Histogram.h"
#include "CImg.h"

#include<math.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
using namespace cimg_library;


int main() {
	while (1) {
		char str[30];
		cout << "input the path of image" << endl;
		cin.getline(str, 30);
		CImg<unsigned char> src(str);
		
		int width = src.width();
		int height = src.height();
		Histogram h;
		for (int i = 0; i < src.spectrum(); i++) {
			unsigned char* imgData = src.data(0, 0, 0, i);
			int* res = h.getData(imgData, width, height);
			for (int row = 0; row < height; row++) {
				for (int col = 0; col < width; col++) {
					int pix = (int)src.atXY(col, row, 0, i);
					int hist = res[pix];
					src.atXY(col, row, 0, i) = (unsigned char)hist;
					//cout << src.atXY(row, col) << endl;
				}
			}
		}
		src.save("result.bmp");
		src.display();
	}
        return 0;
}

