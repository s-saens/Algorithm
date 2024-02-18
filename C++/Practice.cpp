#include <string>
#include <algorithm>
#include <vector>
#define FOR(i,e) for(int i=0 ; i<e ; ++i)

using namespace std;

struct Element
{
    int priority;
    int index;
};

bool sortByPriority(const Element& e1, const Element& e2)
{
    return e1.priority > e2.priority;
}

int solution(vector<int> priorities, int location)
{
    vector<Element> sorted;

    int len = priorities.size();

    FOR(i,len)
    {
        sorted.push_back({priorities[i], i});
    }

    sort(sorted.begin(), sorted.end(), sortByPriority);

    int maxIndex = 0;
    int cnt = 0;
    int i = 0;
    while(cnt < len)
    {
        int max = sorted[maxIndex].priority;
        if(priorities[i] == max)
        {
            cnt++;
            if(location == i) break;

            maxIndex++;
        }
        i = (i+1) % len;
    }

    return cnt;
}