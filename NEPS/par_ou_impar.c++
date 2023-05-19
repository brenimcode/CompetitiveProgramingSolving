#include <iostream>
using namespace std;

int main(){
    int b,c;
    cin >> b >> c;
//bino par e c e impar
if ((b > 10 || b < 0) && (c > 10 || c < 0))
{
    return 0;
}

if ((b+c)%2 == 0)
{
    printf("Bino");
}
else{
    printf("Cino");
}
    return 0;
}