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
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<ll> WAs(N, 0), ACs(N, 0);
    for(int i = 0;i< M;i++){
        ll p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC"){
            ACs[p]+= 1;
        }else{
            if (ACs[p] == 0){
                WAs[p] += 1;
            }
        }
    }

    ll wa,ac;
    ac = 0;
    wa = 0;
    for(int i = 0; i< N;i++){
        if(ACs[i] > 0){
            ac++;
            wa += WAs[i];
        }
    }
    cout << ac << " " << wa << endl;
    return 0;
}