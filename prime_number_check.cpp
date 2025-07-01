 #include<iostream>

 using namespace std;

 bool isprime(int n){
 if(n==1){
    return 1;

 }
 for(int i=2; i<n; i++){
    if(n%i==0)
    {
        return false;
    }
 }
 return true;
 }

 int main(){
 int num;
 cout<<"Enter a number ";
 cin>>num;

if(isprime(num)){
    cout<<"Prime number";
}
else{
    cout<<"Not a prime number";
}

 return 0;
 }
