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
    ll n;
    string s,t;
    vector<ll> ab_pairs;
    vector<ll> ba_pairs;
    cin >> n;
    cin >> s >> t;
    for(int i = 0;i<n;i++){
        if (s[i] == 'a' && t[i] == 'b'){
            ab_pairs.push_back(i);
        }else if(s[i] == 'b' && t[i] == 'a'){
            ba_pairs.push_back(i);
        }
    }

    if ( (ab_pairs.size() + ba_pairs.size()) % 2 != 0){
        cout << -1 << endl;
    }else{
        cout << ab_pairs.size()/2 + ba_pairs.size()/2 + (ab_pairs.size()% 2)*2 << endl;
        while(ab_pairs.size() > 1){
            ll i1 = ab_pairs.back();
            ab_pairs.pop_back();
            ll i2 = ab_pairs.back();
            ab_pairs.pop_back();
            cout << i1 + 1 << " " <<i2 + 1<< endl;
        }

        while(ba_pairs.size() > 1){
            ll i1 = ba_pairs.back();
            ba_pairs.pop_back();
            ll i2 = ba_pairs.back();
            ba_pairs.pop_back();
            cout << i1 + 1 << " " <<i2 + 1 << "\n";
        }

        if (ab_pairs.size() == 1){
            ll i1 = ab_pairs.back();
            ll i2 = ba_pairs.back();
            cout << i1 + 1 << " " <<i1 + 1 << "\n";
            cout << i1 + 1<< " " << i2 + 1 << "\n";
        }

    }
    return 0;
}
