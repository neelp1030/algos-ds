class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--) {
                int temp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = temp;
            }
        }
        
        return nums;
    }
};
