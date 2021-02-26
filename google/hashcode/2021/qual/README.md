# Hash Code 2021 - Traffic Signaling

This gets the following score.

```cpp
A – An example     =      2,002 points
B – By the ocean   =  4,568,480 points
C – Checkmate      =  1,305,748 points
D – Daily commute  =  2,489,112 points
E – Etoile         =    717,956 points
F – Forever jammed =  1,424,412 points
--------------------------------------
    Total score    = 10,507,710 points
```

(Note: this is from extended round. My official score was way worse)

File `D.cpp` is used for A-D and `F.cpp` is used for E-F. E and F could be improved further.

## The idea for D

[This](https://codeforces.com/blog/entry/88188?#comment-765533). It works really well for other tests other than F.

## The idea for F

Starting with all-1, simulate the traffic and record the total volume of each street. Then, for each intersection, we should find the optimal weights for the schedule.

- Define `allocation` to be the length of the cycle. The heuristics used is `allocation = 2 + max_volume / 42`.
- For each incoming street:
  - Do not use if the volume is very small compared to the total volume.
  - Set `weight = ceil(volume * allocation / total_volume)`.

Then repeat the simulation using the new schedule. Do it as many times as you like (but it should converge at around 30 iterations).

The order of the street is also shuffled during each iteration.

## The idea for E (pending implementation)

The pattern is the star with the center having over 200 degrees. The incoming volumes are:

```
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 7 7 9
```

Note that the cycle length is very long here.

The ideas are:

- Calculate the "gain" of each incoming street. Then cut some streets (totaling ~50 cars) which have the smallest gains. This is to lower the cycle length.
- After the cut, we know the exact cycle length. Then perform simulation similar to D to get the optimal ordering.

The ordering of the remaining intersections (all having 2 incoming streets) can also be optimized.
