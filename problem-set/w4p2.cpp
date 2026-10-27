#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int X, N;
        cin >> X >> N;

        int a, c;
        vector<int> A, C;
        vector<int> dp(X+1);
        for (int i = 0; i < N; ++i) {
            cin >> a >> c;
            A.push_back(a);
            C.push_back(c);
        }

        for (int i = 0; i < N; ++i) {
            for (int x = X; x >= C[i]; --x) {
                dp[x] = max(dp[x], dp[x - C[i]] + A[i]);
            }
        }

        cout << dp[X] << '\n';
    }

    return 0;
}