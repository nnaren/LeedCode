// dfs 深度优先搜索 = backtrack 回溯
// x & -x           除最低位，其他1都变成0；     x最低位的1；
// x & (x - 1)      只把最低位1变成0；

using namespace std;
class Solution
{
private:
    int nums =0 ;

public:
    int totalNQueens(int n)
    {
        dfs(n, 0, 0, 0 , 0);
        return nums;
    }
    void dfs(int n, int row, int col, int ld, int rd)
    {
        if(row>= n) 
        { 
            nums++; 
            return;
        }
        int bits = ~(col | ld | rd) & ((1<<n) -1);
        while (bits>0)
        {
            int pick = bits & (-bits) ;
            dfs(n, row+1, (col | pick), (ld | pick) << 1, (rd | pick) >> 1);
            bits &= (bits-1);
        }
        
    }
};

