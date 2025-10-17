#include <iostream>
#include <string>
#include <vector>
using namespace std;

void divide(string& s, int l, int r) {
    int len = r - l;
    if (len < 3) return;
    int third = len / 3;
    for (int i = l + third; i < l + 2 * third; ++i) s[i] = ' ';
    divide(s, l, l + third);
    divide(s, r - third, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> out;  // 결과 모아두는 버퍼
    int N;
    while (cin >> N) {
        long long len = 1;
        for (int i = 0; i < N; ++i) len *= 3;
        string s((size_t)len, '-');
        divide(s, 0, (int)s.size());
        out.push_back(std::move(s));
    }

    // 한 번에 출력
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i];
        if (i + 1 < out.size()) cout << '\n';
    }
    return 0;
}
