#include <math.h>
#include "fungsi.h"

double fungsi::posisi(double amp, double w, double t){
	return amp*sin(w*t);
}

double fungsi::kecepatan(double L){
	return sqrt(9.8/L);
}

double fungsi::perioda(double L){
	return 2*3.14*sqrt(L/9.8);
}