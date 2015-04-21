#include <iostream>
#include <fstream>
#include "Ball.h"
#include "Grid.h"
#include "fungsi.h"

#define rad *3.14/180

using namespace std;

int main() {
	int sumBall = 2;	//jumlah bola
	Ball ball[sumBall]; //deklarasi bola sesuai jumlah
	Grid grid;			//pasang grid
	
	for (int i = 0; i < sumBall; i++)	//meletakkan bola dalam grid
		grid.putBall(&ball[i], i);
	
	Ball::L = 5.0;	//memberi nilai panjang tali
	Ball::r = 0.1; //jari-jari
	Ball::m = 1.0; //massa
	ball[0].setInit(0.0, -20 rad, 10.0); //memberi posisi awal dan kecepatan
	ball[1].setInit(0.2,0.0, 0.0); //memeberi posisi awal dan kecepatan
		
	
	ofstream fout;				//cetak data
	fout.open("Plot/data.txt");	//buka file
	
	double T = fungsi::perioda(Ball::L); //cari perioda
	double Tamp = 90 rad / (ball[0].v/L);
	double t = Tamp; //dimulai dari waktu = 0
	int n = 0; //counter
	cout << T << "\t" << Tamp << endl;
	while (t < T + Tamp){ //selama waktu kurang dari perioda
		for (int i = 0; i < sumBall; i++){ //untuk bola i sampai bola sumBall atau 2
			Ball::hasCollide(grid.findDistance()); //bertumbukankah? sambil menghitung jarak
			cout << grid.findDistance() << "\t"; //mencetak jarak di konsol
			//cout << t << "\t" << ball[i].v << "\t";
			grid.collide(); //berjalan jika bertumbukan
			ball[i].moving(t); //bergerak
			fout << ball[i].posX + ball[i].x0 << "\t" << -ball[i].posY <<"\t" << Ball::r << "\t"; //mencetak pada berkas
		}
		cout << endl;
		fout << endl; //newline
		t += 0.05; //menambah waktu
		n++;
	}
		
	return 0;
}