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
    long long N,ai,i,j,tempSum,sum,minSum,minIndex;
    bool changed;
    vector<long long> As;
    cin >> N;
    As.push_back(0);
    for (i= N;i>=1;i--){
        cin >>ai;
        As.push_back(ai);
    }

    changed = true;
    while (changed){
        changed = false;
        minIndex = -1;
        minSum = 1;
        for (i= N;i>=1;i--){
            tempSum = 0;
            for (j=i;j<=N;j=j+i){
                tempSum += As[j];
            }

            if (tempSum <minSum){
                minSum = tempSum;
                minIndex = i;
            }
        }
        if (minIndex != -1){
            for (j=minIndex;j<=N;j=j+minIndex){
                if (As[j]!= 0){
                    changed = true;
                }
                As[j] = 0;
            }
        }
    }
    sum =0;
    for (i =1;i<=N;i++){
        sum+= As[i];
    }
    cout << sum << endl;
    return 0;
}