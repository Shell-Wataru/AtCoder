#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N,K;
    cin >> N >> K;
    vector<ll> a;
    vector<ll> b;
    vector<pair<ll,ll>> edges;
    vector<vector<ll>> G(N);
    for(int i = 1;i < N;i++){
        edges.emplace_back(i,N);
    }
    ll current = (N-1)*(N-2)/2;
    for(int i = 1;i < N;i++){
        for(int j = i+1;j < N;j++){
            if (current > K){
                edges.emplace_back(i,j);
                current--;
            }
        }
    }
    if (current == K){
        cout << edges.size() << endl;
        for(auto e:edges){
            cout << e.first << " " << e.second << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}