class Solution {
public:
    int can(vector<int>& piles, int h, int mid)
    {
        int curr = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            curr += piles[i] / mid;
            if(piles[i] % mid != 0) 
            {
                curr++;
            }

        }
        return curr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
         int lb = 1, ub = *max_element(piles.begin(), piles.end());

        while(lb < ub)
        {
            int mid = (lb + ub) / 2;
            if(can(piles, h, mid))
            {
                ub = mid;
            }
            else
            {
                lb = mid + 1;
            }
        }
        return lb;
    }
};