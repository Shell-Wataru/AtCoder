#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long H,W,N,ai,i,j;
    vector<long long> A;
    cin >> H >> W;
    cin >> N;
    for (i= 0;i<N;i++){
        cin >> ai;
        A.push_back(ai);
    }
    int **arr = new int*[H];
	// 配列の各要素でintの配列を動的生成
	for( int i=0; i<H; i++ ){
		arr[i] = new int[W];
	}

    long total = 0;
    for (i=0;i<N;i++){
        for (j= 0;j<A[i];j++){
            if ((total+j)/W % 2 == 0){
            arr[(total+j)/W][(total+j)%W]= i+1;
            }else{
                arr[(total+j)/W][W - 1 - (total+j)%W]= i+1;
            }
        }
        total += A[i];
    }

    for (i = 0;i<H;i++){
        for (j = 0;j<W;j++){
            cout << arr[i][j];
            if (j != W-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}