#include "Histogram.h"
#include "CImg.h"

#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>

using namespace std;
using namespace cimg_library;

int* Histogram::getData(unsigned char* imgData, int w, int h) {
        this->width = w;
        this->height = h;
	int total = width*height;
	memset(pro, 0, 256*sizeof(double));
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			pro[int(imgData[i*width+j])] += 1.0;
		}
	}
	for (int k = 0; k < 256; k++) {
		pro[k] = pro[k]/total;
	}
	return equalized();
}
int* Histogram::equalized() {

	double cur = 0;
	int* result = new int[256];
	for (int i = 0; i < 256; i++) {
		cur += pro[i];
		result[i] = (int) round(cur*255);
		cout << i << " " << result[i] << " " << cur << " " << endl;;
	}
	return result;
}

