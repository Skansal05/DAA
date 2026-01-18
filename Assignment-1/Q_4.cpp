#include<iostream>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}
int main(){
    vector<int> nums = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout<<"Maximum SubArray sum is: "<<maxSubArray(nums)<<endl;
    return 0;
}