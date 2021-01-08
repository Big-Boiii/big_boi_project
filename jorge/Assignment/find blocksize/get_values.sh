#!/bin/bash

#BSUB -J find_blocksize
#BSUB -W 10
#BSUB -q hpcintro

rm -f *.txt

msizes="76 112 149 161 172 200"
bsizes="2 5 7 10 15 20 30 35 40 50 70 100 120 150 180"

i=0
for size in $msizes
do
    for block in $bsizes
    do        
        if (($block < $size)); then
            echo $size and $block
            matmult_c.gcc blk $size $size $size $block >> "./($size)_output.txt"
        fi
    done
done

echo All done!
