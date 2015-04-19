#ifndef BALL_H
#define BALL_H
#include "fungsi.h"
#include <fstream>

class Ball : public fungsi {
	public:
		Ball();
		double moving(double);
		static void hasCollide(double);
		static double L;
		static double m;
		static double r;
		void setInit(double, double);
		double posX;
		double v;
		static bool isCollide;
	
	private:
		double posY;
};

#endif