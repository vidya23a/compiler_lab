%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token DIGIT LETTER
%%
L:A'\n' {printf("Valid variable\n");exit(1);}
A:LETTER B
|LETTER
;
B:LETTER B
|LETTER
|DIGIT
|DIGIT B
;
%%
void main(){
	printf("Enter the variable name:");
	yyparse();
}
yylex(){
	char ch;
	ch=getchar();
	if(isalpha(ch)) return LETTER;
	else if(isdigit(ch)) return DIGIT;
	else return ch;
}
 yyerror(){
	printf("Invalid expression\n");
	exit(0);
}


student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ yacc variable_check.y 
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ gcc y.tab.c
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ ./a.out 
Enter the variable name:abc
Valid variable
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ ./a.out 
Enter the variable name:3as
Invalid expression
