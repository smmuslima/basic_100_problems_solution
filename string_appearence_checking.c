#include<stdio.h>
#include<string.h>

int main(){
 char str[100];
 char ch;
 int count=0;

 printf("Enter a string\n");
 fgets(str, 100, stdin);
 printf("Enter a character for found");
 scanf("%c",&ch);

 for(int i=0;i<strlen(str); i++)
 {
     if(str[i]==ch)
     {
         count++;

     }
 }
 printf("The character'%c'is appear %d times\n", ch,count);
}
