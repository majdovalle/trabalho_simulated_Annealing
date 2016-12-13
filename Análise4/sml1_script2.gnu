
# script no gnuplot
#
#
set title "Iterações x Custo"
set ylabel "Custo"
set xlabel "Iterações"
set yrange [9000:24000]
set xrange [-5:25]
set grid
plot 'custInt2' using 2:1 title 'Evolução 2' with lines lt rgb 'blue' lw 2

