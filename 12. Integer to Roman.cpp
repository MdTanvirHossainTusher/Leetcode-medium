// https://youtu.be/ohBNdSJyLh8?si=7_mSltOfmHeL_4Hj
// TC = MC: O(1)
#define pii pair<string, int>
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pii> symbols = {
            {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        string res = "";

        for (int i = symbols.size() - 1; i >= 0; i--)
        {
            string symbol = symbols[i].first;
            int value = symbols[i].second;

            int occuranceOfSymbol = num / value;
            num = num % value;

            while (occuranceOfSymbol--)
            {
                res += symbol;
            }
        }
        return res;
    }
};