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

ll gte_index(vector<ll> &A, ll value, ll r,ll l){
    if (r + 1 == l){
        return l;
    }
    ll center = (l+r)/2;
    if (A[center] >= value){
        return gte_index(A,value,r,center);
    }else{
        return gte_index(A,value,center,l);
    }
}

ll gte_count(vector<ll> &A, ll sum){
    ll count = 0;
    for(int i = 0;i < A.size();i++){
        ll current = A[i];
        // cout << current << " " << gte_index(A,sum - current,-1,A.size()) << endl;
        count += A.size() - gte_index(A,sum - current,-1,A.size());
    }
    return count;
}

ll gte_gte_count(vector<ll> &A,ll M, ll l,ll r){
    if (l + 1 == r){
        return l;
    }
    ll center = (l+r)/2;
    // cout << center << " " <<  l << " "  << r <<endl;
    if (gte_count(A,center) >= M){
        return gte_gte_count(A,M,center,r);
    }else{
        return gte_gte_count(A,M,l,center);
    }
}
int main()
{
    // 整数の入力
    ll N,M;
    set<ll> AA;
    vector<ll> SumA;
    vector<ll> A;
    cin >> N >> M;
    for(int i = 0;i< N;i++){
        ll a;
        cin >> a;
        AA.insert(a);
    }
    SumA.push_back(0);
    for(auto a: AA){
        SumA.push_back(SumA.back()+a);
        cout << a << " " << SumA.back()<< endl;
        A.push_back(a);
    }

    // cout << gte_count(A,33+34) << endl;
    ll gte_score = gte_gte_count(A,M,0,1000000);
    ll gt_count = gte_count(A,gte_score+ 1);
    cout << A.size() << endl;
    cout << gte_score << " " << gt_count << endl;

    ll count = 0;
    for(int i = 0;i < A.size();i++){
        ll current = A[A.size()-i-1];
        ll index = gte_index(A,gte_score - current,-1,A.size());
        cout << gte_score - current << endl;
        cout << current << " " << index << " " << SumA[A.size()] - SumA[index] << ","<<(A.size() - index) * current << endl;
        count += (A.size() - index) * current + SumA[A.size()] - SumA[index];
    }
    cout << count << endl;
   return 0;
}