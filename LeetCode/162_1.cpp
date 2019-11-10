class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> v;
        v.resize(n, vector<int> (m, 0));
        int t = indices.size();
        for (int i = 0 ; i < t; i++) {
            int f = indices[i][0];
            int t = indices[i][1];
            for (int j = 0 ; j < m ; j++) {
                v[f][j] += 1;
            }
            for (int k = 0 ; k < n ; k++) {
                v[k][t] += 1;
            }
        }
        int answer = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (v[i][j] % 2) {
                    answer += 1;
                }
            }
        }
        return answer;
    }
};