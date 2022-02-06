#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(46);
    vector<ll> B(46);
    vector<ll> AB(46);
    vector<ll> C(46);
    vector<ll> ABC(46);
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        A[a% 46]++;
    }
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        B[a% 46]++;
    }
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        C[a% 46]++;
    }
    for(int i = 0;i < 46;i++){
        for(int j = 0;j < 46;j++){
            AB[(i+j)%46] += A[i]*B[j];
        }
    }
    for(int i = 0;i < 46;i++){
        for(int j = 0;j < 46;j++){
            ABC[(i+j)%46] += AB[i]*C[j];
        }
    }
    cout << ABC[0] << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
