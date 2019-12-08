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


int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    map<ll,ll>  cards_counts;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        cards_counts[a]++;
    }
    vector<ll> uniques;
    for(auto p:cards_counts){
        uniques.push_back(p.second);
    }
    sort(uniques.begin(),uniques.end(),greater<ll>());
    ll nokori = N;
    for(int i = 1;i<=N;i++){
        cout << min(N/i,nokori) << endl;
        if (i <= uniques.size()){
            nokori -= uniques[i-1];
        }

    }
 return 0;
}