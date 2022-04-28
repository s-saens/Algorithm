#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool buttons[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
string c;

vector<int> FindClosest3(int number)
{
    vector<int> v;
    if(buttons[number]) v.push_back(number);
    for(int i=number-1 ; i>=0 ; --i) { if(buttons[i]) { v.push_back(i); break; } }
    for(int i=number+1 ; i<10 ; ++i) { if(buttons[i]) { v.push_back(i); break; } }

    return v;
}

string ClickButtons(string remain, string lastClicked, int sign, bool start)
{
    if(remain.length() == 0) return "";
    int number;
    if(sign == 0) number = remain[0] - '0';
    else if(sign < 0) number = 10;
    else if(sign > 0) number = -1;

    vector<int> closest3 = FindClosest3(number);

    if(!buttons[0] && start && remain.length() > 1) closest3.push_back(0);

    string minClicked = "-5000000";


    for(int i=0 ; i<closest3.size() ; ++i)
    {
        if(closest3[i] == number) sign = 0;
        else if(closest3[i] < number) sign = -1;
        else if(closest3[i] > number) sign = 1;

        string clicked = to_string(closest3[i]);

        string nextRemain = remain.substr(1, remain.length()-1);
        clicked += ClickButtons(nextRemain, lastClicked + (char)(closest3[i]+'0'), sign, false);

        if (abs(stoi(clicked) - stoi(remain)) + to_string(stoi(clicked)).length()
        < abs(stoi(minClicked) - stoi(remain)) + to_string(stoi(minClicked)).length())
        {
            minClicked = clicked;
        }
    }

    return minClicked;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string c_big = "0";
    cin >> c;
    c_big += c;

    int N;
    cin >> N;
    for(int i=0 ; i<N ; ++i)
    {
        int broken;
        cin >> broken;
        buttons[broken] = false;
    }

    if(N == 10) // 다 고장난 경우
    {
        cout << abs(stoi(c) - 100);
        return 0;
    }
    if(N == 9 && buttons[0]) // 0만 안고장난 경우
    {
        int cInt = stoi(c);
        if(cInt > 100)
        {
            cout << cInt - 100;
        }
        else
        {
            cout << min(100-cInt, 1+cInt);
        }
        return 0;
    }

    string clicked[3];

    clicked[0] = ClickButtons(c_big, "", 0, false);
    clicked[1] = ClickButtons(c, "", 0, true);
    clicked[2] = "100";

    int answer = 50000000;

    for(int i=0 ; i<3 ; ++i)
    {
        clicked[i] = to_string(stoi(clicked[i]));

        int moveCnt = abs(stoi(clicked[i]) - stoi(c)); // +- 누른 횟수
        int clickCnt = clicked[i].length(); // 채널버튼 누른 횟수
        if(i == 2) clickCnt = 0; // 처음 채널 100인 경우 고려

        answer = min(answer, moveCnt + clickCnt);
    }
    
    cout << answer;

    return 0;
}