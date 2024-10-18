// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        queue<pair<pair<int,int>,int>> q ;
        vector<vector<int>>vis(m , vector<int>(n,0)) ;

        int count = 0 ;

        int t_max = 0 ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0}) ;
                    vis[i][j] = 2 ;
                }
                else
                {
                    vis[i][j] = 0 ;
                }

                if(grid[i][j] == 1)
                count++ ;
            }
        }

        int row[] = {-1,0,1,0} ;
        int col[] = {0,1,0,-1} ;

        int count_r = 0 ;

        while(!q.empty())
        {
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int t = q.front().second ;

            t_max= max(t_max , t) ;

            q.pop() ;

            for(int i = 0 ; i < 4 ; ++i)
            {
                int n_row = r + row[i] ;
                int n_col = c + col[i] ;

                if(n_row >= 0 && n_row < m && n_col >= 0 && n_col < n && grid[n_row][n_col] == 1 && vis[n_row][n_col] == 0)
                {
                    q.push({{n_row,n_col},t+1}) ;
                    vis[n_row][n_col] = 2 ;
                    count_r++ ;
                }
            }
        }
        if(count != count_r)
        return -1 ;

        return t_max ;

    }
};
