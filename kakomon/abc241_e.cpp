#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> first_turn(N,-1);
    vector<ll> first_candies(N,-1);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll current_turn = 0;
    ll current_candies = 0;
    while(first_turn[current_candies % N] == -1 && K > 0){
        first_turn[current_candies % N] = current_turn;
        first_candies[current_candies % N] = current_candies;
        K--;
        current_turn++;
        current_candies += A[current_candies % N];
    }
    if (K == 0){
        cout << current_candies << endl;
        return 0;
    }
    // cout << "!!" << endl;
    // cout << current_candies % N << endl;
    ll period = current_turn-first_turn[current_candies%N];
    current_candies += (current_candies - first_candies[current_candies%N]) * (K/period);
    K = K % period;
    for(int i = 0;i < K;i++){
        current_candies += A[current_candies % N];
    }
    cout << current_candies << endl;
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;

    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}