#include "Ball.h"
#include "grid.h"
#include <iostream>
#include <math.h>

double Ball::L = 0.0; //panjang tali
double Ball::r = 0.0; //jari-jari
double Ball::m = 0.0; //massa

Ball::Ball(){ //konstruktor
//	isCollide = false;
}

void Ball::hasCollide(double d){ //bertumbukankah?
	if (d <= 0.4) //jika jarak kurang dan sama dengan 0.020
		isCollide = true; //maka bertumbukan
	else //jika tidak
		isCollide = false; //tidak bertumbukan
	//std::cout << isCollide << std::endl; //mencetak status di konsol
}

double Ball::moving(double t){ //berberak
		pos = posisi(amp,(v/L),t);
		posX = L*sin(pos);
		posY = L*cos(pos);
		//posX = posX+(v*t); //posisi = posisi seblumnya + kecepatan d * waktu
}

void Ball::setInit(double x, double amp_, double v_){ //menyetel nilai awal
	x0 = x;	
	v = v_;
	amp = amp_;
}