/*Lex program to check perfect numbers*/

% 
{ 
#include <string.h> 
	void check(char*); 
	% 
} 

/*Rule Section*/
% % 
		[0 - 9] 
	+ check(yytext); 
% % int main() 
{ 
	// the input stream pointer 
	extern FILE* yyin; 

	// open a file handle to a particular file 
	yyin = fopen("num", "r"); 

	// The function that starts the analysis 
	yylex(); 
	return 0; 
} 
void check(char* a) 
{ 
	int len = strlen(a), i, num = 0; 

	for (i = 0; i < len; i++) 
		num = num * 10 + (a[i] - '0'); 

	int x = 0, temp = num; 
	for (i = 1; i < num; i++) { 
		if (num % i == 0) 
			x = x + i; 
	} 
	if (x == temp) 
		printf("%d is perfect number \n", num); 

	else
		printf("%d is not perfect number \n", num); 
} 
