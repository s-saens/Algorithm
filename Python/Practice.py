def f(w):
    if w==1:
        return 1
    return 2*f(w-1) + f(1);

q = []

def F(w, s, e):
    if w==1:
        q.append((s, e))
        return 1
    r = 6-s-e
    return F(w-1, s, r) + F(1, s, e) + F(w-1, r, e)

N = int(input())

if N > 20:
    print(2**N - 1)
else:
    print(F(N, 1, 3))
    for (f, s) in q:
        print(f, s, sep=' ')