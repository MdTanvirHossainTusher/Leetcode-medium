// TC = MC: O(n)
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /**
        i = 0 to 6, k = 3 ==>
            out[0+3] = out[3 % 7] = out[3] = nums[0] = 1
            out[1+3] = out[4 % 7] = out[4] = nums[1] = 2
            out[2+3] = out[5 % 7] = out[5] = nums[2] = 3
            out[3+3] = out[6 % 7] = out[6] = nums[3] = 4
            out[4+3] = out[7 % 7] = out[0] = nums[4] = 5
            out[5+3] = out[8 % 7] = out[1] = nums[5] = 6
            out[6+3] = out[9 % 7] = out[2] = nums[6] = 7

        */
        int n = nums.size();
        vector<int> output(n);

        for (int i = 0; i < n; i++)
        {
            int newIdx = (i + k) % n;
            output[newIdx] = nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = output[i];
        }
        return;
    }
};

// https://youtu.be/BHr381Guz3Y?si=ZByy3tO_jfD8WSoh
// TC = O(n), MC = O(1)
class Solution
{
public:
    vector<int> reverseArray(int l, int r, vector<int> &nums)
    {
        while (l <= r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        return nums;
    }
    void rotate(vector<int> &nums, int k)
    {
        /**
        in=> [1,2,3,4,5,6,7]
        rev=>[[7,6,5],[4,3,2,1]] => now reverse first `k` portion, and last portion
        res=>[5,6,7,1,2,3,4] => final answer

        k = k % n korar reason=>
        k == n hoile array same thkbe
        k < n hoile k-th bar shift hbe
        k > n hoile k%n bar shift hbe.

        eg: k=4, n=4 => [1,2,3,4] after rotating k-th time => [1,2,3,4]
        eg: k=2, n=4 => [1,2,3,4] after rotating k-th time => [3,4,1,2]
        eg: k=5, n=4 => [1,2,3,4] after rotating k=4 time => [1,2,3,4] =>k=5 time=> [4,1,2,3] ja ekbar rotate korar soman. r k=1 pabo (k%n) = (5%4=1) kore
        */
        int n = nums.size();
        k = k % n;
        nums = reverseArray(0, n - 1, nums);
        nums = reverseArray(0, k - 1, nums);
        nums = reverseArray(k, n - 1, nums);
    }
};