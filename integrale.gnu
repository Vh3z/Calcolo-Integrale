set terminal png size 600,400 enhanced font 'Verdana,12'
set output 'integrale.png'

set border linewidth 1.5
set key fixed left top vertical

set xlabel 'x'
set ylabel 'y'

set xrange [0:0.5]
set yrange [2.29:2.4]

plot 'dati_trapezio.dat' title 'trapezio' with lines linestyle 1, \
'dati_CavalieriSimpson.dat' title 'CavalieriSimpson' with lines linestyle 2