#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int main()
{
    // 整数の入力
    long long N,ai,i;
    long long start = -1;
    long long before = -1;
    bool isContinue = false;
    long long minTime = 0;
    cin >> N;
    for (i= 1;i<=N;i++){
        cin >> ai;
        if (i == ai){
            if (before != i-1){
                minTime += 1;
                before = i;
            }else{
                before = -1;
            }
        }
    }
    cout << minTime << endl;
    return 0;
}