#!/bin/gnuplot

set terminal png enhanced size 1600,900
set output 'nmkplots.png'

#set multiplot layout 1,2 #title "Beautiful plots"

set xlabel "Memory footprint (Kbyte)"
#set logscale x
set ylabel "Mflop/s"
set title "Mflops/s vs Memory Footprint"
plot "pure_nmk" using 0:2 title "nmk"  with lp, \
     "pure_nkm" using 0:2 title "nmk"  with lp, \
     "pure_mkn" using 0:2 title "mkn" with lp,\
     "pure_mnk" using 0:2 title "mnk" with lp, \
     "pure_knm" using 0:2 title "knm"  with lp, \
     "pure_kmn" using 0:2 title "kmn"  with lp,\

#set ylabel"Secs"
#set title "Runtime comparison"
#plot "aos_output" using 1:5 title "Array of structures" with lp, "soa_output" using 1:5 title "Structure of arrays" with lp

#unset multiplot

#pause mouse close
# This last line is to avoid the terminal to close 
# when you are not outputting to a file
