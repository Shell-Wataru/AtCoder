#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N;
    cin >> N;
    ll k = 2;
    while(k*(k-1)/2 < N){
        k++;
    }
    if (k*(k-1)/2 == N){
        ll count = 0;
        vector<vector<ll>> S(k);
        for(int i = 0;i <k;i++){
            for(int j = i+1;j < k;j++){
                count++;
                S[i].push_back(count);
                S[j].push_back(count);
            }
        }
        cout << "Yes" << endl;
        cout << k << endl;
        for(int i = 0;i < k;i++){
            cout << S[i].size();
            for(int j = 0;j < S[i].size();j++){
                cout << " " << S[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "No" << endl;
    }
    return 0;
}