#include<iostream>

using namespace std;

int main(){
int num, r;
int Count=0;
cout<<"Enter a number  ";
cin>>num;

while(num>0){
    num=num/10;
    Count++;

}

cout<<"Number of digits is  "<<Count;

return 0;
}
