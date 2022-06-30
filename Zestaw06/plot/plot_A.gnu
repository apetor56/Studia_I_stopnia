set terminal wxt size 1366,768

set label "max data size = 500 \n\
each removeVertex operation was repeated and summed 1000 times" at graph 0.1 , 0.9

set xlabel "removed vertex index"
set ylabel "sum of elapsed time"

f(n) = a * n + b
fit f(x) "output_A.txt" using 1:2 via a , b

# set yrange [0:0.0001]

plot "output_A.txt" using 1:2 title "removeVertex operation complexity" linecolor rgb "#00A0FF" pointtype 2 pointsize 0.7, \
f(x) linecolor rgb "#FF0D00" linewidth 3 title "expected complexity"

pause -1