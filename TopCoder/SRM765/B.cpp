#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Tunnel {
	public:
    void move(string &level,vector<int> &row,int i,int stroke,int rate){
        if (level[i] == '#'){
            row[i] = -1;
        }else if (row[i] == -1 || stroke < row[i] ){
            row[i] = stroke;
            if (rate > 0){
                move(level,row,i+1,stroke+1,rate-1);
                move(level,row,i-1,stroke+1,rate-1);
            }
        }
    }
	int  minKeystrokes (vector<string> M,int rate) {
        vector<vector<int>> min_strokes;
        for(int i = 0;i< M.size();i++){
            vector<int> row(M[i].size(),-1);
            if (i == 0){
                for (int j = 0;j < M[i].size();j++){
                    if(M[i][j] == 'v'){
                        move(M[i],row,j,0,rate);
                    }
                }
            }else{
                for (int j = 0;j < M[i].size();j++){
                    if (min_strokes[i-1][j] >= 0){
                        move(M[i],row,j,min_strokes[i-1][j],rate);
                    }
                }
            }
            min_strokes.push_back(row);
        }

        int min_stroke = -1;
        for(int i = 0;i<M[0].size();i++){
            int stroke = min_strokes[M.size()-1][i];
            if (stroke != -1 && (min_stroke == -1 || stroke < min_stroke)){
                min_stroke = stroke;
            }
        }
        // for(int i = 0;i<M.size();i++){
        //     for(int j = 0;j< M[0].size();j++){
        //         cout << min_strokes[i][j] << ",";
        //     }
        //     cout << endl;
        // }
        return min_stroke;
	}
};

int main(){
    Tunnel t;
    vector<string> m{
        "##..v..##",
        "###.....#",
        "#####...#",
        "####...##",
        "###..####",
        "#.......#",
        "#...#####"
    };
    int rate = 2;
    // vector<string> m{"#...v.#"};
    // int rate = 47;

    int ans = t.minKeystrokes(m,rate);
    cout << ans << endl;
    return 0;
}