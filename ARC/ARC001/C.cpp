#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;
bool isCleared(string* chessMap){
    long long i,j,k;
    vector<pair<long long,long long>> QueenPositions;
    for (i = 0;i < 8;i++){
        for (j=0;j<8;j++){
            if (chessMap[i][j] == 'Q'){
                QueenPositions.push_back(make_pair(i,j));
            }
        }
    }

    for (k = 0;k < QueenPositions.size() - 1;k++){
        long long row1,column1,row2,column2;
        row1 = QueenPositions[k].first;
        column1 = QueenPositions[k].second;
        for (i= k+1;i < QueenPositions.size();i++){
            row2 = QueenPositions[i].first;
            column2 = QueenPositions[i].second;

            if (row1 == row2){
                return false;
            }

            if(column1 == column2){
                return false;
            }

            if (abs(row1- row2) == abs(column1- column2)){
                return false;
            }
        }
    }

    return true;
}
int main()
{
    // 整数の入力
    long long  i,j,k;
    vector<long long> noQuennRows,noQuennColumns;
    vector<pair<long long,long long>> QueenPositions;
    string* chessMap = new string[8];
    for (i = 0;i < 8;i++){
        cin >> chessMap[i];
    }
    for (i = 0;i < 8;i++){
        if (chessMap[i].find('Q') == string::npos){
            noQuennRows.push_back(i);
        }
    }

    for (i = 0;i < 8;i++){
        bool containsQueen;
        containsQueen = false;
        for (j=0;j<8;j++){
            if (chessMap[j][i] == 'Q'){
                containsQueen = true;
            }
        }

        if (!containsQueen){
            noQuennColumns.push_back(i);
        }
    }

    if (!isCleared(chessMap)){
        cout << "No Answer" << endl;
        return 0;
    }

    do {
        for(i = 0;i< 5 ;i++){
            chessMap[noQuennRows[i]][noQuennColumns[i]] = 'Q';
        }
        if (isCleared(chessMap)){
            for (i = 0;i < 8;i++){
                cout << chessMap[i] << endl;
            }
            return 0;
        }else{
            for(i = 0;i< 5 ;i++){
                chessMap[noQuennRows[i]][noQuennColumns[i]] = '.';
            }
        }
    } while( next_permutation(noQuennRows.begin(), noQuennRows.end()) );


    cout << "No Answer" << endl;
    return 0;
}