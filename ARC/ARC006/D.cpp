#include<iostream>
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

long long H,W;

struct Rect {
    long long x,y,w,h;
};

pair<long long,long long> arrounds[8] ={
    {1,1},
    {1,0},
    {1,-1},
    {0,1},
    {0,-1},
    {-1,1},
    {-1,0},
    {-1,-1}
};

Rect findCRect(string *image,long long x,long long y){
    queue<pair<long long,long long >> q;
    set<pair<long long,long long >> s;
    q.push(make_pair(x,y));
    s.insert(make_pair(x,y));
    long long minX,minY,maxX,maxY;
    minX = x;
    minY = y;
    maxX = x;
    maxY = y;

    while(!q.empty()){
        pair<long long,long long > p = q.front();
        q.pop();
        // cout << "popped" << q.size() << endl;
        // cout << "set" << s.size() << endl;

        for(int i =0; i< 8;i++){
            pair<long long,long long > diff = arrounds[i];
            pair<long long,long long > next_p = make_pair(p.first + diff.first,p.second + diff.second);
            if (image[next_p.second][next_p.first] == 'o' && s.find(next_p) == s.end()){
                s.insert(next_p);
                q.push(next_p);
                minX = min(next_p.first,minX);
                minY = min(next_p.second,minY);
                maxX = max(next_p.first,maxX);
                maxY = max(next_p.second,maxY);
            }
        }
    }
    return {
        minX,
        minY,
        maxX - minX,
        maxY - minY
    };
}

int checkCharactor(string *image,Rect r){
    int count = 0;
    if (image[r.y][r.x] == 'o'){
        count++;
    }

    if (image[r.y + r.h][r.x] == 'o'){
        count++;
    }

    if (image[r.y][r.x + r.w] == 'o'){
        count++;
    }

    if (image[r.y + r.h][r.x + r.w] == 'o'){
        count++;
    }

    if (image[r.y + r.h/2][r.x + r.w/2] == 'o'){
        count++;
    }

    if (count == 2){
        return 0;
    }else if (count == 3){
        return 1;
    }else if (count == 0){
       return 2;
    }else {
        cout << "error" << endl;
        return 3;
    }
}

int deleteCharactor(string *image,Rect r){
    for(int i = 0;i<= r.w;i++){
        for(int j = 0;j<=r.h;j++){
            image[r.y+j][r.x+i] = '.';
        }
    }
    return 0;
}

int showRect(string *image,Rect r){
    for(int j = 0;j<=r.h;j++){
        for(int i = 0;i<= r.w;i++){
            cout << image[r.y+j][r.x+i];
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    cin >> H >> W;
    string* image = new string[H];
    for (int i = 0;i<H;i++){
        cin >> image[i];
    }
    int A = 0;
    int B = 0;
    int C = 0;

    for (int i = 0;i< W; i++){
        for(int j = 0;j<H;j++){
            if (image[j][i] == 'o'){
                Rect r = findCRect(image,i,j);
                // cout << "found r" << r.x <<  r.y << r.w << r.h << endl;
                // showRect(image,r);
                // cout << "=================================" << endl;
                int charactor = checkCharactor(image,r);
                if (charactor == 0){
                    A++;
                }else if (charactor == 1){
                    B++;
                }else if (charactor == 2){
                    C++;
                }
                deleteCharactor(image,r);
            }
        }
    }
    cout << A << " " << B << " " << C << endl;
    return 0;
}