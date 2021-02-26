#!/usr/bin/env bash

g++ D.cpp -o D -O2 &
g++ F.cpp -o F -O2 &

wait

./D < a.txt > a.out &
./D < b.txt > b.out &
./D < c.txt > c.out &
./D < d.txt > d.out &
./F < e.txt > e.out &
./F < f.txt > f.out &

wait