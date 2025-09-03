class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        int pivot;
        int mid;
        while(start<end){
            mid=(start+end)/2;
            if(arr[mid]>arr[end]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        pivot=start;
        start=0;
        end=n-1;
        if(target>=arr[pivot] && target<=arr[n-1]){
            start=pivot;
        }
        else{
            end=pivot-1;
        }
        while(start<=end){
            mid=(start+end)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    return -1;
    }
    
};