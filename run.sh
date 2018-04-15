#!/bin/bash

for i in `seq 11500 100000`;
        do
                n=$(($i%10000))
                if [ "$n" -eq "0" ]; then
                    echo $i;
                    ./bs 1 $i
                fi
                # echo $i
                # ./bs 1 $i
        done    