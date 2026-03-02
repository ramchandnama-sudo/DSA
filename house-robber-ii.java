class Solution {
    public int rob(int[] nums) 
    {
        if(nums.length<2)return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);

        int leftSkip[]=new int[nums.length-1];
        int rightSkip[]=new int[nums.length-1];

        for(int i=0;i<nums.length-1;i++)
        {
            leftSkip[i]=nums[i+1];
            rightSkip[i]=nums[i];
        }

        int leftSkipMax=houseRobber(leftSkip,leftSkip.length);
        int rightSkipMax=houseRobber(rightSkip,rightSkip.length);

        return Math.max(leftSkipMax,rightSkipMax);
    }

    private int houseRobber(int nums[],int n)
    {
        int dp[]=new int[n];
        dp[0]=nums[0];
        dp[1]=Math.max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp[n-1];
    }
}