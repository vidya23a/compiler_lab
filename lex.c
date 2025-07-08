#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char*argv[]){
	int line=1,slno=1;
	char lexeme[50],ch;
	char keywords[20][50]={"void", "int", "main", "include", "stdio", "FILE", "argc", "argv", "printf" ,"fgetc", "fopen", "while", "do", "else", "if", "char", "fgetc", "ungetc", "fprintf", "for"};
	FILE*fp1,*fp2;
	if(argc!=3){
		printf("Insufficient arguments\n");
	}
	
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(fp1==NULL||fp2==NULL){
		printf("Error opening files\n");
	}
	fprintf(fp2,"Sl.No    Lexeme\tToken\t\tLine No.\n");
	while((ch=fgetc(fp1))!=EOF){
		if(ch=='\t'||ch==' '){
			continue;
		}	
		else if(ch=='\n'){
			line++;
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
			fprintf(fp2,"%d\t%c\t\tArithmetic_op\t\t%d\n",slno,ch,line);
			slno++;
		}
		else if(ch=='{'||ch=='['||ch=='('){
			fprintf(fp2,"%d\t%c\t\tOpen_bracket\t\t%d\n",slno,ch,line);
			slno++;
		}
		else if(ch=='}'||ch==']'||ch==')'){
			fprintf(fp2,"%d\t%c\t\tClose_bracket\t\t%d\n",slno,ch,line);
			slno++;
		}
		else if(ch==','||ch=='&'||ch==':'||ch=='#'||ch=='.'||ch=='_'){
			fprintf(fp2,"%d\t%c\t\tSpecial_op\t\t%d\n",slno,ch,line);
			slno++;
		}
		else if(ch==';'){
			fprintf(fp2,"%d\t%c\t\tSemi-colon\t\t%d\n",slno,ch,line);
			slno++;
		}
		else if(ch=='='){
			char ch1=fgetc(fp1);
			if(ch1=='='){
				fprintf(fp2,"%d\t%c%c\t\tRelational_op\t\t%d\n",slno,ch,ch1,line);
				slno++;
			}
			else{
				ungetc(ch1,fp1);
				fprintf(fp2,"%d\t%c\t\tAssignment_op\t\t%d\n",slno,ch,line);
				slno++;
			}
		}
		else if(ch=='<'||ch=='>'||ch=='!'){
			char c1=fgetc(fp1);
			if(c1=='='){
				fprintf(fp2,"%d\t%c%c\t\tRelational_op\t\t%d\n",slno,ch,c1,line);
				slno++;
			}
			else{
				ungetc(c1,fp1);
				fprintf(fp2,"%d\t%c\t\tRelational_op\t\t%d\n",slno,ch,line);
				slno++;
			}
		}
		else if(isdigit(ch)){
			int i=0,flag=0;
			char ch1;
			lexeme[i]=ch;
			i++;
			do{
				ch1=fgetc(fp1);
				if(ch1=='.'){
					flag=1;
				}
				lexeme[i]=ch1;
				i++;
			}while((isdigit(ch1)||ch1=='.'));
			lexeme[i-1]='\0';
			printf("%s",lexeme);
			ungetc(ch1,fp1);
			if(flag==1){
				fprintf(fp2,"%d\t%s\t\tFloating_point\t\t%d\n",slno,lexeme,line);
				slno++;
			}
			else{
				fprintf(fp2,"%d\t%s\t\tNumber\t\t%d\n",slno,lexeme,line);
				slno++;
			}
		}
		else if(isalpha(ch)){
			int i=0,flag=0;
			char ch1;
			lexeme[i]=ch;
			i++;
			do{
				ch1=fgetc(fp1);
				lexeme[i]=ch1;
				i++;
			}while(isalpha(ch1)||isdigit(ch1));
			lexeme[i-1]='\0';
			ungetc(ch1,fp1);
			for(int j=0;j<20;j++){
				if(strcmp(lexeme,keywords[j])==0){
					flag=1;
					break;
				}
				else;
			}
			if(flag==1){
				fprintf(fp2,"%d\t%s\t\tKeyword\t\t%d\n",slno,lexeme,line);
				slno++;
			}
			else{
				fprintf(fp2,"%d\t%s\t\tIdentifier\t\t%d\n",slno,lexeme,line);
				slno++;
			}
		}
		else{
			fprintf(fp2,"%d\t%c\t\tUnrecognized\t\t%d\n",slno,ch,line);
			slno++;
		}
	}
}
