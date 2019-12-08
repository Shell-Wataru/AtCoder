#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve(){
    ll N,M;
    ll n_odds,n_evens;
    ll m_odds,m_evens;
    n_odds = 0;
    n_evens = 0;
    m_odds = 0;
    m_evens = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        if (a%2 == 0){
            n_evens++;
        }else{
            n_odds++;
        }
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        ll a;
        cin >> a;
        if (a%2 == 0){
            m_evens++;
        }else{
            m_odds++;
        }
    }
    // cout << "me" << m_evens << "mo" << m_odds << endl;
    // cout << "ne" << n_evens << "no" << n_odds << endl;
    cout << m_evens * n_evens + m_odds * n_odds << endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for(int i = 0;i<t;i++){
        solve();
    }
   return 0;
}