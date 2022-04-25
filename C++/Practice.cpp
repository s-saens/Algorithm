#include <iostream>
#define ll long long

using namespace std;

struct Vector2
{
    ll x, y;
    ll size;

    Vector2(ll _x, ll _y)
    {
        x = _x;
        y = _y;
        size = x*x + y*y;
    }
    
    Vector2 operator - (Vector2 &v2)
    {
        return Vector2(x - v2.x, y - v2.y);
    }

    ll operator * (Vector2 &v2)
    {
        return (x * v2.x) + (y * v2.y);
    }
    
    short operator >> (Vector2 &v2) // 외적한 값의 sign : -1 or 0 or 1
    {
        ll cross = (x * v2.y) - (y * v2.x);

        if (cross < 0) return -1;
        if (cross > 0) return 1;
        return 0;
    }

    bool operator <= (Vector2 &v2) // v가 v2의 왼쪽(반시계방향, CCW)에 있는 경우 true 반환
    {
        return (v2 >> *this) > 0;
    }
};

bool PisinL(Vector2 p, Vector2 X, Vector2 Y)
{
    Vector2 XY = Y-X;
    Vector2 XP = p-X;
    if(XY.size < XP.size) return false;
    if(XY * XP < 0) return false;
    return XY >> XP == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Vector2 A = Vector2(x1, y1);
    Vector2 B = Vector2(x2, y2);
    Vector2 C = Vector2(x3, y3);
    Vector2 D = Vector2(x4, y4);

    Vector2 AB = B-A;
    Vector2 AC = C-A;
    Vector2 AD = D-A;
    Vector2 CA = A-C;
    Vector2 CB = B-C;
    Vector2 CD = D-C;

    int crossProduct = (AB >> AC) * (AB >> AD);

    if (PisinL(C, A, B) || PisinL(D, A, B) || PisinL(A, C, D) || PisinL(B, C, D)) // 선에 포함되는 점이 단 한개라도 있다면 선분이 교차된 것을 의미.
    {
        cout << 1; return 0;
    }

    if(crossProduct < 0) // "직"선이 교차함.
    {
        if(AC <= AB) // C가 직선 AB의 왼쪽에 있음. (= D가 직선 AB의 오른쪽에 있음.)
        {
            cout << ((CB <= CD) && (CD <= CA)); return 0;
        }

        cout << ((CD <= CB) && (CA <= CD)); return 0;
    }
    else // 직선 교차 안하면 당연히 선분도 교차 안함. 평행한 경우에도 첫번째 if문에서 안걸러졌으면 어차피 교차 못함.
    {
        cout << 0; return 0;
    }

    return 0;
}