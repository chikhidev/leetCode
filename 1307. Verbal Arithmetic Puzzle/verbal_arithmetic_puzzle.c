#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int str_len(char *str){
	int i = 0;
	while (str[i])
		i++;
	return i;
}




void set_res(char *str, char *alphs, int *res_pos){
	while (*str){
		int pos = 0;
		int found = 0;
		while (alphs[pos]){
			if (alphs[pos] == *str){
				found = 1;
				break;
			}
			pos++;
		}
		if (!found){
			alphs[*res_pos] = *str;
			(*res_pos) += 1;
			alphs[*res_pos] = '\0';
		}
		str++;
	}
}




char *get_all(char **words, int n, char * result){
	int i = 0;
	char *res = malloc(sizeof(char) * 11);	
	res[0] = '\0';
	int res_pos = 0;
	while (i < n){
		set_res(words[i], res, &res_pos);
		i++;
	}
	set_res(result, res, &res_pos);
	return res;



}



char *get_base(int i, char * alphs){
	int pos = 0;
	char *indexes = malloc(sizeof(char) * 11);
    	if (indexes == NULL)
		return 0;

	while (alphs[i]){
		if (i > 9)
			i = 0;
		indexes[pos] = i + 48;
        	pos++;
        	i++;
	}
	indexes[pos] = '\0';
	return indexes;
}




int get_index_rep(char c, char * base, char * alphs){
	int i = 0;

	while (alphs[i]){
		if (alphs[i] == c)
			return base[i] - 48;
		i++;
	}
	return 0;
}




int isSolvable(char ** words, int wordsSize, char * result){
	int i = 0;
	int stringAt = 0;
	char *all_chars = get_all(words, wordsSize, result);
	while (i < 10){
		char *base = get_base(i, all_chars);
		int res = 0;
		while (stringAt < wordsSize){
			int temp_res = 0;
			int j = 0;
			while (words[stringAt][j]){
				temp_res = temp_res * 10 + get_index_rep(words[stringAt][j], base, all_chars);
				j++;
			}
			res += temp_res;
			stringAt++;
		}
		int j = 0;
		int expected = 0;
		while (result[j]){
			expected = expected * 10 + get_index_rep(result[j], base, all_chars);
			j++;
		}
		if (res == expected){
			printf("res:\t\t%d\n", res);
			printf("expected:\t%d\n", expected);
			return 1;
		}
		i++;
	}

	return 0;
}




int main(){
	char **strs = malloc(sizeof(char *) * 2);
	strs[0] = "SEND";
	strs[1] = "MORE";
	if(isSolvable(strs, 2, "MONEY"))
		printf("solvable!\n");
	else
		printf("not solvable!\n");
			
	return 0;
}
