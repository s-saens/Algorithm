min, max = input().split()
min = int(min)
max = int(max)

cnt = max - min + 1

visited = []
for i in range(max+1): visited.append(False)

for i in range(1, max):
    if visited[i] == False:
        j = 2
        while i*j*j < max+1:
            m = i*j*j
            if visited[m] == False and min <= m and m <= max:
                cnt -= 1

            visited[m] = True
            j += 1

print(cnt)
