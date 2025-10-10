#include <iostream>

// 전역의 int배열은 프로그램 시작 시 0으로 자동 초기화가 된다.
// 여기서 store배열은 cache같은 역할을 한다.
int store[21][21][21];

int solve(int a, int b, int c);

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, c;
	while (true)
	{
		std::cin >> a >> b >> c;
		
		if (a == -1 && b == -1 && c == -1)
			break;

		std::cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << '\n';
	}
}

int solve(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return solve(20, 20, 20);

    // 만약 store(즉, cache)에 저장된 값이 있으면 계산하지 않고 바로 값을 가져온다.
	if (store[a][b][c])
		return store[a][b][c];

	if (a < b && b < c)
	{
        // 점화식 + 계산된 값은 store에 저장한다.
		store[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
		return store[a][b][c];
	}

    // 점화식 + 계산된 값은 store에 저장한다.
	store[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
	return store[a][b][c];
}