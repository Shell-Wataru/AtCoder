#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;


int main()
{
    // 整数の入力
    long long N,Z,W,i,ai,pattern1,pattern2;
    vector<long long> As;
    cin >> N >> Z >> W;
    for (i= 0;i< N;i++){
        cin >>ai;
        As.push_back(ai);
    }

    if (N == 1){
        cout << abs(As[0] - W) <<endl;
    }else{
        pattern1 = abs(As[N-1] - W);
        pattern2 = abs(As[N-2] - As[N-1]);
        cout << max(pattern1,pattern2) << endl;
    }
    return 0;
}