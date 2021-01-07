#!/bin/gnuplot

set terminal png enhanced size 1600,900
set output 'plots.png'

set multiplot layout 1,2 #title "Beautiful plots"

set xlabel "Memory footprint (Kbyte)"
set logscale x
set for [i=3:9] xtics(0,2**(2*i))
set ylabel "Mflop/s"
set title "Performance comparison"
plot "aos_output" using 1:4 title "AoS - total" with lp, "soa_output" using 1:4 title "SoA - total" with lp, "aos_output" using 1:2 title "AoS - calc" with lp, "soa_output" using 1:2 title "SoA - calc" with lp, "aos_output" using 1:3 title "AoS - re-use" with lp, "soa_output" using 1:3 title "SoA - re-use" with lp 


set ylabel"Secs"
set title "Runtime comparison"
plot "aos_output" using 1:5 title "Array of structures" with lp, "soa_output" using 1:5 title "Structure of arrays" with lp

unset multiplot

#pause mouse close
# This last line is to avoid the terminal to close 
# when you are not outputting to a file
