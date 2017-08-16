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
    cin >> N >> M;
    set<long long>* edges = new set<long long>[N+1];
    for (i= 0;i<M;i++){
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    for(auto itr = edges[1].begin(); itr != edges[1].end(); ++itr) {
        if (*itr == N){
            cout << "POSSIBLE" << endl;
            return 0;
        }

        for(auto second = edges[*itr].begin(); second != edges[*itr].end(); ++second) {
            if (*second == N){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}