class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string answer = "";
        int n = s.length();
        stack<char> st;
        int eb = 0;
        int ea = 0;
        int a = 0;
        int b = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == ')') {
                b++;
                if (st.empty()){
                    eb += 1;
                }
                else {
                    st.pop();
                }
            }
            if (s[i] == '(') {
                a++;
                st.push('(');
            }
        }
        ea = st.size();
        eb = b - eb;
        ea = a - ea;
        a = 0;
        b = 0;
        printf("%d %d\n", eb, ea);
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == ')') {
                b += 1;
                if (b > a){
                    b -= 1;
                    continue;
                }
                answer += ')';
            }
            else if (s[i] == '(') {
                a += 1;
                if (a > ea) {
                    a -= 1;
                    continue;
                }
                answer += '(';
            }
            else {
                answer += s[i];
            }
        }
        return answer;
    }
};