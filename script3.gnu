
# script no gnuplot
#
#
set multiplot layout 2,1 title "Evolução das soluções"
#
# plot 1
set title "Temperatura x Custo"
set xlabel "Temperatura"
set ylabel "Custo"
set xrange [120:155]
set yrange [10000:24000]
set format x "%.1f"
set key inside top center
set grid
plot 'solucao_1' title 'Solução final 1' with lines lt rgb 'red' lw 2, 'solucao_2' title 'Solução final 2' with lines lt rgb 'blue' lw 2, 'solucao_3' title 'Solução final 3' with lines lt rgb 'green' lw 2;
#
# plot 2
#
#
set title "Iterações x Custo"
set ylabel "Iterações"
set xlabel "Custo"
set yrange [9000:23000]
set xrange [-5:20]
set key inside top right
set grid
plot 'custInt1' using 2:1 title 'Evolução 1' with lines lt rgb 'red' lw 2, 'custInt2' using 2:1 title 'Evolução 2' with lines lt rgb 'blue' lw 2, 'custInt3' using 2:1 title 'Evolução 3' with lines lt rgb 'green' lw 2;

unset multiplot

