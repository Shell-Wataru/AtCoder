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
    long long  N,K,i,a_i,result;
    cin >> N >> K;
    long long* numberCount = new long long[N+1];
    priority_queue<long long, vector<long long>, greater<long long>> countMins;

    for (i = 0;i<= N;i++){
        numberCount[i] = 0;
    }

    for(i=0;i<N;i++){
        cin >> a_i;;
        numberCount[a_i]++;
    }

    for(i=0;i<=N;i++){
        countMins.push(numberCount[i]);
    }

    result = 0;
    for(i=0;i<=N-K;i++){
        result += countMins.top();
        countMins.pop();
    }

    cout << result << endl;

    return 0;
}