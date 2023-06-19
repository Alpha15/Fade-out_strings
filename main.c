#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARR_LEN(s) (sizeof(s) / sizeof(s[0]))

int sleep(unsigned long x){
	clock_t c1 = clock();
	clock_t c2 = 0;
	do{
		if((c2 = clock()) == (clock_t)-1)
			return 0;
	}while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void){
	char str[] = "Hello,World!";
	printf("%s",str);
	fflush(stdout);
	for(int i = 0;i < ARR_LEN(str);i++){
		sleep(500);
		printf("\b \b");
		fflush(stdout);
	}
	return 0;
}
