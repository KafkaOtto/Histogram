main: HisRunner.cpp histogram.o CImg.h
	g++ -o main HisRunner.cpp histogram.o -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11
histogram.o: Histogram.cpp Histogram.h CImg.h
	g++ -c -o histogram.o Histogram.cpp -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11
