#include<bits/stdc++.h>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<pair<int, int>>zeros;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    zeros.push_back({i, j});
                }
            }
        }
        if(zeros.size() == row*col) 
            return;
        for(auto it: zeros){
            for(int i = 0; i<col; i++)
                matrix[it.first][i] = 0;
            for(int j = 0; j<row; j++)
                matrix[j][it.second] = 0;
        }
    }
};