
# script no gnuplot
#
#
set title "Temperatura x Custo"
set xlabel "Temperatura"
set ylabel "Custo"
set xrange [110:160]
set yrange [10000:24000]
set format x "%.1f"
set key inside top left
set grid
plot 'solucao_2' title 'Solução final 2' with lines lt rgb 'blue' lw 2

