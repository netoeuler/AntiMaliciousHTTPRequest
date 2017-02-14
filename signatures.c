#include <regex.h>

int is_signature_sql_injection(const char* input){
	//char* signatures[] = {"([0-9] | ' | \")? (OR | AND) [0-9]=[0-9]"};
	char* signatures[] = {"([0-9] | ' | \")?([+])(OR | AND)([+])[0-9]*[0-9]"};
	return check_signature(input, signatures);
}

int check_signature(const char* input, char** signatures){
	int size_array = sizeof(signatures)/sizeof(char*);
	int i, ret;
	regex_t reg;

	for (i=0; i <size_array; i++){
		ret = regcomp(&reg, signatures[i], REG_EXTENDED);
		if (ret) printf("error to compile.\n");

		ret = regexec(&reg, input, 0, NULL, 0);

		if (!ret){
			return 0;
		}
		else if (ret == REG_NOMATCH){
			printf("no match!\n");
		}
	}

	regfree(&reg);

	return -1;
}