n = int(input())
A = input().split()
B = input().split()

A.sort()
B.sort()

answer = 0

for k in range(n) :
    answer = answer + int(A[k]) * int(B[n-k-1])

print(answer)
