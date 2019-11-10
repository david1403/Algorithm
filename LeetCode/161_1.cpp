class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int a = 0, b = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == 'x') {
                a += 1;
            }
            else b += 1;
        }
        if ((a + b ) % 2 == 1) {
            return -1;
        }
        int answer = 0;
        answer += a / 2;
        answer += b / 2;
        if (a % 2 == 1){
            answer += 2;
        }
        return answer;
    }
};