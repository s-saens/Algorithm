#include <bits/stdc++.h>

int main()
{
    int r, p, c = 0, h = 0, a = 1, s[11], d[11] = {1}, g, i;
    for (i = 0; i < 11; ++i)
    {
        std::cin >> s[i];
        a *= s[i];
        if (i)
            d[i] = s[i - 1] * d[i - 1];
    }

    int t[a], q[a];
    for (i = 0; i < a; ++i)
    {
        std::cin >> g;
        t[i] = g;
        if (g>0) q[h++] = i;
        if (g < 0) r++;
    }
    while (c < h)
    {
        g = q[c++];
        r++;
        p = t[g] - 1;
        for (i = 0; i < 22; ++i)
        {
            int k = i / 2, m = i % 2 ? -1 : 1,
                n = g + m * d[k],
                v = d[k] * s[k],
                x = g % v, y = n % v;

            if (n >= 0 && n < a && m * y > m * x && !t[n])
            {
                q[h++] = n;
                t[n] = t[g] + 1;
            }
        }
    }
    if (r < a)
        p = -1;
    std::cout << p;
}
