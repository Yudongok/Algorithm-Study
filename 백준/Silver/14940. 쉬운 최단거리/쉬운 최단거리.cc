#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
int cnt = 0;
int N, M;

void bfs(int x, int y, vector<vector<int>> &visited){
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    board[x][y] = 0;
    q.push({x, y});
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(!q.empty()){
        // c++에서 q.pop()은 파이썬처럼 값을 빼놓고 지우는게 아닌 바로 지우기 때문에 front()로 값을 뺴내고 지워야 한다.
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M){
            if(board[nx][ny] == 1 && visited[nx][ny] == 0){
            board[nx][ny] = board[cx][cy] + 1;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
        else
            continue;

        }
        
        }
    }
    
}



int main(){
    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int tx = -1, ty = -1;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 2){
                tx = i;
                ty = j;
                break;
            }
        } 
        if(tx != -1) break;
    }

    if(tx != -1){
        bfs(tx, ty, visited);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 1 && visited[i][j] == 0){
                cout << -1 << ' ';
            }
            else{
                cout << board[i][j] << ' ';
            }
        }
        cout << endl;
    }
    
}