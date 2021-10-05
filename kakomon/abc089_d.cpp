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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    ll H,W,D;
    cin >> H >> W >> D;
    vector<vector<ll>> G(H,vector<ll>(W));
    vector<pair<ll,ll>> number_positions(H*W);
    vector<vector<ll>> distances(D,vector<ll>(1,0));
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            ll a;
            cin >> a;
            a--;
            G[i][j] = a;
            number_positions[a] = {i,j};
        }
    }
    // cout << "!!" << endl;
    for(int i = 0;i < D;i++){
        pair<ll,ll> current = number_positions[i];
        for(int j = 1;i + j * D< H*W;j++){
            pair<ll,ll> next = number_positions[i+j*D];
            distances[i].push_back(distances[i].back() + abs(next.first - current.first) +  + abs(next.second - current.second));
            current = next;
        }
    }
    // cout << "!!" << endl;
    ll Q;
    cin >> Q;
    for(int i = 0;i < Q;i++){
        ll l,r;
        cin >> l;
        cin >> r;
        l--;
        r--;
        ll amari = l % D;
        ll l_index = l/D;
        ll r_index = r/D;
        if (l_index > 0){
            l--;
        }
        cout << distances[amari][r_index] - distances[amari][l_index] << endl;
    }
    return 0;
}