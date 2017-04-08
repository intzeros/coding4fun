int findKth(int nums1[], int n1, int nums2[], int n2, int k){
    //always assume that n1 is equal or smaller than n2
    if(n1 > n2){
        return findKth(nums2, n2, nums1, n1, k);
    }
    if(n1 == 0){
        return nums2[k-1];
    }
    if(k == 1){
        return min(nums1[0], nums2[0]);
    }
    
    // divide k into two parts
    int k1 = min(k/2, n1);
    int k2 = k-k1;
    
    if(nums1[k1-1] < nums2[k2-1]){
        return findKth(nums1+k1, n1-k1, nums2, n2, k-k1);
    }else if(nums1[k1-1] > nums2[k2-1]){
        return findKth(nums1, n1, nums2+k2, n2-k2, k-k2);
    }else{
        return nums1[k1-1];
    }
}
 
double findMedianSortedArrays(int nums1[], int n1, int nums2[], int n2)  {
    if((n1+n2) & 1){
        return findKth(nums1, n1, nums2, n2, (n1+n2)/2 + 1);
    }else{
        return (findKth(nums1, n1, nums2, n2, (n1+n2)/2) + findKth(nums1, n1, nums2, n2, (n1+n2)/2 + 1)) / 2.0;
    }
}
