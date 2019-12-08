#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

vector<ll> month_firsts{
        0,
        31,
        31+29,
        31+29+31,
        31+29+31+30,
        31+29+31+30+31,
        31+29+31+30+31+30,
        31+29+31+30+31+30+31,
        31+29+31+30+31+30+31+31,
        31+29+31+30+31+30+31+31+30,
        31+29+31+30+31+30+31+31+30+31,
        31+29+31+30+31+30+31+31+30+31+30
};

int date(ll m,ll n){
    return month_firsts[m-1] + n-1;
}

void update_holiday(vector<bool> &days, ll d){
    if (d >= 366){

    }else if (!days[d]){
        days[d] = true;
    }else{
        update_holiday(days,d+1);
    }
}
int main()
{
    // 整数の入力
    long long N;
    cin >> N;
    vector<bool> days(366,false);
    for(int i = 0;i < 366;i++){
        if(i% 7 == 0 || i% 7 == 6){
            days[i] = true;
        }
    }

    for(int i = 0;i < N;i++){
        ll m,n;
        char c;
        cin >> m >> c >> n;
        ll d = date(m,n);
        // cout << d << endl;
        update_holiday(days,d);
    }

    ll max_consequent = 0;
    ll consequent = 0;
    for(int i = 0;i < 366;i++){
        if (days[i]){
            consequent++;
            max_consequent = max(max_consequent,consequent);
        }else{
            consequent = 0;
        }
    }
    cout << max_consequent << endl;
    return 0;
}