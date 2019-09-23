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

int main()
{
    // 整数の入力
    long long N,M;
    deque<ll> A;
    cin >> N >> M;
    ll max_value = -1;
    ll max_index = -1;
    for(int i = 0;i< N;i++){
        ll a;
        cin >> a;
        if (max_value < a){
            max_value = a;
            max_index = i;
        }
        A.push_back(a);
    }
    vector<pair<ll,ll>> B;
    vector<pair<ll,ll>> C;

    for(int i = 0;i< max_index;i++){
        ll a = A.front();
        A.pop_front();
        ll b = A.front();
        A.pop_front();
        if (a < b){
            A.push_back(a);
            A.push_front(b);
        }else{
            A.push_back(b);
            A.push_front(a);
        }
        B.push_back(make_pair(a,b));
    }

    for(int i = 0;i< N-1;i++){
        ll a = A.front();
        A.pop_front();
        ll b = A.front();
        A.pop_front();
        if (a < b){
            A.push_back(a);
            A.push_front(b);
        }else{
            A.push_back(b);
            A.push_front(a);
        }
        C.push_back(make_pair(a,b));
    }

    for(int i = 0;i< M;i++){
        ll m;
        cin >> m;
        if (m <= B.size()){
            pair<ll,ll> p = B[m-1];
            cout << p.first << " " << p.second << endl;
        }else{
            pair<ll,ll> p = C[(m - B.size() - 1) % C.size()];
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}