class Solution {
public:
    int gcd(int x, int y) {
        if ( y == 0 ) return x;
        return gcd(y, x % y);
    }
    bool isGoodArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1) {
            return nums[0] == 1;
        }
        int n = nums.size();
        int answer = gcd(nums[0], nums[1]);
        for (int i = 2 ; i < n ; i++) {
            answer = gcd(answer, nums[i]);
        }
        return answer == 1;
    }
};