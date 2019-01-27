#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long  N,answer,i;
    cin >> N;
    answer = 1;

    for(i=0;i<N;i++){
        answer *= 4;
    }

    cout << answer << endl;

    return 0;
}