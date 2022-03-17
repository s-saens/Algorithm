#include <iostream>
#include <vector>

using namespace std;

class Molecule
{
    public:
    int C;
    int H;
    int O;

    Molecule(int c, int h, int o)
    {
        C = c;
        H = h;
        O = o;
    }

    Molecule operator + (Molecule &m)
    {
        int c = C + m.C;
        int h = H + m.H;
        int o = O + m.O;

        return Molecule(c, h, o);
    }

    Molecule operator * (int& a)
    {
        int c = C * a;
        int h = H * a;
        int o = O * a;

        return Molecule(c, h, o);
    }

    bool operator == (Molecule &m)
    {
        return (C == m.C && H == m.H && O == m.O);
    }
};

void ResetToZero(int& a, int& b, int& c)
{
    a = 0;
    b = 0;
    c = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string input;
    cin >> input;
    int len = input.length();

    vector<Molecule> molecules;

    int c = 0;
    int h = 0;
    int o = 0;
    int *lastChar;
    for(int i=0 ; i<len ; ++i)
    {
        switch (input[i])
        {
        case 'C':
            lastChar = &c;
            c++;
            break;
        case 'H':
            lastChar = &h;
            h++;
            break;
        case 'O':
            lastChar = &o;
            o++;
            break;
        case '+':
        case '=':
            molecules.push_back(Molecule(c, h, o));
            ResetToZero(c, h, o);
            break;
        default: // 입력 제한 있으므로 이 경우 항상 숫자.
            (*lastChar) += input[i]-'0'-1;
            break;
        }
    }
    
    molecules.push_back(Molecule(c, h, o));
    ResetToZero(c, h, o);

    for(int i=1 ; i<=10 ; ++i)
    {
        for(int j=1 ; j<=10 ; ++j)
        {
            for(int k=1 ; k<=10 ; ++k)
            {
                Molecule mol0 = (molecules[0] * i);
                Molecule mol1 = (molecules[1] * j);
                Molecule mol2 = (molecules[2] * k);

                if( ((mol0 + mol1) == mol2) )
                {
                    cout << i << ' ' << j << ' ' << k << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "NEMOGUCE";
    return 0;
}