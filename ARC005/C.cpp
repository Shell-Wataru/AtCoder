#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;

long long H,W,startX,startY,goalX,goalY;
string* town;
int** breaks;
bool** registered;
void dfs(long long x,long long y,long long value);

struct attack{
    long long x;
    long long y;
    long long value;
};
queue<attack> q;
void search(long long x,long long y,long long value){
    if (breaks[y][x] == -1 && (town[y][x] == '.' || town[y][x] == 'g')){
        dfs(x,y,value);
    }

    if (!registered[y][x] && town[y][x] == '#'){
        q.push({x,y,value +1});
        registered[y][x] = true;
    }
}

void dfs(long long x,long long y,long long value){
    breaks[y][x] = value;
    if (x > 0){
        search(x-1,y,value);
    }

    if (x < W - 1){
        search(x+1,y,value);
    }

    if (y > 0){
        search(x,y-1,value);
    }

    if (y < H - 1){
        search(x,y+1,value);
    }
}

void wfs(long long x,long long y,long long value){
    q.push({x,y,value});
    while(!q.empty()){
        attack a = q.front();
        q.pop();
        dfs(a.x,a.y,a.value);
    }
}


int main()
{
    // 整数の入力
    cin >> H >> W;
    town = new string[H];
    breaks = new int*[H];
    registered = new bool*[H];
    for (int i = 0;i< H;i++){
        cin >> town[i];
        breaks[i] = new int[W];
        registered[i] = new bool[W];
    }

    for (int i = 0;i< H;i++){
        for (int j = 0; j < W;j++){
            breaks[i][j] = -1;
            registered[i][j] = false;
        }
    }

    for (int i = 0;i< H;i++){
        for (int j = 0; j < W;j++){
            if (town[i][j] == 's'){
                startX = j;
                startY = i;
            }
            if (town[i][j] == 'g'){
                goalX = j;
                goalY = i;
            }
        }
    }

    wfs(startX,startY,0);

    // for (int i = 0;i< H;i++){
    //     for (int j = 0; j < W;j++){
    //         cout << breaks[i][j];
    //     }
    //     cout << endl;
    // }

    if (breaks[goalY][goalX] <=2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    // cout << breaks[goalY][goalX] << endl;

    return 0;
}