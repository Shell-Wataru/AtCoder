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
ll BASE_NUM = 1000000007;

// ll pat(ll n){
//     vector<ll> A;
//     A.push_back[1];
//     A.push_back[1];
//     for(int i = 2;i<n;i++){
//         A.push_back( (A[i-1]+A[i-2]) % BASE_NUM);
//     }
//     return A[n];
// }

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
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    if (N == 1){
        cout << 1 << endl;
    }else{
        map<ll,ll> primes;
        decomposite(N,primes);
        if (primes.size() > 1){
            cout << 1 << endl;
        }else{
            cout << (*primes.begin()).first << endl;
        }
    }
    return 0;
}
