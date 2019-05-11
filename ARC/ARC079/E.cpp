#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <queue>
using namespace std;

int main()
{
    // 整数の入力
    long long N,K,i,j,temp,total;
    total = 0;
    cin >> N;
    long long* data = new long long[N];
    for (i= 0; i< N;i++){
        cin >> temp;
        data[i] = temp;
    }


    bool allCrear =false;
    while(!allCrear){
        allCrear = true;
        for (i= 0; i< N;i++){
            if (data[i] >= 2 * N){
                allCrear = false;
                total += data[i]/N - 1;
                for (j= 0; j< N;j++){
                    if (i!=j){
                        data[j] += data[i]/N - 1;
                    }
                }
                data[i] = data[i] % N + N;
            }
        }
    }

    priority_queue <long long> q; // default 大きい順
    for (i= 0; i< N;i++){
        q.push(data[i]);
    }
    allCrear = false;
    int added = 0;
    while(!allCrear){
        allCrear = true;
        if (q.top() + added >= N){
            long long next = q.top() - N - 1;
            allCrear = false;
            added++;
            q.push(next);
            q.pop();
            total++;
        }
    }

    cout << total << endl;
    return 0;
}