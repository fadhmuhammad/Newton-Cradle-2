#include "Grid.h"
#include <math.h>

Grid::Grid(){ //konstruktor default
	for (int i = 0; i < 5; i++)	//mendeklarasikan setiap index tidak ada bola
		order[i] = false;
}


bool Grid::checkNext(int i){ //mengecek apakah ada bola setelahnya
	if (order[i]) //jika pada index sekian ada bola
		return true; //maka setelahnya ada bola
	else	//jika tidak
		return false; // tidak ada bola
}

void Grid::putBall(Ball *bola, int i){	//Menempatkan bola pada objek grid
	if (order[i] == false){ //jika pada index sekita tidak ada bola
		ball[i] = bola; //menempatkan bola
		order[i] = true; //index sekian menjadi benar karena ada bola
	}
}

double Grid::findDistance(){ //mencari jarak antar dua bola
	return sqrt((ball[0]->posX - ball[1]->posX)*(ball[0]->posX - ball[1]->posX)); //akar dari kuadrat posisi bola0 dikurang posisi bola1
}

void Grid::collide(int i){ //menjalankan simulasi ketika bertumbukan
	if (ball[i]->isCollide == true){ // jika bertumbukan
		if(ball[i]->v > 0.0) {	// jika kecepatan bola 0 di atas 0
			vt = ball[i]->v;	// maka menyimpan kecepatan bola 0 dalam v
			ball[i]->v = 0.0; // dan membuat kecepatan bola v = 0
		} else if (ball[i-1]->v == 0) { // jika kecepatan bola 0 adalah 0
			if (order[i-1] == true && ball[i-1]->isCollide){
				ball[i-1]->v = vt; //kecepatan bola 1 menjadi sebesar v yang merupakan kecepatan bola 0 sebelum berhenti
				ball[i-1]->amp = ball[i]->amp;
			} else if (order[i+1] == true && ball[i+1]->isCollide) {
				ball[i+1]->v = vt; //kecepatan bola 1 menjadi sebesar v yang merupakan kecepatan bola 0 sebelum berhenti
				ball[i+1]->amp = ball[i]->amp;
			}
		}
	}
}