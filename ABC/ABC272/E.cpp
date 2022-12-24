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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> answers(M,0);
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        ll d = i+1;
        ll first;
        if (A[i] < 0){
            first = (-A[i]+d-1)/d;
        }else{
            first = 1;
        }
        if (A[i]+first*d < N && first-1 < M){
            q.push({A[i]+first*d,d,first-1});
        }

    }
    while(!q.empty()){
        auto v= q.top();
        q.pop();
        ll i = v[2];
        if (answers[v[2]] ==  v[0]){
            answers[v[2]]++;
        }
        if (v[2]+1 < M && v[0]+v[1] < N){
            q.push({v[0]+v[1],v[1],v[2]+1});
        }
    }
    for(int i = 0;i < M;i++){
        cout << answers[i] << endl;
    }
    return 0;
}