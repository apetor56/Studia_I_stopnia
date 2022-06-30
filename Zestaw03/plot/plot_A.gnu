set terminal wxt size 1366,768

set label "data size = 1000 \n\
bucket size = 10 \n\
each dequeue operation was repeated and summed 500 times" at graph 0.1 , 0.9

set xlabel "indexes of consecitive elements in queue"
set ylabel "sum of elapsed time"

f(n) = b
fit f(x) "output_A.txt" using 1:2 via b

set yrange [0:0.0002]

plot "output_A.txt" using 1:2 title "dequeue operation complexity" linecolor rgb "#00A0FF" pointtype 2 pointsize 0.7, \
f(x) linecolor rgb "#FF0D00" linewidth 3 title "expected complexity"

pause -1