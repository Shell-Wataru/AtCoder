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

int main()
{
    ll K;
    cin >> K;
    vector<pair<ll,ll>> answers;
    for(ll i = 1;i <= 100000;i++){
        ll current = i;
        string cs = to_string(current);
        ll s = 0;
        for(auto c:cs){
            s += c - '0';
        }
        answers.push_back({current,s});
        do {
            current *= 10;
            current += 9;
            s += 9;
            answers.push_back({current,s});
        }while(current <= 1000000000000000ll);
    }

    sort(answers.begin(),answers.end(),[](pair<ll,ll> l, pair<ll,ll> r){
        return l.first*r.second < r.first*l.second || (l.first*r.second == r.first*l.second && l.first < r.first);
    });
    ll x = 0;
    for(auto a:answers){
        if (a.first > x && K > 0){
            x = a.first;
            cout << a.first << "\n";
            K--;
        }
    }
    cout << flush;
    return 0;
}
