#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fibbo.h"
int fibbo (int numberOfTerms,int *array){
	int i,next;
	if(numberOfTerms<1){
		return 0;
	}
	for(i=0;i<numberOfTerms;++i){
		array[i]=(i<=1)?i:array[i-1]+array[i-2];
	};
	return 1;
}

int concat (int *array1, int len_of_array1, int *array2, int len_of_array2, int **result_array){
	int i,total=len_of_array1+len_of_array2;
	if(len_of_array1<=0 && len_of_array2<=0){return 0;};
	*result_array=(int *)malloc(sizeof(int)*(len_of_array1+len_of_array2));
	for(i=0;i<total;++i){
		if(i<len_of_array1){(*result_array)[i]=array1[i];}
		else{(*result_array)[i]=array2[i-len_of_array1];};
	}
	return 1;
}

int filter(int *array, int length, int threshold, int **result_array){
	int i,r_i=0;
	if (length<=0){return 0;};
	*result_array=(int *)malloc(sizeof(int)*length);
	for(i=0;i<length;++i){
		if(array[i]>=threshold){
			(*result_array)[r_i]=array[i];
			++r_i;
		};
	};
	return r_i;
}

int reverse(int *array, int length, int **result_array){
	int i,r_i=length-1;
	if(length<=0){return 0;};
	*result_array=(int *)malloc(sizeof(int)*length);
	for(i=0;i<length;++i){
		(*result_array)[r_i]=array[i];
		--r_i;
	};
	return 1;
}

int reverse_1(int *array, int length){
	int i,temp;
	if(length<=0){return 0;};
	for(i=0;i<length/2;++i){
		temp=array[i];
		array[i]=array[length-i-1];
		array[length-i-1]=temp;
	};
	return 1;
}


int slice(int *array,int len_of_array,int start_index,int end_index,int **result_array){
	int i,r_i=0;
	if(len_of_array==0 || start_index<0 || end_index<=0){return 0;};
	*result_array=(int *)malloc(sizeof(int)*(end_index-start_index));
	for(i=start_index;i<end_index;++i){
		(*result_array)[r_i]=array[i];
		++r_i;
	};
	return end_index-start_index;
}

int is_Prime(int number){
	int j;
	for (j = 2; j < number/2; j++){
 		if((number % j) ==0) 
 		return 0;
 	};
	return 1;
};

int prime(int num1,int num2,int **array){
	int i,count=0;
	if(num1<=1 || num2<=num1){return 0;};
	*array=(int *)malloc(sizeof(int)*(num2-num1)/4);
	for(i = num1; i <= num2; i++){
    	if(is_Prime(i) == 1){
 			(*array)[count]=i;
 			++count;
  		};
  	};
  	return count;
}

int strcomp(char *char_1,char *char_2){
	int l1=strlen(char_1),l2=strlen(char_2),total,i;
	total=(l1>l2)?l1:l2;
	for (i = 0; i < total; ++i) {
		if(char_1[i] != char_2[i]){
			return char_1[i]-char_2[i];
		}
	};
	return 0;
}

int forEach_int(int *array,int length,void (*fn)(int,int,int *)){
	int i;
	if(length==0){return 0;}
	for(i=0;i<length;++i){
		fn(array[i],i,array);
	}
	return 1;
}

int forEach_char(char *array,int length,void (*fn)(char,int,char *)){
	int i;
	if(length==0){return 0;}
	for(i=0;i<length;++i){
		fn(array[i],i,array);
	}
	return 1;
}

int filter_int(int *array,int length,int **result_array,int (*fn)(int,int,int *)){
	int i,r_i=0,space=0;
	if(length==0){return 0;}
	for(i = 0; i < length; ++i)
	{
		if(fn(array[i],i,array)){++space;}
	}
	(*result_array)=(int *)malloc(sizeof(int)*space);
	for(i=0; i<length; ++i){
		if(fn(array[i],i,array)){
			(*result_array)[r_i]=array[i];
			++r_i;
		}
	}
	return space;
}

int filter_char(char *array,int length,char **result_array,int (*fn)(char,int,char *)){
	int i,r_i=0,space=0;
	if(length==0){return 0;}
	for(i = 0; i < length; ++i)
	{
		if(fn(array[i],i,array)){++space;}
	}
	(*result_array)=(char *)malloc(sizeof(char)*space);
	for(i=0; i<length; ++i){
		if(fn(array[i],i,array)){
			(*result_array)[r_i]=array[i];
			++r_i;
		}
	}
	return space;
}

int forEach_string(char **array,int length,void (*fn)(char *,int,char **)){
	int i;
	if(length==0){return 0;}
	for(i=0;i<length;i++){
		fn(array[i],i,array);
	}
	return 1;
}


int *map_int(int *array,int length,int (*fn)(int,int,int *)){
	int *mapped,i;
	// if(length==0){return 0;};
	mapped=(int *)malloc(sizeof(int)*length);
	for (i=0; i<length; ++i){
		mapped[i]=fn(array[i],i,array);
	}
	return mapped;
}

char *map_char(char *array,int length,char (*fn)(char,int)){
	char *mapped;
	int i;
	mapped=(char *)malloc(sizeof(char));
	for (i=0; i<length; ++i){
		mapped[i]=fn(array[i],i);
	}
	return mapped;
}

char **map_string(char **array,int length,char* (*fn)(char*,int)){
	char **mapped;
	int i;
	mapped=(char **)malloc(sizeof(char *)*length);
	for(i=0; i<length; ++i){
		mapped[i]=fn(array[i],i);
	}
	return mapped;
}

int reduce_int(int *array,int length,int initial_value,int (*fn)(int,int)){
	int return_value=initial_value,i;
	for(i=0;i<length;++i){
		return_value=fn(return_value,array[i]);
	}
	return return_value;
}

int filter_string(char **array,int length,char **result_array,int (*fn)(char *)){
	int i,r_i=0;
	if(length==0){return 0;}
	for(i=0; i<length; ++i){
		if(fn(array[i])){
			result_array[r_i]=array[i];
			++r_i;
		}
	}
	return r_i;
}

char reduce_char(char *array,int length,char initial_value,char (*fn)(char,char)){
	char return_value=initial_value,i;
	for(i=0;i<length;++i){
		return_value=fn(return_value,array[i]);
	}
	return return_value;
}

int filter_float(float *array,int length,float **result_array,int (*fn)(float)){
	int i,r_i=0,space=0;
	if(length==0){return 0;}
	for(i = 0; i < length; ++i)
	{
		if(fn(array[i])){++space;}
	}
	(*result_array)=(float *)malloc(sizeof(float)*space);
	for(i=0; i<length; ++i){
		if(fn(array[i])){
			(*result_array)[r_i]=array[i];
			++r_i;
		}
	}
	return space;
}

int forEach_float(float *array,int length,void (*fn)(float,int,float *)){
	int i;
	if(length==0){return 0;}
	for(i=0;i<length;++i){
		fn(array[i],i,array);
	}
	return 1;
}

float *map_float(float *array,int length,float (*fn)(float)){
	float *mapped;
	int i;
	mapped=(float *)malloc(sizeof(float)*length);
	for (i=0; i<length; ++i){
		mapped[i]=fn(array[i]);
	}
	return mapped;
}

float reduce_float(float *array,int length,float initial_value,float (*fn)(float,float)){
	float return_value=initial_value;
	int i;
	for(i=0;i<length;++i){
		return_value=fn(return_value,array[i]);
	}
	return return_value;
}

char *reduce_string(char **array,int length,char *initial_value,char *(*fn)(char *,char *)){
	int i;
	for(i=0;i<length;i++){ 
		initial_value = fn(initial_value,array[i]);
	}
	return initial_value;
}

int indexOf(char *str,char *substr){
	int l1=strlen(str),l2=strlen(substr),i,sub_i=0; 
	for(i=0;i<l1;i++){
		if(sub_i>0 && str[i]!=substr[sub_i]){
			sub_i=0;
		}
		if(str[i]==substr[sub_i]){
			++sub_i;
			if(sub_i==l2){return (i+1)-l2;}
		}
	}
	return -1;
}