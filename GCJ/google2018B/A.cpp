#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <math.h>
using namespace std;
using ll = long long;


ll next_good_point(ll N, ll current,vector<ll> good_points, vector<ll> bad_points){
    lower_bound(good_points.begin(),good_points.end(),current);
    if (N >=)
}

bool max_point(ll N, ll L, vector<ll> chosen)
{
    vector<ll> good_points,bad_points;
    for(int i = 1; i <= N ;i++){
        if ( (200 * i)  % (2 * N) >= N)){
            good_points.push_back(i)
        }else{
            bad_points.push_back(i)
        }
    }

    sort(chosen,[good_point,bad_point](ll a, ll b) -> bool {
        return min(a.m,max(0LL,(T - a.p)/a.s)) > min(b.m,max(0LL,(T - b.p)/b.s));
    })
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll N,L,temp;
        vector<ll> chosen;
        cin >> N >> L;
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            chosen.push_back(temp);
        };

        cout << "Case #" << i << ": " << max_point(N,L,chosen) << endl;
    }

    return 0;
}