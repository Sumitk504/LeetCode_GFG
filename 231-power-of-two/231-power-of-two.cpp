class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        return  n > 0 && (n == 1 || (n%2==0 && isPowerOfTwo(n/2)));
    }
};