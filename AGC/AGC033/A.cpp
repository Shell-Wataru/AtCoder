#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long  H,W;
    queue<pair<ll,ll>> q;
    queue<pair<ll,ll>> next_q;
    cin >> H >> W;
    string *data = new string[H];
    ll count = 0;

    for(int i = 0; i< H;i++){
        cin >> data[i];
    }

    // cout << H << W << endl;
    for(int i = 0; i< H;i++){
        for (int j = 0;j < W;j++){
            if (data[i][j] == '#'){
                // cout << "inseterd" << endl;
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        pair<ll,ll> p = q.front();
        q.pop();
        if (p.first > 0 && data[p.first-1][p.second] != '#'){
            data[p.first-1][p.second] = '#';
            next_q.push(make_pair(p.first-1,p.second));
        }

        if (p.first < H - 1 && data[p.first+1][p.second] != '#'){
            data[p.first+1][p.second] = '#';
            next_q.push(make_pair(p.first+1,p.second));
        }

        if (p.second > 0 && data[p.first][p.second-1] != '#'){
            data[p.first][p.second-1] = '#';
            next_q.push(make_pair(p.first,p.second-1));
        }

        if (p.second < W - 1 && data[p.first][p.second+1] != '#'){
            data[p.first][p.second+1] = '#';
            next_q.push(make_pair(p.first,p.second+1));
        }

        if (q.empty() && !next_q.empty()){
            count++;
            // for (int i = 0; i< H;i++){
            //     cout << data[i] << endl;
            // }
            while(!next_q.empty()){
                q.push(next_q.front());
                next_q.pop();
            }
            // cout << count << endl;
        }
    }

    cout << count << endl;
    return 0;
}