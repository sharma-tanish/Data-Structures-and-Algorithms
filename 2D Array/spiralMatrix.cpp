#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralMatrix(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;
        int count = 0;
        int firstRow = 0;
        int firstCol = 0;
        int lastRow = row-1;
        int lastCol = col-1;
        while(count<total) {
            //Printing first row
            for(int i=firstCol; count<total && i<=lastCol; i++) {
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            //Printing last col
            for(int i=firstRow; count<total && i<=lastRow; i++) {
                ans.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;
            //Printing last row
            for(int i=lastCol; count<total && i>=firstCol; i--) {
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            //Printing first col
            for(int i=lastRow; count<total && i>=firstRow; i--) {
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
        }
        return ans;
    }
};