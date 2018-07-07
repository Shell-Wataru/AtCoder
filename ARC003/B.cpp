#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
int main()
{
    // 整数の入力
    long long N;
    string tempS;
    vector<string> ReverseDic;
    cin >> N;
    for (int i = 0;i< N;i++){
        cin >> tempS;
        reverse(tempS.begin(),tempS.end());
        ReverseDic.push_back(tempS);
    }
    sort(ReverseDic.begin(),ReverseDic.end());
    for (int i = 0;i< N;i++){
        tempS = ReverseDic[i];
        reverse(tempS.begin(),tempS.end());
        cout << tempS << endl;
    }

    return 0;
}