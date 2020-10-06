#include<iostream>
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
ll BASE_NUM =  1000000007;


int main()
{
    // 整数の入力
    ll N;
    vector<ll> P,Q;
    cin >> N;
    for(int i = 0;i< N;i++){
        ll p;
        cin >> p;
        P.push_back(p);
    }
    for(int i = 0;i< N;i++){
        ll q;
        cin >> q;
        Q.push_back(q);
    }
    ll count_p = 0;
    ll count_q = 0;
    while(next_permutation(P.begin(),P.end())){
        count_p++;
    }
    while(next_permutation(Q.begin(),Q.end())){
        count_q++;
    }
    cout << abs(count_p - count_q) << endl;
    return 0;
}