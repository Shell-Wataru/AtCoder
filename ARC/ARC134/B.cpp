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
    string S;
    cin >> S;
    vector<vector<ll>> indices(26);
    for(int i = 0;i < N;i++){
        indices[S[i]- 'a'].push_back(i);
    }
    ll last_removed = N;
    for(int i = 0;i < N;i++){
        ll s = S[i] - 'a';
        for(int j = 0;j < s;j++){
            while(!indices[j].empty() && indices[j].back() > last_removed){
                indices[j].pop_back();
            }
            if (!indices[j].empty() && i < indices[j].back()){
                swap(S[i],S[indices[j].back()]);
                last_removed = indices[j].back();
                indices[j].pop_back();
                break;
            }
        }
    }
    cout << S << endl;
    return 0;
}