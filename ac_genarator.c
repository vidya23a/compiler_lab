#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char expr[30],postfix[30],stack[30];

int prec(char c){
	if(c=='^') return 3;
	else if(c=='/'||c=='*') return 2;
	else if(c=='+'||c=='-') return 1;
	else return -1;
}

void infixToPostfix(char *expr){
	int len=strlen(expr);
	int j=0,top=-1;
	for(int i=0;i<len;i++){
		char c=expr[i];
		if(isalnum(c)) 
			postfix[j++]=c;
		else if(c=='(')
			stack[++top]=c;
		else if(c==')'){
			while(top!=-1&&stack[top]!='(')
				postfix[j++]=stack[top--];
			top--;
		}
		else{
			while(top!=-1&&(prec(c)<prec(stack[top])||prec(c)==prec(stack[top])))
				postfix[j++]=stack[top--];
			stack[++top]=c;
		}
	}
	
	while(top!=-1)
		postfix[j++]=stack[top--];
	
	postfix[j]='\0';
	printf("The postfix expression is:%s\n",postfix);
}

int acgen(int start){
	int top=-1,i=0;
	char ch,ch1,ch2;
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalpha(ch)){
			printf("%d\tMOV A,%c\n%d\tPUSH A\n",start,ch,start+1);
			start=start+2;
		}
		else{
			printf("%d\tPOP B\n%d\tPOP A\n",start,start+1);
			start+=2;
			if(ch=='+') printf("%d\tADD A,B\n",start);
			else if(ch=='-') printf("%d\tSUB A,B\n",start);
			else if(ch=='*') printf("%d\tMUL A,B\n",start);
			else if(ch=='/') printf("%d\tDIV A,B\n",start);
			stack[++top]='A';
			start++;
			printf("%d\tPUSH A\n",start);
			start++;
		}
		i++;
	}
	printf("%d\tPOP A\n%d\tHLT\n",start,start+1);
}

int main(){
	printf("Enter the expression\n");
	scanf("%s",expr);
	printf("Enter the starting address:");
	int start;
	scanf("%d",&start);
	infixToPostfix(expr);
	acgen(start);
	
}
