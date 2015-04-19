#include "Grid.h"
#include <math.h>

Grid::Grid(){
	for (int i = 0; i < 5; i++)
		order[i] = false;
}


bool Grid::checkNext(int i){
	if (order[i])
		return true;
	else
		return false;
}

void Grid::putBall(Ball *bola, int i){
	if (order[i] == false){
		ball[i] = bola;
		order[i] = true;
	}
}

double Grid::findDistance(){
	return sqrt((ball[0]->posX - ball[1]->posX)*(ball[0]->posX - ball[1]->posX));
}

void Grid::collide(){
	if (ball[0]->isCollide == true){
		if(ball[0]->v > 0.0) {
			v = ball[0]->v;
			ball[0]->v = 0.0;
		} else if (ball[0]->v == 0)
			ball[1]->v = v;
	}
}