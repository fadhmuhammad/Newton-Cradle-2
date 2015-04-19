#include "Ball.h"
#include "grid.h"
#include <iostream>

double Ball::L = 0.0; //panjang tali
double Ball::r = 0.0; //jari-jari
double Ball::m = 0.0; //massa
bool Ball::isCollide = false; //bertumbukan?

Ball::Ball(){ //konstruktor

}

void Ball::hasCollide(double d){ //bertumbukankah?
	if (d <= 0.020) //jika jarak kurang dan sama dengan 0.020
		isCollide = true; //maka bertumbukan
	else //jika tidak
		isCollide = false; //tidak bertumbukan
	std::cout << isCollide << std::endl; //mencetak status di konsol
}

double Ball::moving(double t){ //berberak
		posX = posX+(v*t); //posisi = posisi seblumnya + kecepatan d * waktu
}

void Ball::setInit(double x, double v_){ //menyetel nilai awal
	posX = x;	
	v = v_;
}
	