#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;

    cin >> N;

    // int* arr;

    // for(int i=0 ; i<N ; ++i)
    // {
    //     cin >> arr[i];
    // }

    // int longest = 1;
    // int now_length, lastIndex;
    // for(int i=0 ; i<N ; ++i)
    // {
    //     now_length = 1;
    //     lastIndex = i;
    //     for(int j=i+1 ; j<N ; ++j)
    //     {
    //         if(arr[j]>arr[lastIndex])
    //         {
    //             now_length++;
    //         }
    //         lastIndex = j;
    //     }
    //     if(now_length > longest)
    //     {
    //         longest = now_length;
    //     }
    // }

    cout << N;
    
}