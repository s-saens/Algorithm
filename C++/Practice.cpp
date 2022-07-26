#include <iostream>
#include <queue>
#define MAX 100004
using namespace std;

struct Pos {
	int cur, cnt;
};

int n, k, shortest = 200000000, methods;
bool vis[MAX] = {0};
queue<Pos> q;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	q.push((Pos){n, 0});

	while(!q.empty()) {
		auto node = q.front(); q.pop();
		int cur = node.cur, cnt = node.cnt;

		vis[cur] = 1;

		if (shortest < cnt) break;

		if (cur == k) {
			shortest = cnt;
			methods++;
			continue;
		}

		if (cur + 1 <= MAX && !vis[cur + 1])
            q.push((Pos){cur + 1, cnt + 1});
        if (cur - 1 >= 0 && !vis[cur - 1])
            q.push((Pos){cur - 1, cnt + 1});
        if (cur * 2 <= MAX && !vis[cur * 2])
            q.push((Pos){cur * 2, cnt + 1});
    }
	
	cout << shortest << '\n' << methods;
}