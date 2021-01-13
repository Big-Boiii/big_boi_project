#!/bin/bash

#BSUB -J comparison
#BSUB -W 10
#BSUB -q hpcintro

rm -f mkn_output.txt blk_output.txt

msizes="30 50 76 112 149 161 172 200 250 300 350 400 500 800 1000 2000 3000 4000"

for size in $msizes
do
    echo $size
    block=$((40*$size/100))
    matmult_c.gcc mkn $size $size $size >> "./mkn_output.txt"
    matmult_c.gcc blk $size $size $size $block >> "./blk_output.txt"
        
done

echo All done!
