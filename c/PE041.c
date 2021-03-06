#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    if(n == 1)
        return 0;
    else if(n < 4)
        return 1;
    else if(n%2 == 0)
        return 0;
    else if(n < 9)
        return 1;
    else if(n%3 == 0)
        return 0;
    else{
        int r = (int)sqrt((double)n);
        int f = 5;
        while(f <= r){
            if(n%f == 0)
                return 0;
            else if(n%(f+2) == 0)
                return 0;
            f += 6;
        }
    }
    return 1;
}
int main()
{
    int max = 0, a[10], k, i, j, m;
    for(i = 2; i <= 9876543; i++){
        if(isPrime(i)){
            for(j = 0; j < 10; j++)
                a[j] = 0;
            k = 0;
            m = i;
            while(m){
                k++;
                a[m%10] ++;
                m /= 10;
            }
            for(j = 1; j <= k; j++){
                if(a[j] == 0)
                    break;
            }
            if(j == k+1 && i >= max)
                max = i;
        }
    }
    printf("%d\n", max);
    return 0;
}
