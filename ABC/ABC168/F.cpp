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
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

struct horizontal_line{
    ll a,b,c;
};
struct vertical_line{
    ll d,e,f;
};

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<vertical_line> vlines;
    vector<horizontal_line> hlines;
    set<ll> unique_xs;
    set<ll> unique_ys;


    for(int i = 0;i < N;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        hlines.push_back({a,b,c});
        unique_xs.insert(a);
        unique_xs.insert(b);
        unique_ys.insert(c);
    }

    for(int i = 0;i < M;i++){
        ll d,e,f;
        cin >> d >> e >> f;
        vlines.push_back({d,e,f});
        unique_xs.insert(d);
        unique_ys.insert(e);
        unique_ys.insert(f);
    }

    map<ll,ll> zipped_x;
    map<ll,ll> zipped_y;
    vector<ll> unique_xs_vector(unique_xs.begin(),unique_xs.end());
    vector<ll> unique_ys_vector(unique_xs.begin(),unique_xs.end());
    ll x_index = 1;
    ll y_index = 1;
    for(auto x:unique_xs){
        zipped_x[x] = x_index;
        x_index += 2;
    }

    for(auto y:unique_ys){
        zipped_y[y] = y_index;
        y_index += 2;
    }
    vector<vector<ll>> zippedG(2*unique_ys.size(),vector<ll>(2*unique_xs.size(),0));
    for(auto &l:hlines){
        for(int i = zipped_x[l.a];i <= zipped_x[l.b];i++){
            zippedG[zipped_y[l.c]][i] = 1;
        }
    }

    for(auto &l:vlines){
        for(int i = zipped_y[l.e];i <= zipped_y[l.f];i++){
            zippedG[i][zipped_x[l.d]] = 1;
        }
    }
    ll zipped_zero_index_x = 2 *(lower_bound(unique_xs_vector.begin(),unique_xs_vector.end(),0) - unique_xs_vector.begin());
    ll zipped_zero_index_y = 2 *(lower_bound(unique_ys_vector.begin(),unique_ys_vector.end(),0) - unique_ys_vector.begin());
    cout << zipped_zero_index_x << zipped_zero_index_y << endl;

    for(int i = 0;i < zippedG.size();i++){
        for(int j = 0;j < zippedG[j].size();j++){
            cout << zippedG[i][j];
        }
        cout << endl;
    }
    return 0;
}