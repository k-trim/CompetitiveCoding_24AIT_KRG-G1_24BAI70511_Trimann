class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size(), pref = 0;
        map[0] = -1;
        for(int i = 0; i < n; i++)
        {
            pref += nums[i];
            if(map.find(pref% k) != map.end())
            {
                if(abs(i - map[pref%k]) >= 2)
                {
                    return true;
                }
            }
            else
            {
                map[pref%k] = i;
            }
        }
        return false;
    }
};