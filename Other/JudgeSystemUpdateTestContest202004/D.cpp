#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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

int min_index(vector<ll> &GcdA, ll X,ll l,ll r){

}
int main()
{
    // 整数の入力
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(int i = 0;i< N;i++){
        cin >> A[i];
    }
    vector<ll> GcdA(N+1,0);
    for(int i = 1; i<= N;i++){
        GcdA[i] = gcd(GcdA[i-1],A[i-1]);
    }
    for(int i = 0;i< Q;i++){
        ll x;
        cin >> x;
        cout << min_index(GcdA,x,0,N) << endl;
    }
    return 0;
}