// TC = O(n*logn), MC = O(logn)
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, h = n - 1;

        sort(citations.begin(), citations.end());

        while (l <= h)
        {
            int m = l + (h - l) / 2;

            if (citations[m] == (n - m))
            {
                return citations[m];
            }
            else if (citations[m] > (n - m))
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return n - l;
    }
};