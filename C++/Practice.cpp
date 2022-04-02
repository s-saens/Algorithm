#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
    int number = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node()
    {

    }
    Node(int n, Node* l, Node* r)
    {
        number = n;
        left = l;
        right = r;
    }
};

void RCL(Node* start)
{
    if(start->left != nullptr) RCL(start->left);
    if(start->right != nullptr) RCL(start->right);
    cout << start->number << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int newNumber;
    cin >> newNumber;

    Node* rootNode;
    Node r; r.number = newNumber;
    rootNode = &r;

    // 루트노드에 연결 추가해서, 트리 만들기.
    while(cin >> newNumber && newNumber > 0)
    {
        Node *nowNode; // 최근노드
        nowNode = &r; // 처음엔 root부터

        // 자식 없는 놈 찾기
        while (true)
        {
            if (newNumber < nowNode->number) // 왼쪽으로 가야하는데,
            {
                if(nowNode->left == nullptr) break; // 왼쪽이 없으면 멈춤
                else nowNode = nowNode->left; // 왼쪽 있으면 왼쪽으로 감. nowNode 갱신
            }
            else // 오른쪽으로 가야하는데,
            {
                if (nowNode->right == nullptr) break; // 오른쪽이 없으면 멈춤
                else nowNode = nowNode->right; // 오른쪽 있으면 오른쪽으로 감. nowNode 갱신
            }
        }

        Node *l;
        Node *r;

        if (newNumber < nowNode->number) // 왼쪽에 추가해야 함.
        {
            if(nowNode->left != nullptr)
            {
                if (nowNode->left->number < newNumber)
                {
                    l = nowNode->left;
                }
                else
                {
                    r = nowNode->left;
                }
            }
            nowNode->left = new Node(newNumber, l, r);
        }
        else
        {
            if (nowNode->right != nullptr)
            {
                if (nowNode->right->number < newNumber)
                {
                    l = nowNode->right;
                }
                else
                {
                    r = nowNode->right;
                }
            }
            nowNode->right = new Node(newNumber, l, r);
        }
    }

    RCL(rootNode);

    return 0;
}