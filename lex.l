%{
	int line=1,sl_no=1;
	FILE*fp;
%}
DIGIT [0-9]
ALPHA [a-zA-Z]
WS [ \t]
DQ ["]
%%
{WS}+ {}
"\n" {line++;}
"+"|"-"|"*"|"/" {fprintf(fp,"%d\t%s\tArithmetic_op\t%d\n",sl_no,yytext,line);sl_no++;}
";" {fprintf(fp,"%d\t;\tSemicolon\t%d\n",sl_no,line);sl_no++;}
"<"|"<="|">"|">="|"!"|"!="|"==" {fprintf(fp,"%d\t%s\tRelational_op\t%d\n",sl_no,yytext,line);sl_no++;}
"=" {fprintf(fp,"%d\t%s\tAssignment_op\t%d\n",sl_no,yytext,line);sl_no++;}
"{"|"["|"(" {fprintf(fp,"%d\t%s\tOpen_brackets\t%d\n",sl_no,yytext,line);sl_no++;}
"}"|"]"|")" {fprintf(fp,"%d\t%s\tClose_brackets\t%d\n",sl_no,yytext,line);sl_no++;}
","|"&"|":"|"%"|"#"|"." {fprintf(fp,"%d\t%s\tSpecial_character\t%d\n",sl_no,yytext,line);sl_no++;}
{DQ}+ {fprintf(fp,"%d\t%s\tSpecial_character\t%d\n",sl_no,yytext,line);sl_no++;}
{DIGIT}+"."{DIGIT}+ {fprintf(fp,"%d\t%s\tFloating_num\t%d\n",sl_no,yytext,line);sl_no++;}
{DIGIT}+ {fprintf(fp,"%d\t%s\tNumber\t%d\n",sl_no,yytext,line);sl_no++;}
"int"|"stdio"|"printf"|"return"|"main" {fprintf(fp,"%d\t%s\tKeyword\t%d\n",sl_no,yytext,line);sl_no++;}
{ALPHA}({DIGIT}|{ALPHA})* {fprintf(fp,"%d\t%s\tIdentifier\t%d\n",sl_no,yytext,line);sl_no++;}
. {fprintf(fp,"%d\t%s\tUnrecognized\t%d\n",sl_no,yytext,line);sl_no++;}
%%
void main(int argc,char*argv[]){
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	fprintf(fp,"SL_no\tlexeme\ttoken\tline\n");
	yylex();
}
int yywrap(){
	return 1;
}
	
