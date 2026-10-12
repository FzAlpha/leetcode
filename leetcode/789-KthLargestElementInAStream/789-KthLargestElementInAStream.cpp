// Last updated: 10/12/2026, 9:53:35 PM
class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> min;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i : nums){
            add(i);
        }
    }
    
    int add(int val) {
        min.push(val);

        if(min.size() > k){
            min.pop();
        }
        return min.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */