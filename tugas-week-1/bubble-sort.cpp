void bubble_sort(int arr[], int n){
    int i, k, temp;
    for(int i = 0; i < n - 1; i++){
        for(int k = n - 1; k >= i+1; k--){
            if(arr[k] < arr[k-1]){
                temp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp;
            }
        }
    }
}