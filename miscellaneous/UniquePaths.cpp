class Solution {
public:
    //solved using combination
    
    //both long long & double are being accepted
    //even changed the return type to ll and double --> it got accepted
    //however factorial call as such individually throws runtime error as it doesn't fit into    long long data type also
        long long uniquePaths(int m, int n) {
        int var=(m-1)+(n-1);
        int max_one=max(m-1,n-1);
        int min_one=min(m-1,n-1);
        long long  pre=1;
        int y=1;
        for(int x=m+n-2;x>max_one;--x)
        {
            if(y==(min_one+1))
            break;
            pre=(pre*x)/y++;

        }
        return pre;
    }
};