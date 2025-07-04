#include<stdio.h>

int main(){
	int n,inp_no,trans[20][20],final[20],fin_no;
	char alpha[20],input[20],ch;
	printf("Enter the number of states\n");
	scanf("%d",&n);
	printf("Enter the number of input alphabet\n");
	scanf("%d",&inp_no);
	printf("Enter the input alphabets\n");
	scanf("%s",alpha);
	printf("Enter the transitions\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<inp_no;j++){
		printf("For state%d on alphabet %c:",i,alpha[j]);
		scanf("%d",&trans[i][j]);
		}
	}
	printf("Enter the number of final states\n");
	scanf("%d",&fin_no);
	printf("Enter the final states\n");
	for(int i=0;i<fin_no;i++){
		scanf("%d",&final[i]);
	}
	printf("Enter the string or enter 'EXIT'\n");
	scanf("%s",input);
	do{
		int i=0,j=0,accepted=0,current_state=0;
		while(input[i]!='\0'){
			int char_match=-1;
			for(int j=0;j<inp_no;j++){
				if(alpha[j]==input[i]){
					char_match=j;
					break;
				}
			}
			if(char_match==-1){
				printf("cannot resolve the input symbol\n"); //checkingg input symbols
				return 0;
			}
			else{
				current_state=trans[current_state][char_match];
			}
			i++;
		}
		for(int j=0;j<fin_no;j++){
			if(final[j]==current_state){
				accepted=1;
				break;
			}
		}
	
		if(accepted==1){
			printf("The string is accepted\n");
		}
		else{
			printf("The string is rejected\n");
		}
		printf("Enter the input string\n");
		scanf("%s",input);
	}while(input!="EXIT");
	
}
