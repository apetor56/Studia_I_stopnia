set terminal wxt size 1366,768

set label "bucket size = 3 \n\
each add operation was repeated and summed 1000 times \n\
adding order: 1, 2, 3, ..., 500" at graph 0.1 , 0.9

set xlabel "data size"
set ylabel "sum of elapsed time"

set rmargin 3
set lmargin -3

f(n) = a * n + b
fit f(x) "output_B.txt" using 1:2 via a, b

plot "output_B.txt" using 1:2 title "add operation complexity" linecolor rgb "#00A0FF" pointtype 2 pointsize 0.7, \
f(x) linecolor rgb "#FF0D00" linewidth 2 title "expected comlexity"

pause -1