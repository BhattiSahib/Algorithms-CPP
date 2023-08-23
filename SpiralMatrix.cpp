/******************************************************************************

This task prints the 2D-matrix(vector of vectors) in spiral order moving from 
outward boundary to center starting from (0,0), The execution time for this is 
very less ~~ 0ms and memory utilized is 6.95MB.               

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);
int main()
{
    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};
    vector<int> result = spiralOrder(matrix);
    for(auto i:result)
    {
        cout<<i<<" ";
    }

    return 0;
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        
        size_t n_rows = matrix.size();
        size_t n_cols = matrix[0].size();
        size_t num_elements = n_rows*n_cols;
        
        int x, y;
        int right = 0, down = 0, left = 0, up = 0;
        int row_start = 0, col_start = 0;
        int col_end = (n_cols - 1) - down, row_end = (n_rows - 1) - left;
        enum print_dir{row_right = 1, column_down, row_left, column_up};
        print_dir current_direction = row_right;
        while(num_elements > 0)
        {
            switch(current_direction)
            {
                case 1:
                    {
                        x = row_start;
                        for(y = col_start; y <= col_end; y++)
                        {
                            answer.push_back(matrix[x][y]);
                            
                            num_elements--;
                            col_start = y;
                        }
                        right++;

                        
                        
                        row_start = x + 1;
                        row_end = (n_rows-1) - left; 

                        current_direction = column_down;
                        break;
                    }
                case 2:
                    {
                        y = col_start;
                        for(x = row_start; x <= row_end; x++)
                        {
                            answer.push_back(matrix[x][y]);
                            
                            num_elements--;
                            row_start = x;
                        }
                        down++;

                        

                        col_start = y - 1;
                        col_end = up; //proposed (n_cols-col_done-1)


                        current_direction = row_left;
                        break;
                    }
                case 3:
                    {
                        x = row_start;
                        for(y = col_start; y >= col_end ; y--)
                        {
                            answer.push_back(matrix[x][y]);
                            
                            num_elements--;
                            col_start = y;
                        }
                        left++;

                        

                        row_start = x - 1;
                        row_end = right;

                        current_direction = column_up;
                        break;
                    }
                case 4:
                    {
                        y = col_start;
                        for(x = row_start; x >= row_end ; x--)
                        {
                            answer.push_back(matrix[x][y]);
                            
                            num_elements--;
                            row_start = x;
                        }
                        up++;

                        

                        col_start = y + 1;
                        col_end = (n_cols - 1) - down;

                        current_direction = row_right;
                        break;

                    }
                default:
                    {
                        answer.push_back(0);
                        break;
                    }

            }
            
        }
        
        return answer;
}



// Test-Case
// input matrix = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25],[26,27,28,29,30]]
// output vector = 1 2 3 4 5 10 15 20 25 30 29 28 27 26 21 16 11 6 7 8 9 14 19 24 23 22 17 12 13 18


// Test-Case
// input matrix = [[1,2,3,4,5,6 7,8],[9,10,11,12,13,14,15,16],[17,18,19,20,21,22,23,24],[25,26,27,28,29,30,31,32],[33,34,35,36,37,38,39,40],[41,42,43,44,45,46,47,48],[49,50,51,52,53,54,55,56]]
// output vector = 


