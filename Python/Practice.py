fib = [0, 1]
N = int(input())
i = 2
while i <= N :
    fib.append(fib[i-1] + fib[i-2])
    i += 1

print(fib[N])