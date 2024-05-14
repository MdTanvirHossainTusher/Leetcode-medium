// TC = O(log10(n)), MC = O(1)
class Solution {
public:
    int reverse(int x) {
        int MAX = INT_MAX; // 2147483647
        int MIN = INT_MIN; // -2147483648
        int maxWithoutLastDigit = MAX / 10;
        int minWithoutLastDigit = MIN / 10;
        int lastDigitOfMax = MAX % 10;
        int lastDigitOfMin = MIN % 10;

        // cout << (-1%10) << endl; => -1

        int ans = 0;
        while(x) {
            int rem = x % 10;
            x /= 10;

            if (ans > maxWithoutLastDigit || (ans == maxWithoutLastDigit && rem >= lastDigitOfMax)) {
                return 0;
            }
            if (ans < minWithoutLastDigit || (ans == minWithoutLastDigit && rem <= lastDigitOfMin)) {
                return 0;
            }
            ans = (ans * 10) + rem;
        }
        return ans;
    }
};


// https://youtu.be/HAgLH58IgJQ?si=nz45qgBe0hGUnRXj