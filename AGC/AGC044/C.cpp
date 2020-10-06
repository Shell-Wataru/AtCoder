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


struct test{
    ll b,l,u;
};
int main()
{
    // 整数の入力
    ll N ,X;
    cin >> N >> X;
    vector<test> tests;
    vector<test> tests;

    for(int i = 0; i< N;i++){
        test t;
        cin >> t.b >> t.l >> t.u;
        tests.push_back(t);
    }
    sort(tests.begin(),tests.end(),[](test a,test b)-> int{
        return a.b < b.b;
    });
    ll current_sum_b = 0;
    for(auto t:tests){
        current_sum_b += t.b * t.l;
    }
    return 0;
}