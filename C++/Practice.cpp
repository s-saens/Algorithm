#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
    char character = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node()
    {

    }
    Node(int c, Node* l, Node* r)
    {
        character = c;
        left = l;
        right = r;
    }
};


Node tree[27];

void LRC(Node* start)
{
    if(start->left != nullptr) LRC(start->left);
    if(start->right != nullptr) LRC(start->right);
    cout << start->character;
}
void LCR(Node* start)
{
    if(start->left != nullptr)
        LCR(start->left);
    cout << start->character;
    if(start->right != nullptr) LCR(start->right);
}
void CLR(Node* start)
{
    cout << start->character;
    if(start->left != nullptr) CLR(start->left);
    if(start->right != nullptr) CLR(start->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=0 ; i<N ; ++i)
    {
        char c, l, r;
        cin >> c >> l >> r;
        tree[c-'A'].character = c;
        if(l != '.') tree[c-'A'].left = &tree[l-'A'];
        if(r != '.') tree[c-'A'].right = &tree[r-'A'];
    }

    CLR(&tree[0]); // 전위
    cout << "\n";
    LCR(&tree[0]); // 중위
    cout << "\n";
    LRC(&tree[0]); // 후위

    return 0;
}