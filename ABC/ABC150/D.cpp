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

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    // 整数の入力
    ll N,M;
    vector<ll> A;
    cin >> N >> M;
    ll first_two_count = -1;
    ll a_gcd  = 0;
    for(int i = 0;i< N;i++){
        ll a;
        ll two_count = 0;
        cin >> a;
        while(a % 2 == 0){
            two_count++;
            a = a/2;
        }
        if (i == 0){
            first_two_count = two_count;
        }else if(first_two_count != two_count){
            cout << 0 << endl;
            return 0;
        }
        A.push_back(a);
        a_gcd = gcd(a_gcd,a);
    }
    ll a_lcm = 1;
    for(auto a: A){
        a_lcm = a * a_lcm /gcd(a_lcm,a);
        if (a_lcm<<(first_two_count-1) > M){
            cout << 0 << endl;
            return 0;
        }
    }
    a_lcm = (a_lcm<<(first_two_count-1));
    ll normal_count =  M / a_lcm;
    ll odd_count =  (normal_count + 1)/2;

    cout << odd_count << endl;

    return 0;
}