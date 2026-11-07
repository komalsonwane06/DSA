class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        if(n>0) mergesort(arr, 0, n-1, count);
        return count;
    }

    void mergesort(vector<pair<int, int>>& arr, int low, int high, vector<int>& count){
        if(low >= high) return;
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid, count);
        mergesort(arr, mid + 1, high, count);
        merge(arr, low, mid, high, count);
    }

    void merge(vector<pair<int, int>> &arr, int low, int mid, int high, vector<int>& count){
        int left = low;
        int right = mid + 1;
        vector<pair<int, int>> temp;
        int right_count = 0;

        while(left <= mid && right <= high){
            if(arr[left].first <= arr[right].first){
                count[arr[left].second] += right_count;
                temp.push_back(arr[left++]);
            } else {
                right_count++;
                temp.push_back(arr[right++]);
            }
        }

        while(left <= mid) {
            count[arr[left].second] += right_count;
            temp.push_back(arr[left++]);
        }
        
        while(right <= high) {
            temp.push_back(arr[right++]);
        }

        for(int i = 0; i < temp.size(); i++){
            arr[low + i] = temp[i];
        }
    }
};
