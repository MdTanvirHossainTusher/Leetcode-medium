// TC = O(n), MC = O(1)
class Solution
{
public:
    // difficult implementation prb
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = 0;

        while (r < n)
        {
            int cnt = 1;
            while (r + 1 < n && nums[r] == nums[r + 1])
            {
                r++;
                cnt++;
            }
            for (int i = 0; i < min(2, cnt); i++)
            {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};