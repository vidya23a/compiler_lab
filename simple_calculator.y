%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token NUMBER
%%
L:E'\n' {printf("The result is: %d\n",$1);exit(1);}
;
E:E'+'T {$$=$1+$3;}
|T {$$=$1;}
;
T:T'*'F {$$=$1*$3;}
|F {$$=$1;}
;
F:NUMBER {$$=$1;}
;
%%
void main(){
	printf("Enter the expression:");
	yyparse();
}
yylex(){
	char ch;
	ch=getchar();
	if(isdigit(ch)){
		ungetc(ch,stdin);
		scanf("%d",&yylval);
		return NUMBER;
	}
	else return ch;
}
yyerror(){
	printf("Invalid expression\n");
	exit(0);
}


student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ yacc simp_cal.y 
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ gcc y.tab.c
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ ./a.out 
Enter the expression:2+3*5
The result is: 17
