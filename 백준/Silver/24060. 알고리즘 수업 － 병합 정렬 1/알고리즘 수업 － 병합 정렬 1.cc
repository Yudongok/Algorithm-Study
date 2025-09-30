#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#include <vector>

using namespace std;

void merge_sort(int* A, int p, int r, int K);
void merge(int* A, int p, int q, int r, int K);
int inputcnt = 0;
// (선택) 조기 종료용 플래그
bool done = false;

void merge_sort(int* A, int p, int r, int K){
    if (p < r && !done) {                  // 조기 종료 고려
        int q = (p + r) / 2;
        merge_sort(A, p, q, K);
        merge_sort(A, q + 1, r, K);
        merge(A, p, q, r, K);
    }
}

void merge(int* A, int p, int q, int r, int K){
    vector<int> tmp(r-p+2);   //tmp배열은 인덱스 1부터 사용
    int i = p, j = q+1, t = 1;
    while(i<=q && j<=r){
        if(A[i]<=A[j]){
            tmp[t++] = A[i++];
        }else{
            tmp[t++] = A[j++];
        }
    }
    while(i<=q){
        tmp[t++] = A[i++];
    }
    while(j<=r){
        tmp[t++] = A[j++];
    }
    i = p;
    t = 1;
    while (i <= r) {
        A[i++] = tmp[t++];
        if (++inputcnt == K) {
            cout << A[i - 1];
            done = true;                   // (선택) 이후 작업 생략
        }
        if (done) break;                   // (선택) 현재 병합도 조기 종료
    }
}

int main(){
    fastio;
    int N, K;
    cin >> N >> K;
    int* A = new int[N];
    A = new int[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    merge_sort(A, 0, N-1, K);
    //만약 찾으려는 값보다 카운팅된 값이 더 커질경우 -1 출력
    if(inputcnt<K){
        cout << -1;
    }

    return 0;
}