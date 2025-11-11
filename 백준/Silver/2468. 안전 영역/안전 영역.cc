#include <iostream>

using namespace std;

int n, cnt, water, ans;
int map[101][101];
int map_tmp[101][101];
bool visited[101][101];

void dfs(int y, int x){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny > n-1 || nx < 0 || nx > n-1){
            continue;
        }

        if(map_tmp[ny][nx] > 0 && visited[ny][nx] == false){
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

// reset함수가 없으면 map의 물값이 계속해서 마이너스 되므로 에러가 발생.
void reset(){
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map_tmp[i][j] = map[i][j];
            visited[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            map_tmp[i][j] = map[i][j];
        }
    }

    water = 0;
    cnt = 0;
    ans = 0;

    while(true){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                map_tmp[i][j] = map_tmp[i][j] - water;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // 땅 판정 조건에서 !=은 음수도 땅 취급하게 됨.
                if(map_tmp[i][j] > 0 && visited[i][j] == false){
                    visited[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if(ans < cnt)
            ans = cnt;
        if(cnt == 0)
            break;
        water++;
        reset();
    }

    cout << ans;

}