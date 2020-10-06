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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
vector<ll> inverse_array(ll n){
    vector<ll> inverse(n+1,-1);
    inverse[1] = 1;
    for(int i = 2;i<=n;i++){
        inverse[i] = BASE_NUM - inverse[BASE_NUM % i] * (BASE_NUM/i) % BASE_NUM;
    }
    return inverse;
}

vector<ll> powers_array(ll n){
    vector<ll> power(n+1,-1);
    power.push_back(1);
    for(int i = 1;i<=n;i++){
        power.push_back(power.back() * 2 % BASE_NUM);
    }
    return power;
}

vector<ll> inverses = inverse_array(2000000);
vector<ll> powers = powers_array(2000000);

int sum(ll r, ll c){
    ll patterns = powers[r+c];
    for(int i = 0;i< r;i++){
        ll combination =
        patterns -= powers[r-1-i] *
    }
}
int main()
{
    // 整数の入力
    ll r1,c1,r2,c2;
    cout << inverses[2000000] << endl;
    return 0;
}