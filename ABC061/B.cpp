#include<iostream>
#include <algorithm>
#include <vector>
#include <deque> 
using namespace std;

int main()
{
    // 整数の入力
    int N,M,i,s,t;
    cin >> N >> M;
    int* loadCounts = new int[N+1];
    for (i=0;i < N+1;i++){
        loadCounts[i] = 0;
    }


    for (i=0;i < M;i++){
        cin >> s >> t;
        loadCounts[s] += 1;
        loadCounts[t] += 1;
    }

    for (i=1;i <= N;i++){
        cout << loadCounts[i] << endl;
    }


    return 0;
}