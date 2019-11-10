class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int answer = 0;
        vector<int> v;
        int index = 0;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            if (nums[i] % 2 == 0) {
                index += 1;
            }
            else {
                v.push_back(index);
                index = 0;
            }
        }
        v.push_back(index);
        for (int i = 0 ; i < n ; i++) {
            int next = i+k;
            if (next >= v.size())
                break;
            answer += (v[i] + 1)*(v[next] + 1);
            
        }
        return answer;
    }
};