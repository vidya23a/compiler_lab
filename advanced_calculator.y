%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define YYSTYPE double
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UMINUS
%%
L:E'\n' {printf("The result is: %lf\n",$1);exit(1);}
;
E:E'+'E {$$=$1+$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'-'E {$$=$1-$3;}
|'('E')' {$$=$2;}
|'-'E %prec UMINUS
|NUMBER {$$=$1;}
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
		scanf("%lf",&yylval);
		return NUMBER;
	}
	else return ch;
}
 yyerror(){
	printf("Invalid expression\n");
	exit(0);
}


student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ yacc advanced_calc.y 
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ gcc y.tab.c
student@admincse-OptiPlex-5055-Ryzen-CPU:~/Desktop/vidya$ ./a.out 
Enter the expression:2+(3*5/3)*2
The result is: 12.000000
