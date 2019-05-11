#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <math.h>
using namespace std;
using ll = long long;



ll max_point(ll N, ll L, vector<ll> chosen)
{
    ll* next_good_points = new ll[N+1];
    ll last_next_good_point = N;
    for(int i = N; i>=0 ;i--){
        if ( (200 * i)  % (2 * N) >= N){
            next_good_points[i] = 0;
            last_next_good_point = 0;
        }else{
            next_good_points[i] = last_next_good_point + 1;
            last_next_good_point++;
        }
        // cout << i << ":" << next_good_points[i] << endl;
    }

    sort(chosen.begin(),chosen.end(),[next_good_points](ll a, ll b) -> bool {
        return next_good_points[a] < next_good_points[b];
    });

    ll remain_votes = N;
    for(auto a: chosen){
        remain_votes -= a;
    }
    // cout << remain_votes << endl;

    ll index = 0;
    while(remain_votes > 0){
        ll new_vote = min(remain_votes,next_good_points[chosen[index]]);
        if(chosen[index] == 0){
            chosen.push_back(new_vote);
        }else{
            chosen[index] += new_vote;
            index++;
        }
        remain_votes -= new_vote;
    }

    ll total = 0;

    for(auto a: chosen){
        // cout << "chosen:" << a <<endl;
        total += (ll)(100.0 * a /N + 0.5);
    }

    return total;
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll N,L,temp;
        vector<ll> chosen;
        cin >> N >> L;
        for (int j = 0; j < L; j++)
        {
            cin >> temp;
            chosen.push_back(temp);
        };
        chosen.push_back(0);

        cout << "Case #" << i << ": " << max_point(N,L,chosen) << endl;
    }

    return 0;
}