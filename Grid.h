#ifndef GRID_H
#define GRID_H
#include "Ball.h"

class Grid{
	public:
		Grid();
		bool checkNext(int);
		void putBall(Ball*, int);
		double findDistance();
		void collide();
	
	private:
		Ball *ball[5];
		bool order[5];
		double v;
};

#endif