#include<stdio.h>

char string[20];
int j=0;

int E();
int T();
int T1();
int E1();
int F();


int E(){
	printf("E-->TE1\n");
	if(T()==1){
 		if(E1()==1){
 			return 1;
 		}
 		else{
 			return 0;
 		}
	}
	else{
 		return 0;
	}
}

int E1(){
	if(string[j]=='+'){
		printf("E1-->+TE1\n");
		printf("Consuming %c\n",string[j]);
		j++;
		if(T()==1){
			if(E1()==1){
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
			
	}
	else{
		printf("E1-->e\n");
		return 1;
	}
		
}

int T(){
	printf("T-->FT1\n");
	if(F()==1){
		if(T1()==1){
			return 1;
		}
		else
			return 0;
	}
	return 0;
}


int T1(){
	if(string[j]=='*'){
		printf("T1-->*FT1\n");
		printf("Consuming %c\n",string[j]);
		j++;
		if(F()==1){
			if(T1()==1){
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else{
		printf("T1-->e\n");
		return 1;
	}
		
}

int F(){
	if(string[j]=='('){
		printf("F-->(E)\n");
		printf("Consuming %c\n",string[j]);
		j++;
		if(E()==1){
			if(string[j]==')'){
				printf("Consuming %c",string[j]);
				j++;
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else if(string[j]=='i'){
			printf("F-->i\n");
			printf("Consuming %c\n",string[j]);
			j++;
			return 1;
	}
	else{
		return 0;
	}
	
	
	
}
int main(){
	printf("Enter the string\n");
	scanf("%s",string);
	if(E()==1&&string[j]=='\0'){
		printf("String accepted\n");
	}
	else{
		printf("String rejected\n");
	}
}
