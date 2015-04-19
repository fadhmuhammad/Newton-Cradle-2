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
	
	Ball::L = 5.0;	//memberi nilai panjang tali
	Ball::r = 0.01; //jari-jari
	Ball::m = 1.0; //massa
	ball[0].setInit(-0.05,0.1); //memberi posisi awal dan kecepatan
	ball[1].setInit(0.0,0.0); //memeberi posisi awal dan kecepatan
		
	
	ofstream fout;				//cetak data
	fout.open("Plot/data.txt");	//buka file
	double T = fungsi::perioda(Ball::L); //cari perioda
	double t = 0.0; //dimulai dari waktu = 0
	while (t < T){ //selama waktu kurang dari perioda
		for (int i = 0; i < sumBall; i++){ //untuk bola i sampai bola sumBall atau 2
			Ball::hasCollide(grid.findDistance()); //bertumbukankah? sambil menghitung jarak
			cout << grid.findDistance() << "\t"; //mencetak jarak di konsol
			grid.collide(); //berjalan jika bertumbukan
			ball[i].moving(t); //bergerak
			fout << ball[i].posX << "\t" << 0.0 << "\t" << 0.01 << "\t"; //mencetak pada berkas
		}
		fout << endl; //newline
		t += 0.1; //menambah waktu
	}
		
	return 0;
}