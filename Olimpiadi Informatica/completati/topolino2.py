import sys

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input0.txt')
sys.stdout = open('output.txt', 'w')


N = int(input().strip())
P = list(map(int, input().strip().split()))

sum = 0
media = 0
for i in P:
    sum+= i
media = sum/N

print(f"{sum} {media}")