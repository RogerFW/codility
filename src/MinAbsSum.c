#include <alloca.h>
#include <memory.h>
#include <math.h>
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int max = 0;
    int sum = 0;
    
    for (int i = 0; i < N; i++){
        A[i] = abs(A[i]);
        max = max < A[i] ? A[i] : max;
        sum += A[i];
    }
        
    //the absolute values of A[] are between [0..100]
    int num_memsize = sizeof(int) * (max + 1);
    int* count = (int*)alloca(num_memsize);
    memset(count, 0x00, num_memsize);
    
    for (int i = 0; i < N; i++){
        count[A[i]]++;
    }
    
    
    int dp_memsize = sizeof(int) * (sum + 1);
    int* dp = (int*)alloca(dp_memsize);
    //clear up with -1.
    memset(dp, 0xFF, dp_memsize);
    
    dp[0] = 0;
    for (int i = 1; i <= max; i++){
        if (count[i] <= 0){
            continue;    
        }
        for (int j = 0; j <= sum; j++){
            if (dp[j] >= 0){
                dp[j] = count[i];    
            }
            else if (j >= i && dp[j - i] > 0){
                dp[j] = dp[j - i] - 1;    
            }
        }
    }
    
    int result = sum;
    for (int p = 0; p * 2 <= sum; p++){
        if (dp[p] >= 0){
            int q = sum - p;
            int diff = q - p;
            result = diff < result ? diff : result; 
        }
    }
    return result;
}
