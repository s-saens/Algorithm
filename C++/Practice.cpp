#include <iostream>
#define FOR(i, s, e) for (int i = s; i < e; ++i)
using namespace std;

bool k[128][128];

int N, W = 0, B = 0;

void f(int x1, int y1, int w, int h)
{
  bool allSame = true;
  bool first = k[y1][x1];
  FOR(y, y1, y1 + h)
  FOR(x, x1, x1 + w)
  {
    if (k[y][x] != first)
    {
      allSame = false;
      break;
    }
  }

  if (!allSame)
  {
    int nw = w / 2, nh = h / 2;
    f(x1, y1, nw, nh);
    f(x1 + nw, y1, nw, nh);
    f(x1 + nw, y1 + nh, nw, nh);
    f(x1, y1 + nh, nw, nh);
  }
  else
  {
    if (first) // blue
    {
      B++;
    }
    else // white
    {
      W++;
    }
  }
}

int main()
{
  cin >> N;

  FOR(y, 0, N)
  FOR(x, 0, N)
  {
    cin >> k[y][x];
  }

  f(0, 0, N, N);

  cout << W << '\n'
       << B;

  return 0;
}