#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

long long cumCalc(long long** cumMap,long long x1,long long y1,long long x2,long long y2){
    if (x1 == -1 && y1 == -1){
        return cumMap[x2][y2];
    }else if(x1 == -1){
        return cumMap[x2][y2] - cumMap[x2][y1];
    }else if (y1 == -1){
        return cumMap[x2][y2] - cumMap[x1][y2];
    }else{
        return cumMap[x2][y2] - cumMap[x1][y2] - cumMap[x2][y1] + cumMap[x1][y1];
    }
}
int main()
{
    // 整数の入力
    long long N,M,Q,i,j;
    cin >> N >> M >> Q;
    string* S = new string[N];
    long long** cummlativeVerticalEdgeSum = new long long*[N];
    long long** cummlativeHorizontalEdgeSum = new long long*[N];
    long long** cummlativeVertexSum = new long long*[N];

    for (i=0;i< N;i++){
        cin >> S[i];
        cummlativeVerticalEdgeSum[i] = new long long[M];
        cummlativeHorizontalEdgeSum[i] = new long long[M];
        cummlativeVertexSum[i] = new long long[M];
    }

    cummlativeVerticalEdgeSum[0][0] = 0;
    cummlativeHorizontalEdgeSum[0][0] = 0;
    cummlativeVertexSum[0][0] = 0;

    if(S[0][0] == '1'){
        cummlativeVertexSum[0][0] += 1;
    }

    for (i=1;i< N;i++){
        cummlativeVerticalEdgeSum[i][0] = cummlativeVerticalEdgeSum[i-1][0];
        cummlativeHorizontalEdgeSum[i][0] = 0;
        cummlativeVertexSum[i][0] = cummlativeVertexSum[i-1][0];
        if(S[i][0] == '1'){
            cummlativeVertexSum[i][0] += 1;
        }

        // 上
        if(S[i][0] == '1' &&S[i-1][0] == '1'){
            cummlativeVerticalEdgeSum[i][0] += 1;
        }
    }

    for (i=1;i< M;i++){
        cummlativeVerticalEdgeSum[0][i] = 0;
        cummlativeHorizontalEdgeSum[0][i] = cummlativeHorizontalEdgeSum[0][i-1];
        cummlativeVertexSum[0][i] = cummlativeVertexSum[0][i-1];
        if(S[0][i] == '1'){
            cummlativeVertexSum[0][i] += 1;
        }
        // hidari
        if(S[0][i] == '1' &&S[0][i-1] == '1'){
            cummlativeHorizontalEdgeSum[0][i] += 1;
        }
    }

    for (i=1;i< N;i++){
        for (j=1;j< M;j++){
            cummlativeVertexSum[i][j] = cummlativeVertexSum[i][j-1] + cummlativeVertexSum[i-1][j] - cummlativeVertexSum[i-1][j-1];
            cummlativeVerticalEdgeSum[i][j] = cummlativeVerticalEdgeSum[i][j-1] + cummlativeVerticalEdgeSum[i-1][j] - cummlativeVerticalEdgeSum[i-1][j-1];
            cummlativeHorizontalEdgeSum[i][j] = cummlativeHorizontalEdgeSum[i][j-1] + cummlativeHorizontalEdgeSum[i-1][j] - cummlativeHorizontalEdgeSum[i-1][j-1];
            if(S[i][j] == '1'){
                cummlativeVertexSum[i][j] += 1;
            }

            // 上
            if(S[i][j] == '1' &&S[i-1][j] == '1'){
                cummlativeVerticalEdgeSum[i][j] += 1;
            }
            // 左
            if(S[i][j] == '1' &&S[i][j-1] == '1'){
                cummlativeHorizontalEdgeSum[i][j] += 1;
            }
        }
    }

    long long x1,y1,x2,y2;

    for (i =0;i< Q;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << cumCalc(cummlativeVertexSum,x1 - 2,y1 - 2,x2 - 1,y2 - 1)
                - cumCalc(cummlativeVerticalEdgeSum,x1 - 1,y1 - 2,x2 - 1,y2 - 1)
                - cumCalc(cummlativeHorizontalEdgeSum,x1 - 2,y1 - 1,x2 - 1,y2 - 1) << endl;
    }
    return 0;
}