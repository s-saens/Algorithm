#include <iostream>
#include <cmath>

using namespace std;

int nextNum(string input, int index)
{
    int next = 0;
    for(int i=index ; i<input.length() ; ++i)
    {
        bool isOp = false;

        switch(input[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
                isOp = true;
                break;
        }

        if(isOp == true)
        {
            break;
        }

        next *= 10;
        next += (int)input[i] - (int)'0';
    }
    return next;

}

int calculate(string input)
{

    int lastNum = nextNum(input, 0);

    for(int i=1 ; i<input.length()-1 ; i++)
    {
        switch(input[i])
        {
            case '+':
                lastNum += nextNum(input, i + 1);
                break;
            case '-':
                lastNum -= nextNum(input, i + 1);
                break;
            case '*':
                lastNum *= nextNum(input, i + 1);
                break;
            case '/':
                lastNum /= nextNum(input, i + 1);
                break;
            default:

                break;
        }
    }
    return lastNum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cout << calculate("11-11-11*30/10");

    return 0;
}
