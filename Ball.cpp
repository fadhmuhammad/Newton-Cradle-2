#include "Ball.h"
#include "grid.h"
#include <iostream>

double Ball::L = 0.0;
double Ball::r = 0.0;
double Ball::m = 0.0;
bool Ball::isCollide = false;

Ball::Ball(){

}

void Ball::hasCollide(double d){
	if (d <= 0.020)
		isCollide = true;
	else
		isCollide = false;
	std::cout << isCollide << std::endl;
}

double Ball::moving(double t){
		posX = posX+(v*t);
}

void Ball::setInit(double x, double v_){
	posX = x;
	v = v_;
}
	