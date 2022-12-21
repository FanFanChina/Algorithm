class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int t = -1;
        for(int i = 1; i < nums.size(); i ++ ) 
            if(nums[i] < nums[i - 1]) {
                t = i;
                break;
            }
        if (t == -1) return nums[0];
        return nums[0] < nums[t] ? nums[0] : nums[t];
    }
};

// 旋转数组的最小数字
// https://www.acwing.com/problem/content/20/