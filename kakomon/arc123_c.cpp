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

map<ll,bool> cache1,cache2,cache3,cache4;
bool solve1(ll N){
    if (cache1.find(N) != cache1.end()){
        return cache1[N];
    }
    while(N > 0){
        ll n = N % 10;
        if (1 <= n && n <= 3){
            N /= 10;
            continue;
        }else{
            cache1[N] = false;
            return false;
        }
    }
    cache1[N] = true;
    return true;
}
bool solve2(ll N){
    if (cache2.find(N) != cache2.end()){
        return cache2[N];
    }
    while(N > 0){
        ll n = N % 10;
        if (n == 1){
            cache2[N] = solve1(N);
            return cache2[N];
        }else if (2 <= n && n <= 6){
            N /= 10;
            continue;
        }else{
            cache2[N] = false;
            return false;
        }
    }
    cache2[N] = true;
    return true;
}
bool solve3(ll N){
    if (cache3.find(N) != cache3.end()){
        return cache3[N];
    }
    while(N > 0){
        ll n = N % 10;
        if (n == 1){
            cache3[N] = solve1(N);
            return cache3[N];
        }else if (n == 2){
            cache3[N] = solve2(N);
            return cache3[N];
        }else if (3 <= n && n <= 9){
            N /= 10;
            continue;
        }else{
            cache3[N] = false;
            return false;
        }
    }
    cache3[N] = true;
    return true;
}

bool solve4(ll N){
    if (cache4.find(N) != cache4.end()){
        return cache4[N];
    }
    while(N > 0){
        ll n = N % 10;
        if (4 <= n && n <= 9){
            N /= 10;
            continue;
        }else if(0<= n && n <= 2){
            N -= 10;
            N /= 10;
        }else{
            cache4[N] = solve3(N);
            return cache4[N];
        }
    }
    cache4[N] = true;
    return true;
}

int solve(){
    ll N;
    cin >> N;
    if (solve1(N)){
        cout << 1 << "\n";
    }else if (solve2(N)){
        cout << 2 << "\n";
        }else if (solve3(N)){
        cout << 3 << "\n";
        }else if (solve4(N)){
        cout << 4 << "\n";
    }else{
        cout << 5 << endl;
    }
    return 0;
}

int main()
{
    ll t;
    cin >> t;
    for(int i = 0;i < t;i++){
        solve();
    }
    return 0;
}