import sys

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input0.txt')
sys.stdout = open('output.txt', 'w')


N = int(input().strip())

if (N%2==0): print("pari")
else: print("dispari")