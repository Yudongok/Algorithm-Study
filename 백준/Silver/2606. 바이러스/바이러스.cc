#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[100];
int cnt = 0;
int n, m;
vector<pair<int, int>> edges;
vector<int> arr;
queue<int> q;

void bfs(int n){
    q.push(n); 
    visited[n] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto &e: edges){
            int a = e.first;
            int b = e.second;

            if (a==x && !visited[b]){
                visited[b] = true;
                q.push(b);
                cnt++;
            }

            if (b==x && !visited[a]){
                visited[a] = true;
                q.push(a);
                cnt++;
            }
        }
    }
}

int main(){
    

    cin >> n;
    cin >> m;

    edges.reserve(m);
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    bfs(1);
    cout << cnt << endl;
}