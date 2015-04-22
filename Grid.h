#ifndef GRID_H
#define GRID_H
#include "Ball.h"

class Grid{
	public:
		Grid(); //konstruktor
		bool checkNext(int); //mengecek setelahnya
		void putBall(Ball*, int); //meletakkan bola
		double findDistance(); //mencari jarak antar dua bola
		void collide(int); //bertumbukan
	
	private:
		Ball *ball[5];
		bool order[5];
		double vt;
};

#endif