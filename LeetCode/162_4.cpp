class Solution {
public:
    vector<string> gwords;
    vector<char> gletters;
    vector<int> gscore;
    vector<int> leftover;
    int maximum_score = 0;
    bool can_make(string s) {
        int k = s.length();
        vector<int> temp = leftover;
        for (int i = 0 ; i < k ; i++) {
            if (temp[s[i] - 'a'] == 0){
                return false;
            }
            else {
                temp[s[i] - 'a'] -= 1;
            }
        }
        return true;
    }
    
    void go(int index, int max_index, int score) {
        if (index == max_index) {
            maximum_score = max(score, maximum_score);
            return;
        }
        go(index + 1, max_index, score);
        if (can_make(gwords[index])) {
            string s = gwords[index];
            int tempscore = 0;
            for (int j = 0 ; j < s.length() ; j++) {
                leftover[s[j] - 'a'] -= 1;
                tempscore += gscore[s[j] - 'a'];
            }
            go(index + 1, max_index, score + tempscore);
            for (int j = 0 ; j < s.length() ; j++) {
                leftover[s[j] - 'a'] += 1;
            }
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        gwords = words;
        gletters = letters;
        gscore = score;
        leftover.resize(26, 0);
        for (int i = 0 ; i < letters.size() ; i++) {
            leftover[letters[i] - 'a'] += 1;
        }
        int ss = words.size();
        go(0, ss, 0);
        return maximum_score;
    }
};