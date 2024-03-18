set terminal png size 600,400 enhanced font 'Verdana,12'
set output 'funzione.png'

set border linewidth 1.5
set key fixed left top vertical

set xlabel 'x'
set ylabel 'y'

set xrange [0:3.14]
set yrange [-0.5:1.5]

plot sqrt(sin(x)) title 'sqrt(sin(x))' with lines linestyle 1
