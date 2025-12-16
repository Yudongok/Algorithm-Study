#include <iostream>
#include <vector>
#include <queue> 

#define INF 1e9 // 무한대 값 설정

using namespace std;

// 간선 정보를 담을 구조체 (목적지, 가중치)
struct Edge {
    int to;
    int weight;
    
    // 생성자 (emplace_back용)
    Edge(int to, int weight) : to(to), weight(weight) {}
};

int main() {
    // 입출력 속도 향상 (백준 필수)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    int start;

    cin >> v >> e >> start;

    // 1. 인접 리스트 사용 (메모리 낭비 방지 및 속도 향상)
    // adj[u] 에는 {v, w} 형태의 데이터들이 들어감
    vector<vector<Edge>> adj(v + 1);

    // 2. 거리 저장 배열 (무한대로 초기화)
    vector<int> dist(v + 1, INF);

    for (int i = 0; i < e; i++) {
        int u, v2, w;
        cin >> u >> v2 >> w;
        // u에서 v2로 가는 가중치 w인 간선
        adj[u].emplace_back(v2, w);
    }

    // 3. 우선순위 큐 사용 (최소 힙: 비용이 작은 것이 먼저 나옴)
    // pair<int, int> : {비용, 정점번호}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작점 초기화
    dist[start] = 0;
    pq.push({0, start}); // 비용 0, 시작점 start

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // 중요: 이미 처리된 경로보다 더 긴 경로가 큐에서 나왔다면 무시 (Time Check)
        if (dist[current_node] < current_cost) continue;

        // 현재 정점(current_node)과 연결된 모든 주변 정점 확인
        for (const auto& edge : adj[current_node]) {
            int next_node = edge.to;
            int next_cost = current_cost + edge.weight;

            // 더 짧은 경로를 발견했다면 갱신
            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF" << "\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}