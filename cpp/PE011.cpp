#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf("PE011.txt");
    int a[20][20];
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++)
            inf >> a[i][j];
    int mul, max = 0;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++){
            if(i-3 >= 0 && j+3 < 20){
                mul = a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
                if(mul > max)
                    max = mul;
            }
            if(j+3 < 20){
                mul = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
                if(mul > max)
                    max = mul;
            }
            if(i+3 < 20){
                mul = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
                if(mul > max)
                    max = mul;
            }
            if(i+3 < 20 && j+3 < 20){
                mul = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
                if(mul > max)
                    max = mul;
            }
        }
    cout << max << endl;
    return 0;
}
