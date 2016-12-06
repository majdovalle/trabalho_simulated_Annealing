
# script no gnuplot
#
#
set title "Iterações x Custos"
set ylabel "Custo"
set xlabel "Iterações"
set yrange [9000:23000]
set xrange [-5:25]
set grid
plot 'custInt1' using 2:1 title 'Evolução 1' with lines lt rgb 'red' lw 2, 'custInt2' using 2:1 title 'Evolução 2' with lines lt rgb 'blue' lw 2, 'custInt3' using 2:1 title 'Evolução 3' with lines lt rgb 'green' lw 2;
