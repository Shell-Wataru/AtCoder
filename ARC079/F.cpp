#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,M,i,a,b;
    cin >> N;
    set<long long>* to = new set<long long>[N+1];
    set<long long>* candidates = new set<long long>[N+1];
    long long* from = new long long[N+1];
    long long* nums = new long long[N+1];
    set<long long> cycle;
    set<long long> tempCycle;
    new set<long long>[N+1];

    for (i= 1;i<=N;i++){
        cin >> a;
        to[a].insert(i);
        from[i] = a;
    }

    for (i= 1;i<=N;i++){
        for (j = 0;j <= to[i].size();j++){
            candidates[i].push_back(j);
        }
    }

    for (i= 1;i<=N;i++){
        if (candidates[i].size() == 1){
            long long fromnode = from[i]
            candidates[fromnode].s
        }
    }


    long long now = 1;
    while(tempCycle.count(now) == 0){
        tempCycle.insert(now);
        now = from[now];
    }

    while(cycle.count(now) == 0){
        cycle.insert(now);
        now = from[now];
    }


    for(auto node = cycle.begin(); node != cycle.end(); ++node) {
        cout << "cyclenode;"<< *node << endl;
        for(auto leaf = to[*node].begin(); leaf != to[*node].end(); ++leaf) {
            if (cycle.count(*leaf)==0){
                cout << *leaf << endl;
            }
        }
    }


    return 0;
}