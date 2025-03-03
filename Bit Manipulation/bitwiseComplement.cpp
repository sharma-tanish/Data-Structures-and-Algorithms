class Solution {
public:
    int bitwiseComplement(int n) {
        int temp = n;
        int mask = 0;
        if(n == 0) {
            return 1;
        }
        while(temp != 0) {
            temp = temp >> 1;
            mask = mask << 1;
            mask = mask | 1;
        }
        int ans = (~n) & mask;
        return ans;
    }
};