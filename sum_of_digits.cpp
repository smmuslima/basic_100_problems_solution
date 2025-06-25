Problem no 4.
Algorithm SumOfDigit
step 1: num, r, sum=0
step 2:r=num%10;
       sum+=r 
        num=num/10
step 3: if num=0
    No: Go to step 2
    Yes:Go to next step
step 4: print sum;
step 5: exist

DEBUG
num -    r  -   sum  - output
456      0      0       
45       6      6
4        5      11
0        4      15      

                        15



Code in C++:

#include<iostream>

using namespace std;
int main()
{
    int num, r;
    int sum=0;

    cout<<"Enter a number: \n";
    cin>>num;

    while(num>0)
    {
        r=num%10;
        sum+=r;
        num=num/10;
    }

    cout<<"Sum of digit from given number   ";
    cout<<sum;
    return 0;
}

Code in c:


#include<iostream>

using namespace std;
int main()
{
    int num, r;
    int sum=0;

    cout<<"Enter a number: \n";
    cin>>num;

    while(num>0)
    {
        r=num%10;
        sum+=r;
        num=num/10;
    }

    cout<<"Sum of digit from given number   ";
    cout<<sum;
    return 0;
}

CODE c#:

using system;
class program
{
static int SumOfDigit(int number)
{
number=Math.Abs(number);
int sum=0;
while(number>0)
{
sum+=number%10;
number/=10;
}
}
static void main()
{
Console.writeline("Enter a number");
int num=convert.Total32(Console.readline());
int result=SumOfDigit(num);
Console.Writelina("Sum of Digits: "+result);
}
}
