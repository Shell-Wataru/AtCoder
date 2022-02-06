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

using namespace std;
using ll = long long;
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<pair<ll, ll>> cards(N);
    ll all_gcd = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i].first >> cards[i].second;
        all_gcd = gcd(all_gcd, cards[i].first);
        all_gcd = gcd(all_gcd, cards[i].second);
    }
    for (int i = 0; i < N; i++)
    {
        cards[i].first /= all_gcd;
        cards[i].second /= all_gcd;
    }
    set<ll> primes_a;
    set<ll> primes_b;
    for(ll j = 1;j * j <= cards[0].first;j++){
        if (cards[0].first % j == 0){
            primes_a.insert(cards[0].first/j);
            primes_a.insert(j);
        }
    }
    for(ll j = 1;j * j <= cards[0].second;j++){
        if (cards[0].second % j == 0){
            primes_b.insert(cards[0].second/j);
            primes_b.insert(j);
        }
    }
    ll max_score = all_gcd;
    // cout << primes.size() << endl;
    for(auto p1:primes_a){
        for(auto p2:primes_b){
            if (gcd(p1,p2) != 1){
                continue;
            }
            bool can_divide = true;
            for(int i = 0;i < N;i++){
                if (gcd(cards[i].first,p1) == p1 && gcd(cards[i].second,p2) == p2){
                    continue;
                }else if (gcd(cards[i].second,p1) == p1 && gcd(cards[i].first,p2) == p2){
                    continue;
                }else{
                    can_divide = false;
                    break;
                }
            }
            if (can_divide){
                max_score = max(max_score, all_gcd * p1 * p2);
            }
        }
    }
    cout << max_score << endl;
    return 0;
}
