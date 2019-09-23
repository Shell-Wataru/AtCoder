#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

struct Point{
    vector<ll> x;
};

int main()
{
    // 整数の入力
    ll N,total;
    cin >> N;
    if (N < 10){
        cout <<  N << endl;
    }else if(N <100){
        cout << 9 << endl;
    }else if (N < 1000){
        cout <<  N - 99 + 9 << endl;
    }else if (N < 10000){
        cout <<  999 - 99 + 9 << endl;
    }else if (N < 100000){
        cout <<  N - 9999 + 999 - 99 + 9 << endl;
    }else{
        cout <<  99999 - 9999 + 999 - 99 + 9 << endl;
    }

    return 0;
}