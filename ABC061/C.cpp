#include<iostream>
#include <algorithm>
#include <vector>
#include <deque> 
using namespace std;

int main()
{
    // 整数の入力
    long long N,K,i,a,b;
    int MAXSIZE = 100000;
    cin >> N >> K;
    long long* numCounts = new long long[MAXSIZE+1];
    long long totalCount = 0;
    for (i=0;i < MAXSIZE+1;i++){
        numCounts[i] = 0;
    }

    for (i=0;i < N;i++){
        cin >> a >> b;
        numCounts[a] += b;
    }

    for (i=1;i < MAXSIZE + 1;i++){
        totalCount += numCounts[i];
        if (totalCount >= K){
            cout << i << endl;
            break;
        }
    }


    return 0;
}