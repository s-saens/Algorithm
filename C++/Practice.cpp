#include <iostream>
#include <queue>
#include <vector>
#define s1 q1.size()
#define s2 q2.size()
#define t1 q1.top()
#define t2 q2.top()

using namespace std;

priority_queue<int> q1; // maxHeap
priority_queue<int, vector<int>, greater<int>> q2; // minHeap

int push_and_return_mid(int k)
{
    if(q1.empty())
    {
        q1.push(k);
        return k;
    }
    else if(q2.empty())
    {
        if(k < t1)
        {
            q2.push(t1);
            q1.pop(); q1.push(k);

            return k;
        }
        q2.push(k);
        return t1;
    }

    if(s1 == s2)
    {
        if(k <= t2) q1.push(k);
        else q2.push(k);
    }
    else if(s1 < s2)
    {
        if(k > t2)
        {
            q1.push(t2);
            q2.pop(); q2.push(k);
        }
        else q1.push(k);
    }
    else
    {
        if(k <= t1)
        {
            q2.push(t1);
            q1.pop(); q1.push(k);
        }
        else q2.push(k);
    }

	return s1 < s2 ? t2 : t1;
}

int main()
{
	int N; cin >> N;
    vector<int> answers;
	for(int i=0 ; i<N ; ++i)
	{
		int a; cin >> a;
        answers.push_back(push_and_return_mid(a));
	}

    for(int i=0 ; i<N ; ++i) cout << answers[i] << '\n';
}