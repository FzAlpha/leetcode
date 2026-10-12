// Last updated: 10/12/2026, 9:56:12 PM
class Solution {
public:
    bool search(vector<vector<int>>& matrix , int target , int row){
        int n = matrix[0].size();
        int st = 0 , end = n -1;
        while(st <= end){
            int mid = st + ( end - st)/2;
            if(target == matrix[row][mid]){
                return true;
            }else if (target >= matrix[row][mid]){
                st = mid +1;
            }else{
                end = mid -1;
            }
        }

        return false;
    }


    bool searchMatrix(vector<vector<int>>& ma, int target) {
        int m = ma.size() , n = ma[0].size();

        int start = 0 , end = m -1;
        while( start <= end ){
            int mid = start + ( end - start)/2;
            if( target >= ma[mid][0] && target <= ma[mid][n-1]){
                return search(ma, target , mid);
            }else if( target >= ma[mid][n-1]){
                start = mid +1;
            }else{
                end = mid -1;
            }
        }
        return false;
        
    }
};