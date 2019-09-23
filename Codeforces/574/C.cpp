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
    long long N;
    vector<ll> First,Second,first_max,second_max;
    cin >> N;
    for(int i = 0;i< N;i++){
        ll h;
        cin >> h;
        First.push_back(h);
    }
    for(int i = 0;i< N;i++){
        ll h;
        cin >> h;
        Second.push_back(h);
    }

    first_max.push_back(First[0]);
    second_max.push_back(Second[0]);
    if (N >= 2){
        first_max.push_back(second_max[0] + First[1]);
        second_max.push_back(first_max[0] + Second[1]);
    }

    for(int i = 2;i<N;i++){
        first_max.push_back(max(second_max[i-1],second_max[i-2]) + First[i]);
        second_max.push_back(max(first_max[i-1],first_max[i-2]) + Second[i]);
    }
    cout << max(first_max[N-1],second_max[N-1]) << endl;

    return 0;
}