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
    // 整数の入力
    ll N;
    cin >> N;
    string S;
    cin >> S;
    map<pair<string,string>,ll> count;
    for(int i = 0;i < (1ll<<N);i++){
        string red;
        string blue;
        for(int j = 0;j < N;j++){
            if (i & (1<<j)){
                red += S[j];
            }else{
                blue += S[j];
            }
        }
        reverse(blue.begin(),blue.end());
        count[{red,blue}]++;
    }
    ll ans = 0;
    for(int i = 0;i < (1ll<<N);i++){
        string red;
        string blue;
        for(int j = 0;j < N;j++){
            if (i & (1<<j)){
                red += S[N+j];
            }else{
                blue += S[N+j];
            }
        }
        reverse(red.begin(),red.end());
        // if (count[{red,blue}] != 0){
        //     cout << red << ":" << blue << endl;
        // }
        ans += count[{red,blue}];
    }
    cout << ans << endl;
    return 0;
}