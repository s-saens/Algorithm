#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool buttons[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int SmallestBigger(int length)
{
    string channel = "";
    int i = 0;
    for(i = 1 ; i < 10 ; ++i) if(buttons[i]) break;

    int k = i;

    channel += k + '0';

    if(buttons[0]) for(i=1 ; i<length ; ++i) channel += '0';
    else for(i=1 ; i<length ; ++i) channel += k + '0';

    return stoi(channel);
}
string BiggestSmaller(int length)
{
    string channel = "";
    int cnt = 0;
    int first = -1;
    int second = 0;
    int i = 0;
    for(i = 9 ; i > 0 ; --i)
    {
        if(buttons[i])
        {
            if(first > -1)
            {
                first = i;
            }
            else
            {
                second = i;
            }
        }
    }

    channel += second + '0';

    for(i=1 ; i<length ; ++i) channel += first + '0';

    return channel;
}

vector<int> ClosestButton(int number)
{
    vector<int> c;
    if(buttons[number])
    {
        c.push_back(number);
        return c;
    }

    bool canReturn = false;

    for(int i=1 ; i<11 ; ++i)
    {
        int up = number + i;
        int down = number - i;

        if(up < 10 && buttons[up]) { c.push_back(up); canReturn = true; }
        if(down >= 0 && buttons[down]) { c.push_back(down); canReturn = true; }

        if(canReturn) return c;
    }
    return c;
}

string SelectChannel(string channel, string lastSelected, short sign)
{
    if(channel.length() == 0) return lastSelected;

    int number = channel[0] - '0';
    vector<int> cb;

    if(sign > 0) number = 0;
    else if(sign < 0) number = 10;

    cb = ClosestButton(number);

    int channelInt = stoi(channel);

    string closestChannel = "0";
    for(int i=0 ; i<cb.size() ; ++i)
    {
        string nextChannel = channel.substr(1, channel.length() - 1);

        if(cb[i] < number) sign = -1;
        else if(cb[i] > number) sign = 1;
        else sign = 0;

        string selected = SelectChannel(nextChannel, lastSelected + (char)(cb[i] + '0'), sign);
        if(closestChannel.compare("0") == 0) closestChannel = selected;
        else if(abs(stoi(channel) - stoi(selected)) > abs(stoi(channel) - stoi(closestChannel))) closestChannel = selected;
    }

    return closestChannel;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string channel;
    cin >> channel;
    int chanLen = channel.length();

    int N;
    cin >> N;

    int buttonsCnt = 10;
    for(int i=0 ; i<N ; ++i)
    {
        int broken; cin >> broken;
        buttons[broken] = false;
        buttonsCnt--;
    }

    if(buttonsCnt == 0) // 다 고장난 경우 : 0으로도 못감.
    {
        cout << abs(100 - stoi(channel));
        return 0;
    }
    
    if(buttonsCnt == 1 && buttons[0]) // 0 빼고 다 고장난 경우 : 0으로 갈 수 있음.
    {
        int chanInt = stoi(channel);
        int ans = min( chanInt, abs(100 - chanInt) + 1 );
        cout << ans + 1;
        return 0;
    }

    string closestChannel = SelectChannel(channel, "", 0);

    int channelInt = stoi(channel);
    int closestChannelInt = stoi(closestChannel);

    int moveButtonCnt = abs(channelInt - closestChannelInt);
    int numberButtonCnt = closestChannel.length();
    if (closestChannel[0] == '0') numberButtonCnt--;

    int clickCnt = moveButtonCnt + numberButtonCnt;

    int answer = min( clickCnt, abs(channelInt - 100) );

    int smallestBiggerChannelInt = min(abs(SmallestBigger(chanLen + 1) - channelInt), abs(channelInt - 100));
    smallestBiggerChannelInt += chanLen + 1;
    answer = min(answer, smallestBiggerChannelInt);

    // if(chanLen > 1)
    // {
    //     string biggestSmallerChannel = BiggestSmaller(chanLen);
    //     cout << '>' << biggestSmallerChannel << "\n";
    //     answer = min(answer, stoi(biggestSmallerChannel) + (int)biggestSmallerChannel.length());
    // }


    cout << answer;

    return 0;
}