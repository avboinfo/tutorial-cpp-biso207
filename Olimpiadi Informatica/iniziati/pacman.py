#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

def can_reach_destination(N, X, Y, Z):
    for i in range(N):
        # differenza valori lungo l'asse
        dx = (X[i] - X[i+1])
        dy = (Y[i] - Y[i+1])
        dz = (Z[i] - Z[i+1])

        # controllo se il fantasma può passare
        if (dx == 0 or dx == -1) and (dy == 0 or dy == -1) and (dz == 0 or dz == -1):
            continue
        else:
            return False
    
    return True

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input0.txt')
sys.stdout = open('output.txt', 'w')

N = int(input().strip())

X = list(map(int, input().strip().split()))

Y = list(map(int, input().strip().split()))

Z = list(map(int, input().strip().split()))

# INSERT YOUR CODE HERE
success = can_reach_destination(N, X, Y, Z)


if success:
    print("YES")
else:
    print("NO")

sys.stdout.close()
