
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
plot 'solucao_1' title 'Solução final 1' with lines lt rgb 'red' lw 2, 'solucao_2' title 'Solução final 2' with lines lt rgb 'blue' lw 2, 'solucao_3' title 'Solução final 3' with lines lt rgb 'green' lw 2, 'solucao_4' title 'Solução final 4' with lines lt rgb 'violet' lw 2, 'solucao_5' title 'Solução final 5' with lines lt rgb 'yellow' lw 2

