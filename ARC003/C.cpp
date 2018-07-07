#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
struct PositionWithTime{
    long first;
    long second;
    long t;
    double maxAkarusa;
};

int Solve(ll N,ll M,double **AkarusaMin,string *Map,PositionWithTime start){
    long** Registered = new long*[N];
    for (long i = 0;i<N;i++){
        Registered[i] = new long[M];
        for (long j = 0;j<M;j++){
            Registered[i][j] = 1000000000;
        }
    }

    auto c = [Map](PositionWithTime p1,PositionWithTime p2) {
            return p1.maxAkarusa < p2.maxAkarusa;
         };
    priority_queue<PositionWithTime,vector<PositionWithTime>,decltype(c)> q(c);
    q.push(start);
    while(!q.empty()){
        PositionWithTime p = q.top();
        q.pop();
        //cout << p.first << " " << p.second << " " << p.maxAkarusa << endl;
        if (p.first+1 < N && Map[p.first+1][p.second] != '#' && Map[p.first+1][p.second] != 's' && p.t + 1 < Registered[p.first+1][p.second]){
            PositionWithTime next;
            next.first = p.first + 1;
            next.second = p.second;
            next.t = p.t + 1;
            if (Map[next.first][next.second] == 'g'){
                next.maxAkarusa = p.maxAkarusa;
            }else{
                next.maxAkarusa = min(p.maxAkarusa,(Map[next.first][next.second] - '0') * pow(0.99,next.t));
            }
            Registered[next.first][next.second] = next.t;
            q.push(next);
        }

        if (p.second+1 < M && Map[p.first][p.second+1]!= '#' && Map[p.first][p.second+1]!= 's' && p.t + 1 < Registered[p.first][p.second+1]){
                PositionWithTime next;
                next.first = p.first;
                next.second = p.second + 1;
                next.t = p.t + 1;
                if (Map[next.first][next.second] == 'g'){
                    next.maxAkarusa = p.maxAkarusa;
                }else{
                    next.maxAkarusa = min(p.maxAkarusa,(Map[next.first][next.second] - '0') * pow(0.99,next.t));
                }
                Registered[next.first][next.second] = next.t;
                q.push(next);
        }

        if (p.first-1 >=0 && Map[p.first-1][p.second]!= '#' && Map[p.first-1][p.second]!= 's' && p.t + 1 < Registered[p.first-1][p.second]){
            PositionWithTime next;
            next.first = p.first - 1;
            next.second = p.second;
            next.t = p.t + 1;
            if (Map[next.first][next.second] == 'g'){
                next.maxAkarusa = p.maxAkarusa;
            }else{
                next.maxAkarusa = min(p.maxAkarusa,(Map[next.first][next.second] - '0') * pow(0.99,next.t));
            }
            Registered[next.first][next.second] = next.t;
            q.push(next);
        }

        if (p.second-1 >=0 && Map[p.first][p.second-1]!= '#' && Map[p.first][p.second-1]!= 's' && p.t + 1 < Registered[p.first][p.second-1]){
            PositionWithTime next;
            next.first = p.first;
            next.second = p.second - 1;
            next.t = p.t + 1;
            if (Map[next.first][next.second] == 'g'){
                next.maxAkarusa = p.maxAkarusa;
            }else{
                next.maxAkarusa = min(p.maxAkarusa,(Map[next.first][next.second] - '0') * pow(0.99,next.t));
            }
            Registered[next.first][next.second] = next.t;
            q.push(next);
        }

        AkarusaMin[p.first][p.second] = p.maxAkarusa;
        if (Map[p.first][p.second] == 'g'){
            break;
        }
    }


    return 0;
}

int main()
{
    // 整数の入力
    ll N,M,i,j,start_x,start_y,goal_x,goal_y;
    double **AkarusaMin;
    cin >> N >> M;
    string *Map = new string[N];
    for (i = 0;i<N;i++){
        cin >> Map[i];
    }

    AkarusaMin = new double*[N];
    for (i = 0;i<N;i++){
        AkarusaMin[i] = new double[M];
        for (j = 0;j<M;j++){
            AkarusaMin[i][j] = -1;
        }
    }

    for (i = 0;i<N;i++){
        for (j = 0;j<M;j++){
            if (Map[i][j] == 's'){
                start_x = i;
                start_y = j;
            }
            if (Map[i][j] == 'g'){
                goal_x = i;
                goal_y = j;
            }
        }
    }
    PositionWithTime start;
    start.first = start_x;
    start.second = start_y;
    start.t = 0;
    start.maxAkarusa = 10;
    Solve(N,M,AkarusaMin,Map,start);
    if (AkarusaMin[goal_x][goal_y] == -1){
        cout << -1 << endl;
    }else{
        cout << fixed << setprecision(14) << AkarusaMin[goal_x][goal_y] << endl;
    }
    return 0;
}