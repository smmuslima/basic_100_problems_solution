#include<stdio.h>
#include<conio.h>

int  isPrime(int n){
if(n==1){
    return 1;
}
for(int i=2;i<n; i++){
    if(n%i==0){
return 0;
    }
}
return 1;
}

int main()
{
    int num;
    printf("enter an number ");
    scanf("%d",&num);

    if(isPrime(num)){
        printf("Prime number");
    }
    else{
        printf("Not a prime number ");
    }

    return 0;
}
