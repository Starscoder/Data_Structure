class Solution {
public:
    int climbStairs(int n) {
         if(n==1||n==2) return n;
        int pre=1;
        int now=2;
        for(int i=3;i<=n;i++){
            int temp=now;
            now+=pre;
            pre=temp;
        }
        return now;
    }
};
