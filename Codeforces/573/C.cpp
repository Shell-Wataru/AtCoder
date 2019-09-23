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
    long long N,M,K,planed,removed,current_page,total;
    vector<ll> P;
    cin >> N >> M >> K;
    for(int i = 0;i< M;i++){
        ll p;
        cin >> p;
        P.push_back(p);
    }
    removed = 0;
    planed = 0;
    current_page = -1;
    total = 0;

    for(int i = 0;i< M;i++){
        ll index = P[i] - removed;
        if (current_page != -1 && index > current_page * K){
            removed += planed;
            planed = 0;
            current_page = -1;
            total++;
        }
        index = P[i] - removed;

        current_page = (index - 1)/K + 1;
        planed++;
    }
    if (current_page != -1){
        total++;
    }

    cout << total << endl;
    return 0;
}