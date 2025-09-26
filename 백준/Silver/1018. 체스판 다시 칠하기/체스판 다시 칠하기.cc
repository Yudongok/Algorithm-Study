#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

//미리 정답지를 만들어 놓음
string WB[8] ={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string board[50];

//행과 열의 개수가 8개씩 한줄씩 이동하면서 카운팅함 -> 무식하게 모든 경우의수를 구하므로 브루트포스임.
int WB_cnt(int x, int y){
    int cnt = 0;
    for(int i = 0; i<8; i++){       //행 하니씩 즉, 아래로 한줄씩 이동
        for(int j=0; j<8; j++){     //열 하나씩 즉, 오른쪽으로 한줄씩 이동
            if(board[x+i][y+j] != WB[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int BW_cnt(int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[x+i][y+j] != BW[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int min_val=12345;
    pair<int, int> p1;
    cin >> p1.first >> p1.second;

    // 한줄씩 입력되는거임
    for(int i=0; i<p1.first; i++){
        cin >> board[i];
    }

    for(int i=0; i+8<=p1.first; i++){
        for(int j=0; j+8<=p1.second; j++){
            int tmp;
            tmp = min(WB_cnt(i, j), BW_cnt(i, j));
            if(tmp < min_val){
                min_val = tmp;
            }
        }
    }
    cout << min_val;
    return 0;
}