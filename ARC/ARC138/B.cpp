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

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    deque<ll> q;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        q.push_back(a);
    }
    bool flipped = false;
    while(q.size() >= 2){
        if (q[q.size()-1] == flipped){
            // cout << "B" << endl;
            q.pop_back();
        }else if (q[0] == flipped && q[1] == !flipped){
            // cout << "A" << endl;
            q.pop_front();
            flipped = !flipped;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    if (q.size() == 1 && q[0] == flipped){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}