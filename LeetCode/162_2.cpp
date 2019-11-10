class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ret;
        int two = 0;
        int one = 0;
        int n = colsum.size();
        for (int i = 0 ; i < n ; i++) {
            if (colsum[i] == 1)
                one += 1;
            if (colsum[i] == 2)
                two += 1;
        }
        upper -= two;
        lower -= two;
        if ((lower + upper != one) || (upper < 0) || (lower < 0)) {
            return ret;
        }
        ret.resize(2, vector<int> (n));
        for (int i = 0 ; i < n ; i++) {
            if (colsum[i] == 2) {
                ret[0][i] = 1;
                ret[1][i] = 1;
            }
            else if (colsum[i] == 1) {
                if (upper) {
                    ret[0][i] = 1;
                    ret[1][i] = 0;
                    upper -= 1;
                }
                else {
                    ret[0][i] = 0;
                    ret[1][i] = 1;
                }
            }
            else {
                ret[0][i] = 0;
                ret[1][i] = 0;
            }
        }
        return ret;
    }
};