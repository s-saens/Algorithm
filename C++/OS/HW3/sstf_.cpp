#include <bits/stdc++.h>
using namespace std;

struct Track
{
    int pos;
    int time; // 요청 시간 = 맨 처음 인덱스
};

bool compareTrack(const Track t1, const Track t2)
{
    return t1.pos < t2.pos;
}

int main()
{
    int head;
    cout << "enter head position\n";
    cin >> head;

    int n;
    cout << "enter total requets\n";
    cin >> n;
    Track queue1[n];
    bool done[n];
    int dists[n-1];

    cout << "enter requests\n";
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        queue1[i] = {v, i};
        done[i] = 0;
    }

    sort(queue1, queue1+n, compareTrack);

    cout << head;

    int cur;
    for(int i=0 ; i<n ; ++i)
    {
        if(queue1[i].pos == head)
        {
            cur = i;
            break;
        }
    }
    done[cur] = 1;

    int count1 = 0, j, sum = 0;
    while (count1 < n-1)
    {
        int k = -1, l=cur-1, r=cur+1;

        while(l>0)
        {
            if(done[l] == 0) break;
            l--;
        }
        while(r<n)
        {
            if(done[r] == 0) break;
            r++;
        }

        int p = queue1[cur].pos;
        int pl = queue1[l].pos, pr = queue1[r].pos; 
        int dl = abs(p-pl), dr = abs(p-pr), dist;
        int tl = queue1[l].time, tr = queue1[r].time;

        k = l;
        dist = dl;

        if(dr < dl || (dr == dl && tr < tl))
        {
            k = r;
            dist = dr;
        }

        int lastPosition = queue1[cur].pos;
        int position = queue1[k].pos;

        sum += dist;
        cout << "->";
        cout << position;
        done[k] = 1;

        cur = k;

        dists[count1] = dist;
        count1++;
    }

    cout << "\nmovements: ";

    for (int i = 0; i < n - 1; ++i)
    {
        cout << dists[i];
        if(i < n-2) cout << "+";
    }

    cout << '\n';

    cout << "total head movement is = " << sum << endl;
}