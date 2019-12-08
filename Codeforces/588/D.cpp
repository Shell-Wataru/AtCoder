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
ll BASE_NUM = 998244353;

int main()
{
    // 整数の入力
    long long N;
    vector<ll> A;
    vector<ll> B;
    set<ll> duplicates;
    map<ll,ll> values;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        ll b;
        cin >> b;
        B.push_back(b);
    }

    // cout << "---" << endl;
    for(int i = 0;i< N;i++){
        if(values.find(A[i]) != values.end()){
            duplicates.insert(A[i]);
        }
        values[A[i]] =  values[A[i]] + B[i];
    }

    // cout << "---" << endl;
    ll total = 0;
    for(auto v:values){
        ll a = v.first;
        ll b = v.second;
        for(auto d: duplicates){
            if ((d | a) == d){
                total += b;
                break;
            }
        }
    }

    cout << total << endl;
   return 0;
}