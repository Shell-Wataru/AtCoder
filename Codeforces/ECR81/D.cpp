#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

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

map<long long,long long> decomposite(long long N, map<long long,long long> & primes,long long next_p = 2){
    if (N == 1){
        return primes;
    }


    while (next_p * next_p <= N ) {
        if (N % next_p == 0) {
            primes[next_p] += 1;
            return decomposite(N/next_p,primes,next_p);
        } else {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}

int solve(){
    ll a,m;
    cin >> a >> m;
    ll common = gcd(a,m);
    map<ll,ll> primes;
    decomposite(m,primes);
    (a + m - 1)/m -
    cout << endl;
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}