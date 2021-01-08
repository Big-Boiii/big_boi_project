#!/bin/gnuplot

set terminal png enhanced size 1600,900
set output 'blocksizecheck.png'

#set multiplot layout 1,2 #title "Beautiful plots"

set xlabel "Block Size"
#set logscale x
#set for [i=3:9] xtics(0,2**(2*i))
set ylabel "Mflop/s"
set title "Performance comparison"
plot "(76)_output.txt" using 6:2 title "76" with lp, "(112)_output.txt" using 6:2 title "112" with lp, "(149)_output.txt" using 6:2 title "149" with lp, "(161)_output.txt" using 6:2 title "161" with lp, "(172)_output.txt" using 6:2 title "172" with lp, "(200)_output.txt" using 6:2 title "200                                              " with lp,

# set ylabel"Secs"
# set title "Runtime comparison"
# plot "(50)_output.txt" using 1:5 title "Array of structures" with lp, "soa_output" using 1:5 title "Structure of arrays" with lp

# unset multiplot

#pause mouse close
# This last line is to avoid the terminal to close 
# when you are not outputting to a file
