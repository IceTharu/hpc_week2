#!/bin/bash

#BSUB -J collector
#BSUB -o collector_%.out
#BSUB -q hpcintro
#BSUB -n 1
#BSUB -R "rusage[mem=2048]"
#BSUB -W 10:00

module load studio
make realclean
make


for ((i=1; i<=24; i++))
do
    printf "$i " >> mandelbrot_times.csv
    OMP_NUM_THREADS=$i ./mandelbrot  >> mandelbrot_times.csv
done

