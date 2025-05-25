class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        int maxSum = INT_MIN;
        int posSum = 0;

        for(int i=0; i<size; i++){
            posSum += nums[i];
            maxSum = max(posSum,maxSum);
            if(posSum < 0){
                posSum=0;
            }
            
        }
        return maxSum;
    }
};