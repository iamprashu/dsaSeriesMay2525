class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //step 1 using optimal approach
        bool isFirstRowInfected = false;
        bool isFirstColInfected = false;

        int row = matrix.size();
        int col = matrix[0].size();

        // checking if the 0th roe and col are infected or not
        for(int i=0; i<col; i++) {
            if ( matrix[0][i] == 0 ) { 
                isFirstRowInfected=true;
                break;
            }
        }
        
        for(int i=0; i<row; i++){
            if(matrix[i][0] == 0){
                isFirstColInfected = true;
                break;
            }
        }

        //now marking the 0th row and 0th col of the found match

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //at last marking 0th row and 0th col if they are infected

        if(isFirstColInfected){
            for(int i=0; i<row; i++){
                matrix[i][0] = 0;
            }
        }

        if(isFirstRowInfected){
            for(int i=0; i<col; i++){
                matrix[0][i] = 0;
            }
        }
        
    }
};