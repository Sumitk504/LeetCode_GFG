class Solution {
public:
    void insert(vector<int>& nums, int val){
        if(nums.size() == 0 || nums[nums.size() - 1] <= val){
            nums.push_back(val);
            return;
        }
        int temp = nums[nums.size()-1];
        nums.pop_back();
        insert(nums, val);
        nums.push_back(temp);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return nums;
        int val = nums[size-1];
        nums.pop_back();
        sort(nums.begin(), nums.end());
        
        insert(nums, val);
        return nums;
    }
};