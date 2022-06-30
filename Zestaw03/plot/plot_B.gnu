set terminal wxt size 1366,768

set label "queue max size = 1000 \n\
in each one specific step dequeue function was executed 1000 times \n\
(from full queue to empty queue) \n\
each dequeue operation was repeated and summed 10000 times" at graph 0.1 , 0.9

set xlabel "data size"
set ylabel "sum of elapsed time"

f(n) = a * log(n) + b
fit f(x) "output_B.txt" using 1:2 via a,b

set yrange [0.0003:0.0010]

plot "output_B.txt" using 1:2 title "dequeue operation complexity" linecolor rgb "#00A0FF" pointtype 2 pointsize 0.7, \
f(x) linecolor rgb "#FF0D00" linewidth 3 title "expected complexity"

pause -1