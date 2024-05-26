#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input0.txt')
sys.stdout = open('output.txt', 'w')

T = int(input().strip())
for test in range(1, T+1):
    input()
    N = int(input().strip())
    
    P = list(map(int, input().strip().split()))
    
    ans = ""
    
    
    # INSERT YOUR CODE HERE
    won = False
    cont = 0

    for i in P:
        if i == 1: cont += 1

    num = round(N / 2)
    if ((N % 2) != 0): num = round(N / 2) + 1

    if cont >= num: won = True

    if won: print("Champion")
    else: print("Practice harder")
    
sys.stdout.close()
