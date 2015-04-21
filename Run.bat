g++ -c fungsi.cpp Grid.cpp Ball.cpp
g++ main.cpp fungsi.o Grid.o Ball.o -o NewtonCradle.exe
NewtonCradle.exe
gnuplot -c Plot/plot.plt