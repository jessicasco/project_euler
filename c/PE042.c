#include <stdio.h>
#include <math.h>
int isTriangle(int n) {
    if(n == 0)
        return 0;
    int t = 2*n;
    int k = (int)sqrt(t);
    if(k*(k+1) == t)
        return 1;
    return 0;
}
int main() {
    int count = 0, c, sum;
    freopen("PE042.txt", "r", stdin);
    c = getchar();
    while(c != EOF){
        if(c == ',')
             c = getchar();
        sum = 0;
        while((c = getchar()) != '\"'){
            sum += c - 'A' + 1;
        }
        c = getchar();
        if(isTriangle(sum)){
            count ++;
        }
    }
    printf("%d\n", count);
    return 0;
}
