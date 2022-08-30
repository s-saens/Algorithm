n = 1000 - int(input())
now = 500
d = 5
cnt = 0
while n > 0:
    if n >= now:
        n -= now
        cnt += 1
    else:
        now /= d
        d = 2 if d == 5 else 5

print(cnt)
