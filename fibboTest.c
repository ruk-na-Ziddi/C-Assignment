#include <stdlib.h>
#include "expr_assert.h"
#include "fibbo.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void test_a(){
	int *array;
	array=(int *)malloc(sizeof(int)*5);
	assertEqual(fibbo(5,array),1);
	free(array);
}

void test_b(){
	int *array;
	array=(int *)malloc(sizeof(int)*5);
	assertEqual(fibbo(-5,array),0);
	free(array);

}

void test_c(){
	int *array;
	array=(int *)malloc(sizeof(int)*5);
	assertEqual(fibbo(1,array),1);
	assertEqual(array[0],0);
	free(array);
}

void test_d(){
	int *array;
	array=(int *)malloc(sizeof(int)*5);
	assertEqual(fibbo(2,array),1);
	assertEqual(array[0],0);
	assertEqual(array[1],1);
	free(array);

}

void test_e(){
	int *array;
	array=(int *)malloc(sizeof(int)*5);
	assertEqual(fibbo(3,array),1);
	assertEqual(array[0],0);
	assertEqual(array[1],1);
	assertEqual(array[2],1);
	free(array);

}

void test_f(){
	int *array;
	array=(int *)malloc(sizeof(int)*6);
	assertEqual(fibbo(6,array),1);
	assertEqual(array[0],0);
	assertEqual(array[1],1);
	assertEqual(array[2],1);
	assertEqual(array[3],2);
	assertEqual(array[4],3);
	assertEqual(array[5],5);
	free(array);

}

void test_g(){
	int array1[]={1,2},len_of_array1=2,array2[]={3,4,5},len_of_array2=3,*result_array;
	assertEqual(concat(array1, 2, array2, 3, &result_array), 1);
	assertEqual(result_array[0], 1);
	assertEqual(result_array[1], 2);
	assertEqual(result_array[2], 3);
	assertEqual(result_array[3], 4);
	assertEqual(result_array[4], 5);
	free(result_array);
}

void test_h(){
	int array1[]={},len_of_array1=0,array2[]={},len_of_array2=0,*result_array;
	assertEqual(concat(array1, 0, array2, 0, &result_array), 0);
}

void test_i(){
	int array[]={1,2,3,4,5},length=5,threshold=3,*result_array;
	assertEqual(filter(array,5,3,&result_array), 3);
	assertEqual(result_array[0], 3);
	assertEqual(result_array[1], 4);
	assertEqual(result_array[2], 5);
	free(result_array);
}

void test_j(){
	int array[]={},length=0,threshold=3,*result_array;
	assertEqual(filter(array,0,3,&result_array), 0);
}

void test_k(){
	int array[]={1,2,3,4,5,6},length=6,*result_array;
	assertEqual(reverse(array,6,&result_array), 1);
	assertEqual(result_array[0], 6);
	assertEqual(result_array[1], 5);
	assertEqual(result_array[2], 4);
	assertEqual(result_array[3], 3);
	assertEqual(result_array[4], 2);
	assertEqual(result_array[5], 1);
	free(result_array);
}

void test_l(){
	int array[]={},length=0,*result_array;
	assertEqual(reverse(array,0,&result_array), 0);
}

void test_m(){
	int array[]={1,2,3,4,5,6},lenght=6;
	assertEqual(reverse_1(array,6), 1);
	assertEqual(array[0], 6);
	assertEqual(array[1], 5);
	assertEqual(array[2], 4);
	assertEqual(array[3], 3);
	assertEqual(array[4], 2);
	assertEqual(array[5], 1);
}

void test_n(){
	int array[]={1,2,3,4,5},lenght=5;
	assertEqual(reverse_1(array,5), 1);
	assertEqual(array[0], 5);
	assertEqual(array[1], 4);
	assertEqual(array[2], 3);
	assertEqual(array[3], 2);
	assertEqual(array[4], 1);
}

void test_o(){
	int array[]={},lenght=0;
	assertEqual(reverse_1(array,0), 0);
}

void test_p(){
	int array[]={1,2,3,4,5},len_of_array=5,start_index=1,end_index=3,*result_array;
	assertEqual(slice(array,5,1,3,&result_array), 2);
	assertEqual(result_array[0], 2);
	assertEqual(result_array[1], 3);
	free(result_array);
}

void test_q(){
	int array[]={},len_of_array=0,start_index=0,end_index=0,*result_array;
	assertEqual(slice(array,0,0,0,&result_array), 0);
}

void test_r(){
	int array[]={1,2,3,4,5,6},len_of_array=6,start_index=0,end_index=5,*result_array;
	assertEqual(slice(array,6,0,5,&result_array), 5);
	assertEqual(result_array[0], 1);
	assertEqual(result_array[1], 2);
	assertEqual(result_array[2], 3);
	assertEqual(result_array[3], 4);
	assertEqual(result_array[4], 5);
	free(result_array);
}

void test_s(){
	int num1=2,num2=20,*array;
	assertEqual(prime(2,20,&array), 9);
	assertEqual(array[0], 2);
	assertEqual(array[8], 19);
	free(array);
}

void test_t(){
	char *char_1="hello",*char_2="helloo";
	assertEqual(strcomp(char_1,char_2), strcmp(char_1,char_2));
}

void test_u(){
	char *char_1="helloo",*char_2="hello";
	assertEqual(strcomp(char_1,char_2), strcmp(char_1,char_2));
}

void test_v(){
	char *char_1="hello",*char_2="hello";
	assertEqual(strcomp(char_1,char_2), strcmp(char_1,char_2));
}

void test_w(){
	char *char_1="hellooo",*char_2="hello";
	assertEqual(strcomp(char_1,char_2), strcmp(char_1,char_2));
}

void increment(int ele,int i,int *array){
	array[i]=ele+1;
}

void test_x(){
	int array[]={1,2,3,4,5},length=5;
	void (*fn)(int,int,int *array)=&increment;
	assertEqual(forEach_int(array,length,fn), 1);
	assertEqual(array[0], 2);
	assertEqual(array[1], 3);
	assertEqual(array[2], 4);
	assertEqual(array[3], 5);
	assertEqual(array[4], 6);
}

void two_times(float ele,int i,float *array){
	array[i]=ele*2;
}

void test_y(){
	float array[]={1.5,2.5,3.5,4.5,5.5};
	int length=5;
	assertEqual(forEach_float(array,length,two_times), 1);
	assertEqual(array[0], 3);
	assertEqual(array[1], 5);
	assertEqual(array[2], 7);
	assertEqual(array[3], 9);
	assertEqual(array[4], 11);
}

void test_z(){
	float array[]={};
	int length=0;
	assertEqual(forEach_float(array,length,two_times), 0);
}

void test_aa(){
	int array[]={},length=0;
	assertEqual(forEach_int(array,length,increment), 0);
}

void next_char(char ele,int i,char * array){
	array[i]=ele+1;
}

void test_bb(){
	char array[]={'a','b','c','d','e'},length=5;
	void (*fn)(char,int,char *)=&next_char;
	assertEqual(forEach_char(array,length,fn), 1);
	assertEqual(array[0], 'b');
	assertEqual(array[1], 'c');
	assertEqual(array[2], 'd');
	assertEqual(array[3], 'e');
	assertEqual(array[4], 'f');
}

void test_cc(){
	char array[]={},length=0;
	// void (*fn)(char,int,char *)=&next_char;
	assertEqual(forEach_char(array,length,next_char), 0);
}

int even(int ele,int i,int * array){
	return ele%2==0;
}

void test_dd(){	
	int array[]={1,2,3,4,5,6},length=6;
	// int (*fn)(int,int,int *)=&even;
	int *result_array;
	assertEqual(filter_int(array,length,&result_array,even), 3);
	assertEqual(result_array[0], 2);
	assertEqual(result_array[1], 4);
	assertEqual(result_array[2], 6);
	free(result_array);
}

int greater_than_2(float ele){
	return ele>2;
}

void test_ee(){	
	float array[]={1.5,2.5,3.5,4.5,5.5,6.5};
	int length=6;
	float *result_array;
	assertEqual(filter_float(array,length,&result_array,greater_than_2), 5);
	assertEqual(abs(result_array[0]), 2);
	assertEqual(abs(result_array[1]), 3);
	assertEqual(abs(result_array[2]), 4);
	assertEqual(abs(result_array[3]), 5);
	assertEqual(abs(result_array[4]), 6);
	free(result_array);
}

void test_ff(){
	float array[]={};
	int length=0;
	float *result_array;
	assertEqual(filter_float(array,length,&result_array,greater_than_2), 0);
}

void test_gg(){
	int array[]={},length=0,(*fn)(int,int,int *)=&even,*result_array;
	assertEqual(filter_int(array,length,&result_array,fn), 0);
}

int greater_than_h(char ele,int i,char *array){
	return array[i]>'h';
}

void test_hh(){
	char array[]={'a','d','o','q','s'};
	int length=5;
	char *result_array;
	assertEqual(filter_char(array,length,&result_array,greater_than_h), 3);
	assertEqual(result_array[0], 'o');
	assertEqual(result_array[1], 'q');
	assertEqual(result_array[2], 's');
	free(result_array);
}

void test_ii(){
	char array[]={};
	int length=0;
	char *result_array;
	assertEqual(filter_char(array,length,&result_array,greater_than_h), 0);
}

void change_letters(char *ele,int i,char **array){
	int j=0;
	while(ele[j]!=0){
		ele[j]=ele[j]+1;
		j++;
	}
}

void test_jj(){
	char sr_1[]={'a','b','c','\0'},sr_2[]={'d','e','f','\0'},sr_3[]={'g','h','i','\0'};
	char *array[]={sr_1,sr_2,sr_3};
	int length=3;
	assertEqual(forEach_string(array,length,change_letters), 1);
	assertEqual(strcmp(array[0],"bcd"), 0);
	assertEqual(strcmp(array[1],"efg"), 0);
	assertEqual(strcmp(array[2],"hij"), 0);
}

void test_kk(){
	char *array[]={};
	int length=0;
	assertEqual(forEach_string(array,length,change_letters), 0);
}

int square(int ele,int i,int *array){
	return array[i]*ele;
}

void test_ll(){
	int array[]={1,2,3,4,5},length=5,*mapped;
	mapped=map_int(array,length,square);
	assertEqual(mapped[0],1);
	assertEqual(mapped[1],4);
	assertEqual(mapped[2],9);
	assertEqual(mapped[3],16);
	assertEqual(mapped[4],25);
	free(mapped);
}

float into_four(float ele){
	return ele*4;
}

void test_mm(){
	float array[]={1.5,2.5,3.5,4.5,5.5};
	float *mapped;
	int length=5;
	mapped=map_float(array,length,into_four);
	assertEqual(mapped[0],6);
	assertEqual(mapped[1],10);
	assertEqual(mapped[2],14);
	assertEqual(mapped[3],18);
	assertEqual(mapped[4],22);
	free(mapped);
}

char jumping(char ele,int i){
	return ele+i;
}

void test_nn(){
	char array[]={'a','a','a','a','a'},*mapped;
	int length=5;
	mapped=map_char(array,length,jumping);
	assertEqual(mapped[0], 'a');
	assertEqual(mapped[1], 'b');
	assertEqual(mapped[2], 'c');
	assertEqual(mapped[3], 'd');
	assertEqual(mapped[4], 'e');
	free(mapped);
}

char *upper(char *ele,int i){
	return strupr(ele);
}

void test_oo(){
	char sr_1[]={'a','b','c','\0'},sr_2[]={'d','e','f','\0'},sr_3[]={'g','h','i','\0'};
	char *array[]={sr_1,sr_2,sr_3},**mapped;
	int length=3;
	mapped=map_string(array,length,upper);
	assertEqual(strcmp(mapped[0],"ABC"), 0);
	assertEqual(strcmp(mapped[1],"DEF"), 0);
	assertEqual(strcmp(mapped[2],"GHI"), 0);
	free(mapped);
}

int add(int x,int y){
	return x+y;
}

void test_pp(){
	int array[]={1,2,3,4,5},length=5,inital_value=0;
	assertEqual(reduce_int(array,length,inital_value,add), 15);
}

void test_qq(){
	int array[]={1,2,3,4,5},length=5,inital_value=15;
	assertEqual(reduce_int(array,length,inital_value,add), 30);
}

float least_among_float(float x,float y){
	return (x<y)?x:y;
}

void test_rr(){
	float array[]={1.5,2.5,3.5,4.5,5.5},inital_value=7.5;
	int length=5;
	float result=reduce_float(array,length,inital_value,least_among_float);
	assertEqual(abs(result), 1);
}

void test_ss(){
	float array[]={1.5,2.5,3.5,4.5,5.5},inital_value=0.5;
	int length=5;
	float result=reduce_float(array,length,inital_value,least_among_float);
	assertEqual(abs(result), 0);
}

int not_aa(char *ele){
	return strcmp(ele,"aa")==0;
}

void test_tt(){
	char *array[]={"aa","aa","bb","cc","aa","dd"};
	int length=6;
	char **result_array;
	result_array=(char **)malloc(sizeof(char)*length);
	assertEqual(filter_string(array,length,result_array,not_aa), 3);
	assertEqual(strcmp(result_array[0],"aa"),0);
	assertEqual(strcmp(result_array[1],"aa"),0);
	assertEqual(strcmp(result_array[2],"aa"),0);
	free(result_array);
}

char greatest_char(char a,char b){
	return (a>b)?a:b;
}

void test_uu(){
	char array[]={'a','b','c','d','e'};
	int length=5;
	char initial_value='a';
	assertEqual(reduce_char(array,length,initial_value,greatest_char), 'e');
}

void test_vv(){
	char array[]={'a','b','c','d','e'};
	int length=5;
	char initial_value='q';
	assertEqual(reduce_char(array,length,initial_value,greatest_char), 'q');
}

char *largest_string(char *a,char *b){
	return (strlen(a)>strlen(b))?a:b;
}

void test_ww(){
	char *array[] = {"aa","bbb","ccc","dddd","eeeeee"};
	int length=5;
	char *initial_Value = "";
	assertEqual(strcmp(reduce_string(array,length,initial_Value,largest_string),"eeeeee"),0);
}

void test_xx(){
	char *str = "ankur";
	char *substr = "nku";
	assertEqual(indexOf(str,substr),1);
}

void test_yy(){
	char *str = "ankur";
	char *substr = "ku";
	assertEqual(indexOf(str,substr),2);
}

void test_zz(){
	char *str = "helloloo";
	char *substr = "loo";
	assertEqual(indexOf(str,substr),5);
}

void test_aaa(){
	char *str = "hello";
	char *substr = "kk";
	assertEqual(indexOf(str,substr),-1);
}