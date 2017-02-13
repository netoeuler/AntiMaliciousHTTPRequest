#include <stdlib.h>
#include <string.h>

int is_post_request(const char* text){
	char first4[] = {text[0], text[1], text[2], text[3]};
	if (strcmp(first4, "POST") == 0){
		return 0;
	}
	else{
		return -1;
	}
	
}