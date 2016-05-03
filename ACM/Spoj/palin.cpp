#include <stdio.h>
#include <string.h>
const int MAXINT = 1000010;
int len;
char inp[MAXINT], palin[MAXINT], incpalin[MAXINT];



void fillPalin() {
	int cp = (len+1)/2;
	for(int i = 0; i < cp; i++) {
		palin[i] = inp[i];
		palin[len-i-1] = inp[i];
	}
	palin[len] = '\0';
}

void fillNines(){
	incpalin[0] = incpalin[len] = '1';
	incpalin[len+1] = '\0';
	for(int i = 1; i < len; i++)
		incpalin[i] = '0';
} 

void fillIncPalin() {
	bool isnines = true;
	int cp = (len+1)/2;
	
	for(int i = 0; i < cp && isnines; i++){
		if(palin[i]!='9') {
			isnines = false;
			break;
		}
	}

	if(isnines) {fillNines(); return;}

	int carry = 1;
	for(int i = cp-1; i >= 0; i--) {
		char v =  ((palin[i] + carry - '0')%10) + '0';
		incpalin[i] = v;	
		incpalin[len - i - 1] = incpalin[i];
		if(incpalin[i] != '0') carry = 0;
	} 
	incpalin[len] = '\0';
}

int main() {
	int T;
	scanf(" %d",&T);
	while(T--) {
		scanf(" %s",inp);
		len = strlen(inp);
		fillPalin();
		if(strcmp(palin, inp) > 0){
			 printf("%s\n",palin);
		}
		else {
			fillIncPalin();
			printf("%s\n",incpalin);
		}
	}	
}
