// TC = O(n), MC = O(1)
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string res = "";
        int n = s.size();
        if (numRows == 1)
            return s;

        for (int r = 0; r < numRows; r++)
        {
            int step = (numRows - 1) * 2;
            for (int i = r; i < n; i = i + step)
            {
                res += s[i];

                int middleCharIdx = i + step - 2 * r;
                if (r > 0 && r < numRows - 1 && middleCharIdx < n)
                {
                    res += s[middleCharIdx];
                }
            }
        }
        return res;
    }
};