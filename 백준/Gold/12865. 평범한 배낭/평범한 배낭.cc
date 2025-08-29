#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (b < a) ? a : b;
}

int main() {
    int N, K;  // N: 물품 수, K: 버틸 수 있는 무게
    cin >> N >> K;

    vector<int> W(N + 1); // W[i]: i번째 물건 무게
    vector<int> V(N + 1); // V[i]: i번째 물건 가치

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    // DP[i][j] = 0 ~ i번째 물건까지 고려, 배낭 용량 j일 때 최대 가치
    vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j < W[i]) {
                DP[i][j] = DP[i - 1][j];  // 담지 못함
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);  // 담거나 안 담거나
            }
        }
    }

    cout << DP[N][K] << endl;

    return 0;
}
