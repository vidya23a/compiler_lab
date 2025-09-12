#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	if(argc!=2){
		printf("Expected arguments\n");
		exit(0);
	}
	FILE*fp1=fopen(argv[1],"r");
	char ch,ch1;
	char stack[30];
	int top=-1,line=1,flag=0;
	while((ch=fgetc(fp1))!=EOF){
		switch(ch){
			case '{':
			case '[':
			case '(':stack[++top]=ch;
					  break;
			case '\n':line++;
			                 break;
			case '}':if(top==-1) printf("Open paranthesis missing at line %d\n",line);
					  else{
					  	ch1=stack[top--];
					  	if(ch1=='{');
					  	else {
					  	printf("Paranthesis mismatch found at line %d\n",line);
					  	flag=1;
					 	}
					 }
					  break;
			case ']':if(top==-1) printf("Open paranthesis missing at line %d\n",line);
			                else{
			             	ch1=stack[top--];
					  	if(ch1=='[');
					  	else {
					  	printf("Paranthesis mismatch found at line %d\n",line);
					  	flag=1;
					 	}
					 }
					  break;
			case ')':if(top==-1) printf("Open paranthesis missing at line %d\n",line);
			                else{
			             	ch1=stack[top--];
					  	if(ch1=='(');
					  	else {
					  	printf("Paranthesis mismatch found at line %d\n",line);
					  	flag=1;
					 	}
					 }
					  break;
			default:break;
		}				
	}
	if(top!=-1) 
		printf("Closing parenthesis missing at line%d\n",line);
	if(!flag)
		printf("Balanced Parenthesis. Syntax verified!\n");
}



student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ gcc balanced_parenthesis.c 
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ ./a.out example.c
Paranthesis mismatch found at line 8
Closing parenthesis missing at line14


example.c
#include <stdio.h>

int main() {
    int arr[5;       
    int a = 10;
    int b = 20;

    if (a < b)) {     
        printf("a is less than b\n";
                 

    return 0;
