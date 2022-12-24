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
namespace mp = boost::multiprecision;

string my_max(string a, string b){
    if (a.size() == b.size()){
        if (a > b){
            return a;
        }else{
            return b;
        }
    }else if(a.size() > b.size()){
        return a;
    }else{
        return b;
    }
}
int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }
    vector<ll> uses = {
        0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<string> DP(N+1,"");
    DP[0] = "0";
    for(int i =0;i <= N;i++){
        for(int j =  0;j < M;j++){
            if (i - uses[A[j]] >= 0){
                DP[i] = my_max(DP[i], to_string(A[j]) + DP[i - uses[A[j]]] );
            }
        }
    }
    DP[N].pop_back();
    cout << DP[N] << endl;
    return 0;
}