#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long N,zeros,total,daburi;
    map<ll,ll> piles;
    zeros = 0;
    daburi = 0;
    total = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        piles[a]++;
    }
    ll next = 0;
    for(auto p: piles){
        daburi += p.second - 1;
        for(int i = 0;i< p.second;i++){
            total += (p.first - next) % 2;
            next++;
        }
    }

    if (piles[0] >= 2 || daburi >= 2 || total % 2 == 0){
        cout << "cslnb" << endl;
    }else{
        cout << "sjfnb" << endl;
    }
    return 0;
}