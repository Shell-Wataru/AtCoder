#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void ans(string* S)
{
    long long x1,y1,x2,y2,i,j;
    cin >> y1 >> x1 >> y2 >> x2;
    vector<vector<long long>> connected;
    connected.resize(y2 - y1 + 1);
    deque<long long*> waiting;
    for (i=0; i<y2 - y1 + 1;i++){
        connected[i].resize(0);
        for (j=0;j<x2-x1+1;j++){
            connected[i].push_back(0);
        }
    }
     long long count =0;
    for (j= y1-1;j<y2;j++){
        for (i= x1-1;i<x2;i++){
            if (S[j][i] == '1' && connected[j -y1+ 1][i -x1+1] == 0){
                waiting.push_back(new long long[2]{j,i});
                count += 1;
            }
            while(!waiting.empty()){
                long long*a = waiting.back();
                waiting.pop_back();
                connected[a[0] -y1+ 1][a[1] -x1+1] = count;
                // 上
                if(a[0] >  y1-1 && S[a[0] - 1][a[1]] == '1' && connected[a[0] -y1][a[1] -x1+1] == 0){
                    waiting.push_back(new long long[2]{a[0] - 1,a[1]});
                }
                // 左
                if(a[1] >  x1-1 && S[a[0]][a[1]-1] == '1' && connected[a[0] -y1+1][a[1] -x1] == 0){
                    waiting.push_back(new long long[2]{a[0],a[1]-1});
                }
                // した
                if(a[0] < y2-1  && S[a[0] + 1][a[1]] == '1' && connected[a[0] -y1 +2][a[1] -x1+1] == 0){
                    waiting.push_back(new long long[2]{a[0] + 1,a[1]});
                }
                // 右
                if(a[1] < x2-1 && S[a[0]][a[1]+1] == '1' && connected[a[0] -y1+1][a[1] -x1+2] == 0){
                    waiting.push_back(new long long[2]{a[0],a[1] +1});
                }

            }
        }
    }

    cout << count << endl;
}

int main()
{
    // 整数の入力
    long long N,M,Q,i;
    cin >> N >> M >> Q;
    string* S = new string[N];
    for (i=0;i< N;i++){
        cin >> S[i];
    }

    for (i =0;i< Q;i++){
        ans(S);
    }
    return 0;
}