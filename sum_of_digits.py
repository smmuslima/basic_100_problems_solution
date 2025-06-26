r;
sum=0;
num=input("Enter a number");

while i<num:
r=num%10;
sum+=r;
num=num/10;

print("Sum of the digits of given number :"+sum);
