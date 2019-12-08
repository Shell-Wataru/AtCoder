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
    map<ll,ll> data;
    cin >> N;
    for (int i = 0;i< N;i++){
        ll a;
        cin >> a;
        data[a] = i + 1;
    }

    for(auto p:data){
        cout << p.second << " ";
    }

    cout << endl;
    return 0;
}