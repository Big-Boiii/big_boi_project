#!/bin/gnuplot

set terminal png enhanced size 1600,900
set output 'mkn_vs_blk_O3_funroll.png'

#set multiplot layout 1,2 #title "Beautiful plots"

set xlabel "Memory footprint (KByte)"
set logscale x
set for [i=3:9] xtics(0,2**(2*i))
set ylabel "Mflop/s"
set title "Performance comparison"
plot "mkn_output.txt" using 1:2 title "mkn" with lp, "blk_output.txt" using 1:2 title "blk" with lp

# set ylabel"Secs"
# set title "Runtime comparison"
# plot "(50)_output.txt" using 1:5 title "Array of structures" with lp, "soa_output" using 1:5 title "Structure of arrays" with lp

# unset multiplot

#pause mouse close
# This last line is to avoid the terminal to close 
# when you are not outputting to a file
