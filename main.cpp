#include <iostream>
#include <fstream>
#include "Ball.h"
#include "Grid.h"
#include "fungsi.h"

using namespace std;

int main() {
	int sumBall = 2;	//jumlah bola
	Ball ball[sumBall]; //deklarasi bola sesuai jumlah
	Grid grid;			//pasang grid
	
	for (int i = 0; i < sumBall; i++)	//meletakkan bola dalam grid
		grid.putBall(&ball[i], i);
	
	Ball::L = 5.0;	//memberi nilai
	Ball::r = 0.01;
	Ball::m = 1.0;
	ball[0].setInit(-0.05,0.1);
	ball[1].setInit(0.0,0.0);
		
	
	ofstream fout;							//cetak data
	fout.open("Plot/data.txt");
	double T = fungsi::perioda(Ball::L);
	double t = 0.0;
	while (t < T){
		for (int i = 0; i < sumBall; i++){
			Ball::hasCollide(grid.findDistance());
			cout << grid.findDistance() << "\t";
			grid.collide();
			ball[i].moving(t);
			fout << ball[i].posX << "\t" << 0.0 << "\t" << 0.01 << "\t";
		}
		fout << endl;
		t += 0.1;
	}
		
	return 0;
}