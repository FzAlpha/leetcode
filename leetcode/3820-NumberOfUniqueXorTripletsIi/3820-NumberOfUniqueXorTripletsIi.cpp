// Last updated: 10/12/2026, 9:49:54 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bool has[2048] = {false};
        vector<int> unique_nums;

        for(int& i : nums){
            if(!has[i]){
                has[i] = true;
                unique_nums.push_back(i);
            }
        }

        bool pair_xors[2048] = {false};
        for(int i =0 ; i< unique_nums.size() ;i++){
            for(int j =0 ; j < unique_nums.size() ; j++){
                pair_xors[unique_nums[i] ^ unique_nums[j]]= true;
            }
        }

        bool triple_xor[2048] = {false};
        int unique_count =0;
        for(int i = 0; i < 2048; i++){
            if(pair_xors[i]){
                for(int j : unique_nums){
                    if(!triple_xor[i^j]){
                        triple_xor[i ^ j] = true;
                        unique_count++;
                    }
                }
            }
        }
        return unique_count;

    }
};