#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    int N;
    while (T--) {
        cin >> N;
        vector<vector<int>> graph(N);
        int root = -1;
        for (int i = 0; i < N; ++i) {
            int input;
            cin >> input;
            if (input == -1) {
                root = i;
            } 
            else {
                graph[i].push_back(input);
                graph[input].push_back(i);
            }
        }
        int target;
        cin >> target;
        vector<bool> visited(N, false);

        queue<int> q;
        q.push(root);

        int answer = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == target) continue;

            visited[cur] = true;
            int cnt = 0;

            for (int next : graph[cur]) {
                if (visited[next]) continue;

                if (next == target) continue;

                q.push(next);
                cnt++;
            }

            if (cnt == 0) {
                answer++;
        }
        }
        cout << answer << '\n';
    }

    return 0;
}