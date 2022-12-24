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
    string S;
    cin >> S;
    for (size_t i = 0; i < S.size()-1; i++)
    {
        if (S[i] != S[i+1]){
            swap(S[i],S[i+1]);
            cout << S << endl;
            return 0;
        }
    }
    ll hash  = 0;
    for (size_t i = 0; i < S.size(); i++)
    {
        hash += S[i] - 'a' + 1;
    }
    // cout << hash << endl;
    vector<ll> a(20,0);
    vector<ll> b(20,0);

    for(int i = 0;i < 20;i++){
        a[i] += max(min(hash - 26*i,26ll),0ll);
    }
    for(int i = 0;i < 20;i++){
        b[i] += (hash+20-1-i)/20;
    }
    string ans_a = "";
    string ans_b = "";
    for(int i = 0;i < 20;i++){
        if (a[i] > 0){
            ans_a += (char)('a'+ a[i] - 1);
        }
        if (b[i] > 0){
            ans_b += (char)('a'+ b[i] - 1);
        }
    }
    if (S != ans_a){
        cout << ans_a << endl;
    }else if (S != ans_b){
        cout << ans_b << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}