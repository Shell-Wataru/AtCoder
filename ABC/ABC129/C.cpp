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
    ll N,M;
    cin >> N >> M;
    vector<ll> total;
    set<ll> broken;
    for(int i = 0;i<M;i++){
        ll b;
        cin >> b;
        broken.insert(b);
    }
    total.push_back(1);
    if(broken.find(1) != broken.end()){
        total.push_back(0);
    }else{
        total.push_back(1);
    }
    for(int i= 2;i<=N;i++){
        if(broken.find(i) != broken.end()){
            total.push_back(0);
        }else{
            total.push_back((total[i-1] + total[i-2]) % BASE_NUM);
        }
    }
    cout << total[N] << endl;
    return 0;
}