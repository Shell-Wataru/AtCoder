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

using namespace std;
struct BetweenInfo{
    long long crossImportance;
    long long circleImportance;
    long long width;
};

long long getBetWeenCrossImportance(string S, long long i, long long j){
    long long importance = 0;
    for (;j < S.length();j++){
        if (S[j] == 'x'){
            importance++;
        }
        if (S[j] == 'o'){
            break;
        }
    }

    return importance;

}

long long getBetWeenCircleImportance(string S, long long i, long long j){
    long long importance = 0;
    for (;i>=0;i--){
        if (S[i] == 'o'){
            importance++;
        }
        if (S[i] == 'x'){
            break;
        }
    }

    return importance;

}


long long circleMoveCapacity(string S, long long i){
    i--;
    long long space = 0;
    long long capacity = 0;
    for (;i>=0;i--){

        if (S[i] == '.'){
            space++;
        }else if (S[i] == 'o'){
            capacity += space;
        } else if (S[i] == 'x'){
            break;
        }
    }
    return capacity;
}

long long crossMoveCapacity(string S, long long i){
    i++;
    long long space = 0;
    long long capacity = 0;
    for (;i<S.length();i++){
        if (S[i] == '.'){
            space++;
        }else if (S[i] == 'x'){
            capacity += space;
        } else if (S[i] == 'o'){
            break;
        }
    }
    return capacity;
}

int main()
{
    // 整数の入力
    long long H,W,i,j,minCircle,minCross,crossTotal,circleTotal,lastCharactorIndex;
    priority_queue<BetweenInfo,vector<BetweenInfo>, function<bool(BetweenInfo,BetweenInfo)>>q(
        [](BetweenInfo a,BetweenInfo b){return a.circleImportance + a.crossImportance <b.circleImportance + b.crossImportance;}
    );
    crossTotal = 0;
    circleTotal = 0;
    minCircle = -1;
    minCross = - 1;
    char lastCharactor;
    string *S;
    cin >> H >> W;
    S = new string[H];
    for (i = 0;i<H;i++){
        cin >> S[i];
    }

    for (i = 0;i<H;i++){
        lastCharactor = '*';
        for (j =0;j<W;j++){
            if (S[i][j] == 'o'){
                lastCharactor = S[i][j];
                lastCharactorIndex = j;
            }else if (S[i][j] == 'x'){
                if (lastCharactor == 'o'){
                    BetweenInfo BI;
                    BI.crossImportance = getBetWeenCrossImportance(S[i],lastCharactorIndex,j);
                    BI.circleImportance = getBetWeenCircleImportance(S[i],lastCharactorIndex,j);
                    BI.width = max(0LL,j - lastCharactorIndex - 2);
                    q.push(BI);
                    circleTotal += circleMoveCapacity(S[i],lastCharactorIndex);
                    crossTotal += crossMoveCapacity(S[i],j);
                }else if (lastCharactor == '*'){
                    if (minCross == -1 || j < minCross){
                        minCross = j;
                    }
                }
                lastCharactor = S[i][j];
                lastCharactorIndex = j;
            }
        }

        if (lastCharactor == 'o'){
            if (minCircle == -1 || W - lastCharactorIndex - 1 < minCircle){
                minCircle = W - lastCharactorIndex - 1;
            }
        }
    }

    bool circleFirst = true;
    while(!q.empty()) {
        //cout << q.top().circleImportance <<' ' << q.top().circleImportance << ' ' << q.top().width << endl;
        if (circleFirst){
            circleTotal += q.top().circleImportance * ((q.top().width + 2 - 1)/2);
            crossTotal += q.top().crossImportance * (q.top().width /2);
        }else{
            circleTotal += q.top().circleImportance * (q.top().width/2);
            crossTotal += q.top().crossImportance * ((q.top().width + 2 - 1)/2);
        }

        if (q.top().width % 2 != 0){
            circleFirst = !circleFirst;
        }
        q.pop();
    }

    //cout << crossTotal<< endl;
    //cout << circleTotal << endl;
    //cout << minCircle << endl;
    //cout << minCross << endl;

    if (minCircle == -1 && minCross == -1){
        if (crossTotal < circleTotal){
            cout << 'o' <<endl;
        }else{
            cout << 'x' <<endl;
        }
    }else{
        if(minCircle == -1){
            cout << 'x' <<endl;
        }else if (minCross == -1){
            cout << 'o' <<endl;
        }else if(minCross < minCircle){
            cout << 'x' <<endl;
        }else{
            cout << 'o' <<endl;
        }
    }
    return 0;
}