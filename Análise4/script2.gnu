
# script no gnuplot
#
#
set title "Iterações x Custo"
set ylabel "Custo"
set xlabel "Iterações"
set yrange [9000:24000]
set xrange [-5:25]
set grid
plot 'custInt1' using 2:1 title 'Evolução 1' with lines lt rgb 'red' lw 2, 'custInt2' using 2:1 title 'Evolução 2' with lines lt rgb 'blue' lw 2, 'custInt3' using 2:1 title 'Evolução 3' with lines lt rgb 'green' lw 2, 'custInt4' using 2:1 title 'Evolução 4' with lines lt rgb 'violet' lw 2, 'custInt5' using 2:1 title 'Evolução 5' with lines lt rgb 'yellow' lw 2

