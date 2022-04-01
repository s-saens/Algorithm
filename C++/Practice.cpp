#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int index = 0;
    int number = 1;
    Node* left = nullptr;
    Node* right = nullptr;
};

vector<int> dp;

int FindMaximum(Node node)
{
    if(dp[node.index] > 0)
    {
        return dp[node.index];
    }

    int l = -1;
    int r = -1;

    if(node.left != nullptr)
    {
        l = FindMaximum(*node.left);
    }
    if(node.right != nullptr)
    {
        r = FindMaximum(*node.right);
    }

    if(l == -1 && r == -1)
    {
        dp[node.index] = node.number;
    }
    else
    {
        dp[node.index] = node.number + max(l, r);
    }

    return dp[node.index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int numbersCnt = N * (N+1) / 2;

    vector<Node> triangle[N];

    int index = 0;
    for(int i=0 ; i<N ; ++i)
    {
        for(int j=0 ; j<=i ; ++j)
        {
            int n;
            cin >> n;
            Node node;
            node.number = n;
            node.index = index;
            triangle[i].push_back(node);
            dp.push_back(0);
            index++;
        }
    }

    for(int i=0 ; i<N-1 ; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            triangle[i][j].left = &triangle[i+1][j];
            triangle[i][j].right = &triangle[i+1][j+1];
        }
    }

    cout << FindMaximum(triangle[0][0]);

    return 0;
}