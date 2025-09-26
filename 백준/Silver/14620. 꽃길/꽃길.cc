#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n;

int board[11][11] = { 0 };
vector<int>v;
vector<int>comb;
int minSize = 999999;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

//조합 완전 탐색
void combi(int start) {
	if (comb.size() == 3) {
		set<pair<int, int>> s;
        //면적 set에 넣기
		for (int i : comb) {
			int r = i / n;
			int c = i % n;
			s.insert({ r, c });
			for (int i = 0; i < 4; i++) {
				int Nr = r + dy[i];
				int Nc = c + dx[i];
				s.insert({ Nr, Nc });
			}
			
		}
		if (s.size() == 15) {  //중복값 없이 들어가면 총 사이즈가 15가 되어야함
			int num = 0;
			for (auto p = s.begin(); p != s.end(); p++) {
				num += board[(*p).first][(*p).second];

			}
			minSize = min(minSize, num);  //최솟값 갱신
		}
		return;
	}
	for (int i = start; i < v.size(); i++) {
		comb.push_back(v[i]);
		combi(i + 1);
		comb.pop_back();
	}
}

int main() {
	int cnt = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
        //가장자리에서는 어짜피 꽃이 피지 못함, 가장자리가 아닌 부분만 v배열에 모두 넣음.
			if (i != 0 && i != n - 1 && j != 0 && j != n - 1) {
				v.push_back(cnt);
			}
			cnt++;
		}
	}
	combi(0);
	cout << minSize;
}