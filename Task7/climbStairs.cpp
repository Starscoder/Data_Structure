class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 0 )
            return 0;
        if ( n < 3 )
            return n;
        int c1 = 1, c2 = 2, cn;
        for ( int i=3; i<=n; i++ ){
            cn = c1 + c2;
            c1 = c2;
            c2 = cn;
        }
        return cn;
    }
};
