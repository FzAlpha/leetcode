// Last updated: 10/12/2026, 9:53:33 PM
class Solution {
public:
    int binSearch(vector<int> & arr , int tar , int st , int end){
        if(st<=end){
            int mid = st + (end - st)/2;

            if(arr[mid] == tar){
                return mid;
            }else if(arr[mid] <= tar){
                return binSearch(arr , tar , mid+1 , end);
            }else{
                return binSearch(arr , tar , st , mid -1);
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int tar) {
        
         return binSearch(arr , tar , 0 , arr.size() -1);
    }
};