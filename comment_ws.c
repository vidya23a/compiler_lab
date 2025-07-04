#include<stdio.h>

int main(int argc,char*argv[]){
	if(argc!=3){
		printf("Error:Expected two argument,but get %d\n",argc);
	}
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(fp1==NULL||fp2==NULL){
		printf("Error openng file\n");
		return 0;
	}
	
	char ch,x;
	while((ch=fgetc(fp1))!=EOF){
		switch(ch){
			case '\n':
			case '\t':
			case ' ': break;
			case '/':char ch2;
				    ch2=fgetc(fp1);
				    if(ch2=='/'){
				    	while(x=(fgetc(fp1))!='\n');
				    }
				    else if(ch2=='*'){
				    	char c1,c2;
				    	while(c1=(fgetc(fp1))!=EOF){
				    		if(c1=='*'){
				    			c2=fgetc(fp1);
				    			if(c2=='/'){
				    				break;
				    			}
				    			else{
				    				ungetc(c2,fp1);
				    			}
				    		}
				    	}
				    }
				    else{
				    	fputc(ch,fp2);
				    	ungetc(ch,fp1);
				    }
			            break;
			default:fputc(ch,fp2);
				    break;
		}
	}
	fclose(fp1);
	fclose(fp2);
}
