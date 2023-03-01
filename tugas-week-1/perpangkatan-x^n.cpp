int pangkat(int x, int n){
    int result = 1;

    for(int i = 0; i < n; i++){
        result = result * x;
    }

    return result;
}

int pangkat_rec(int x, int n){
    if(n == 0) return 1;
    return x * pangkat_rec(x, n-1);
}
