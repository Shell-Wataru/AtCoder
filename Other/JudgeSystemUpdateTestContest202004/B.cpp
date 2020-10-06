#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N;
    vector<ll> Reds;
    vector<ll> Blues;
    cin >> N;

    for(int i = 0;i<N;i++){
        ll x;
        char c;
        cin >> x >> c;
        if(c == 'R'){
            Reds.push_back(x);
        }else{
            Blues.push_back(x);
        }
    }
    sort(Reds.begin(),Reds.end());
    sort(Blues.begin(),Blues.end());
    for(auto b: Reds){
        cout << b  << endl;
    }
    for(auto b: Blues){
        cout << b  << endl;
    }
    return 0;
}