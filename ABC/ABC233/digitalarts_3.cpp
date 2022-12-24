#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
#include <climits>
using namespace std;
using ll = long long;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<set<ll>> G(N);
    vector<ll> total(N,0);
    vector<ll> store(N,0);
    for(int i = 0;i < M;i++){
        char type;
        cin >> type;
        if (type == 't'){
            ll j;
            cin >> j;
            j--;
            store[j]++;
        }else if (type == 'f'){
            ll j,k;
            cin >> j >> k;
            j--;
            k--;
            total[j] -= store[k];
            total[k] -= store[j];
            G[j].insert(k);
            G[k].insert(j);
        }else{
            ll j,k;
            cin >> j >> k;
            j--;
            k--;
            total[j] += store[k];
            total[k] += store[j];
            G[j].erase(k);
            G[k].erase(j);
        }
    }
    for(int i = 0;i < N;i++){
        for(auto to:G[i]){
            total[to] += store[i];
        }
        total[i] += store[i];
    }
    sort(total.rbegin(),total.rend());
    cout << total[K-1] << endl;
    return 0;
}