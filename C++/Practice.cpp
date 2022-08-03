#include <iostream>
#include <map>
#include <vector>
#define FOR(i,e)for(int i=0;i<e;++i)
using namespace std;

struct Node
{
    int level = 0;
    map<string, Node> children;
};

Node start;

void Print(Node& node, string lastString)
{
    map<string, Node>::iterator itr;
    if(lastString.length() > 0)
    {
        FOR(i, node.level) cout << "--";
        cout << lastString << '\n';
    }
    for(itr = node.children.begin() ; itr != node.children.end() ; itr++)
    {
        Print(itr->second, itr->first);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N;

    FOR(i, N)
    {
        Node* now = &start;

        cin >> K;

        FOR(j, K)
        {
            string input; cin >> input;
            if(now->children.find(input) == now->children.end()) // 자식 중에 없으면 추가하기
            {
                Node newNode;
                newNode.level = j;
                now->children[input] = newNode;
            }
            now = &now->children[input];
        }
    }

    Print(start, "");

    return 0;
}