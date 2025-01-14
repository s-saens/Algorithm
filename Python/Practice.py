N = int(input())

set = {""}
cnt = 0

for i in range(0,N) :
    s = input().split('@');

    if len(s) != 2 : continue

    left = s[0]
    right = s[1]
    ll = len(left)
    lr = len(right)

    invalid = ll-left.count('.') < 6 or ll-left.count('.') > 30 or lr < 3 or lr > 30

    if invalid :
        continue
    
    # left
    for j in range(0, ll):
        c = left[j]

        charValid = c.isdigit() or c.isalpha() or c == '_' or c == '.'
        periodNotValid = c == '.' and (j == 0 or j==ll-1 or (j > 0 and left[j-1] == '.'))

        if not charValid or periodNotValid:
            invalid = True
            break

    # right
    for j in range(0, lr):
        c = right[j]

        charValid = c.isdigit() or c.isalpha() or c == '-' or c == '.'
        periodNotValid = c == '.' and (j == 0 or j==lr-1 or (j > 0 and right[j-1] == '.'))

        if not charValid or periodNotValid :
            invalid = True
            break
    
    if invalid :
        continue
    
    ts = (str(left).replace('.','') + '@' + right).upper()
    set.add(ts)


print(len(set)-1)