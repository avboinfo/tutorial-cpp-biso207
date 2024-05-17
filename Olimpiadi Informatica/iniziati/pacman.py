#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

def can_reach_destination(N, X, Y, Z):
    for i in range(N):
        for j in range(i+1, N):
            # Calculate the differences along each axis
            dx = abs(X[i] - X[j])
            dy = abs(Y[i] - Y[j])
            dz = abs(Z[i] - Z[j])
            
            # Check if the ghost can reach the destination
            if (dx == 0 and dy == 0) or (dx == 0 and dz == 0) or (dy == 0 and dz == 0):
                continue
            elif (dx == 0 and dy != 0 and dz != 0) or (dy == 0 and dx != 0 and dz != 0) or (dz == 0 and dx != 0 and dy != 0):
                continue
            else:
                return False
    
    return True

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

N = int(input().strip())

X = list(map(int, input().strip().split()))

Y = list(map(int, input().strip().split()))

Z = list(map(int, input().strip().split()))

success = False


# INSERT YOUR CODE HERE
success = can_reach_destination(N, X, Y, Z)


if success:
    print("YES")
else:
    print("NO")

sys.stdout.close()
