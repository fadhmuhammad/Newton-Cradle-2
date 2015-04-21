set term png
set style fill solid 1.0
set xrange [-2:2]
set xtics 0.001
set xlabel "x axis"
set ylabel "y axis"
set yrange [-6:0]
do for [i=0:89] {
	filename = sprintf("plot-0%1.0f.png", i);
	set output filename
	plot \
	"data.txt" u 1:2:3 every ::i::i w circles, \
	"data.txt" u 4:5:6 every ::i::i w circles
}