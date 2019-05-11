#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
using namespace std;



int main()
{
    // 整数の入力
    long long N,M,u,v;
    cin >> N >> M;
    long long* p = new long long[N];
    fill(p,p+N,-1);
    set<long long> *G = new set<long long>[N];
    for (int i = 0;i < M;i++){
        cin >> u >> v;
        G[u-1].insert(v-1);
        G[v-1].insert(u-1);
    }

    for (int i = 0;i < N; i++){
        for(auto itr: G[i]){
            if (G[i].size() > 1 && G[itr].size() > 1){
                G[itr].erase(i);
                G[i].erase(itr);
            }
        }
    }

    for (int i = 0;i < N; i++){
        if (p[i] == -1){
            int center;
            if (G[i].size() >= G[*G[i].begin()].size()){
                center = i;
            }else{
                center = *G[i].begin();
            }

            int before = center;
            for(auto itr: G[center]){
                p[itr] = before;
                before = itr;
            }
            p[center] = before;
        }
    }

    for (int i = 0;i < N; i++){
        cout << p[i] + 1 << endl;
    }

    return 0;
}