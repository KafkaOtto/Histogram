#ifndef HISTOGRAM_H
#define HISTOGRAM_H

class Histogram {
	public:
		int width;
		int height;
		double pro[256];
		int* getData(unsigned char* imgData, int w, int h);
		int* equalized();
};

#endif
