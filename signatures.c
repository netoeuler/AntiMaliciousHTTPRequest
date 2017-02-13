#include <string.h>

int is_signature_sql_injection(char* input){
	char* signatures[] = {"1 OR 1=1"};
	int size_array = sizeof(signatures)/sizeof(char*);
	int i;

	for (i=0; i <size_array; i++){
		if (strcmp(input, signatures[i]) == 0){
			return 0;
		}
	}

	return -1;

}