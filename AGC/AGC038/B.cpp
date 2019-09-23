#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 998244353;

ll factor(ll N){
    if (N == 1){
        return 1;
    }else{
        return N * factor(N - 1) % BASE_NUM;
    }

}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
long long permutation(long long n,long long m){
    long long value = 1;
    for (long long i = 0;i < m;i++){
        value = (value * (n - i)) % BASE_NUM;
    }
    // cout << "p" << value << endl;
    return value;
}

long long combination(long long n,long long m){
    m = min(m,n-m);
    long long value = permutation(n,m);

    for (long long i = 1;i <= m;i++){
        long long x,y,reverse;
        extGCD(i,BASE_NUM,x,y);
        reverse = (x + ((abs(x/BASE_NUM) + 1)* BASE_NUM) )% BASE_NUM;
        value = (value * reverse) % BASE_NUM;
    }
    return value;
}

int main()
{
    // 整数の入力
    string S;
    ll N,total;
    cin >> N;
    cin >> S;
    ll tempN = N;
    total = factor(N);
    vector<pair<char,ll>> lst;
    for(int i = 0;i<3 * N;i++){
        if (i == 0){
            lst.push_back(make_pair(S[i],1));
        }else if(lst[lst.size()-1].first == S[i]){
            lst[lst.size()-1].second++;
        }else{
            lst.push_back(make_pair(S[i],1));
        }

        if (lst.size() >= 3 &&
            lst[lst.size()-1].first != lst[lst.size()-2].first &&
            lst[lst.size()-2].first != lst[lst.size()-3].first &&
            lst[lst.size()-3].first != lst[lst.size()-1].first &&
            lst[lst.size()-1].second == lst[lst.size()-2].second &&
            lst[lst.size()-2].second <= lst[lst.size()-3].second){
            // cout << "-----" << endl;
            // for(auto p:lst){
            //     cout << p.first << p.second << endl;
            // }

            ll length = lst[lst.size()-1].second;
            total = total * factor(length) % BASE_NUM;
            total = total * factor(length) % BASE_NUM;
            total = total * factor(length) % BASE_NUM;

            lst.pop_back();
            lst.pop_back();
            if (lst[lst.size()-1].second == length){
                lst.pop_back();
            }else{
                lst[lst.size()-1].second -= length;
            }
        }else if(lst.size() >= 4 &&
            lst[lst.size()-1].first != lst[lst.size()-2].first &&
            lst[lst.size()-2].first != lst[lst.size()-3].first &&
            lst[lst.size()-3].first != lst[lst.size()-4].first &&
            lst[lst.size()-4].first == lst[lst.size()-1].first &&
            lst[lst.size()-1].second + lst[lst.size()-4].second >= lst[lst.size()-2].second &&
            lst[lst.size()-2].second == lst[lst.size()-3].second){
            // cout << "!!!!!!!" << endl;
            // for(auto p:lst){
            //     cout << p.first << p.second << endl;
            // }

            ll length = lst[lst.size()-2].second;
            total = total * factor(length) % BASE_NUM;
            total = total * factor(length) % BASE_NUM;
            total = total * factor(length) % BASE_NUM;
            lst.pop_back();

            ll remain = length - lst[lst.size()-1].second;
            lst.pop_back();
            lst.pop_back();
            lst.pop_back();
            if (lst[lst.size()-1].second == remain){
                lst.pop_back();
            }else{
                lst[lst.size()-1].second -= remain;
            }
        }
    }

    // cout << "-----" << endl;
    // for(auto p:lst){
    //     cout << p.first << p.second << endl;
    // }
    // cout << lst.size() << endl;
    cout << total << endl;
    return 0;
}