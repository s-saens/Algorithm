#include <bits/stdc++.h>
#define FOR(i, s, e) for (int i = s; i < e; ++i)

using namespace std;

int present(list<int> table_frame, int nf, int page)
{
    for (const int val : table_frame)
        if (val == page)
            return 1;
    return 0;
}

void printtable(list<int> table_frame, int nf)
{
    for (const int val : table_frame)
    {
        if (val == -1)
            printf("-- ");
        else
            printf("%2d ", val);
    }
    printf("||");
}

int getIndex(list<int> table_frame)
{
    int idx = 0;
    for (int val : table_frame)
    {
        if (val == -1) return idx;
        idx++;
    }
    return -1;
}

int main()
{
    // nf-number of frames
    int n, nf;

    printf("enter number of frames\n");
    scanf("%d", &nf);
    list<int> table_frame(nf, -1);

    printf("enter total number of page requests\n");
    scanf("%d", &n);
    int pages[n];

    printf("enter reference string\n");
    FOR(i, 0, n)
    scanf("%d", &pages[i]);

    int faultCnt = 0;
    printf("position of frame table after each request\n");
    FOR(i, 0, n)
    {
        printf("page table after request from %2d || ", pages[i]);
        if (!present(table_frame, nf, pages[i]))
        {
            if (table_frame.back() == -1)
            {
                list<int>::iterator it = table_frame.begin();
                for (int j = 0; j < getIndex(table_frame); j++)
                    it++;
                table_frame.insert(it, pages[i]);
                table_frame.pop_back();
            }
            else
            {
                table_frame.pop_front();
                table_frame.push_back(pages[i]);
            }

            printtable(table_frame, nf);
            printf(" page fault\n");
            faultCnt++;
            continue;
        }
        table_frame.remove(pages[i]);
        table_frame.push_back(pages[i]);

        printtable(table_frame, nf);
        printf("\n");
    }
    printf("\nNumber of page faults : %d\n\n", faultCnt);
}