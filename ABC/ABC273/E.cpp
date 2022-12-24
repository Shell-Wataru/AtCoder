#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll Q;
    scanf("%lld",&Q);
    vector<pair<ll,ll>> A;
    ll current_index = 0;
    map<ll,ll> indices;
    vector<ll> answers;
    A.push_back({-1,0});
    for(int i = 0;i < Q;i++){
        string Q;
        cin >> Q;
        if (Q == "ADD"){
            ll x;
            scanf("%lld",&x);
            A.push_back({x,current_index});
            current_index = A.size() - 1;
            answers.push_back(x);
        }else if (Q == "DELETE"){
            current_index = A[current_index].second;
            answers.push_back(A[current_index].first);
        }else if (Q == "SAVE"){
            ll y;
            scanf("%lld",&y);
            indices[y] = current_index;
            answers.push_back(A[current_index].first);
        }else if (Q == "LOAD"){
            ll z;
            scanf("%lld",&z);
            current_index = indices[z];
            answers.push_back(A[current_index].first);
        }
    }
    for(int i = 0;i < answers.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << answers[i];
    }
    cout << endl;
    return 0;
}