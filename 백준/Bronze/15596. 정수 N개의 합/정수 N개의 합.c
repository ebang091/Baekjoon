long long sum(int *a, int n) {
	
    long long result = 0;
    int *ptr = a;
    while(ptr < a + n)
        result += *ptr++;
    return result;
}
