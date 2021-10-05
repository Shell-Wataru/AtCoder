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
    string S;
    cin >> S;
    vector<ll> damages(S.size() + 10,0);
    vector<ll> combos(S.size() + 10,0);
    vector<ll> hukuro(S.size() + 10,5);
    vector<bool> tame(S.size() + 10,false);
    for(int i = 0;i < S.size();i++){
        if (i != 0){
            combos[i] += combos[i-1];
        }
        if (tame[i]){
            continue;
        }else if (S[i] == 'N'){
            if (hukuro[i] >= 1){
                for(int j = 1;j <= 6;j++){
                    hukuro[i+j]--;
                }
                damages[i+2] += 1 * (10 + (combos[i]/10));
                combos[i+2]++;
            }
        }else if (S[i] == 'C'){
            if (hukuro[i] >= 3){
                for(int j = 1;j <=2;j++){
                    tame[i+j] = true;
                }
                for(int j = 3;j <= 8;j++){
                    hukuro[i+j] -= 3;
                }
                damages[i+4] += 5 * (10 + (combos[i]/10));
                combos[i+4]++;
            }
        }else{
            continue;
        }
    }
    ll ans = 0;
    for(auto d:damages){
        // cout << d << ",";
        ans += d;
    }
    // cout << endl;
    // for(auto d:combos){
    //     cout << d << ",";
    // }
    // cout << endl;

    cout << ans << endl;
    return 0;
}