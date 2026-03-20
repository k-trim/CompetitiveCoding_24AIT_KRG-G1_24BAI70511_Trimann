class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), l = k - 1;
        unordered_map<int, int> map;
        long long sum = 0, ans = 0;

        for(int i = 0; i < k - 1; i++)
        {
            map[nums[i]]++;
            sum += nums[i];
        }

        while(l < n)
        {
            sum += nums[l];
            map[nums[l]]++;
            cout<<sum<<endl;
            if(map.size() == k) ans = max(ans, sum);
            map[nums[l - k + 1]]--;
            sum -= nums[l - k + 1];
            if(map[nums[l -k + 1]] == 0)
            {
                map.erase(nums[l -k + 1]);
            }

            l++;
        }

        return ans;
    }
};