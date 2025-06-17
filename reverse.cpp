#include<iostream>

using namespace std;
int main()
{
    int num, r,rev_num=0;
    cout<<"Enter a number\n";
    cin>>num;

    while(num){
        r=num%10;
        rev_num=rev_num*10+r;
        num=num/10;
    }
    cout<<"Revers of the given numberis= "<<rev_num;
}
