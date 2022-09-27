#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(char* s1, char* s2) {
// int temp=0;
int count=0;
// int len1=strlen(s1);
// int len2=strlen(s2);
// for (int i=0;i<len2;i++){
//         for(int j=temp;j<len1;j++){
//             if(s2[i]==s1[j]){
//                 temp=j;
//                 count+=1;
//                 break;
//             }
//         }
// }
// int size1=len1-count;
// int size2=len2-count;
// int value=size1+size2;
int value=0;
int arr[26]={0},arr1[26]={0};
int std1=0,std2=0;
for(int i=0;i<strlen(s1);i++){
    int temp=s1[i]-'a';
    arr[temp]++;
}
for(int i=0;i<strlen(s2);i++){
    int temp=s2[i]-'a';
    arr1[temp]++;
}
// for(int i=0;i<strlen(s2);i++){
//     printf("%d ",arr[i]);
// }

for(int i=0;i<26;i++){
    value+=abs(arr[i]-arr1[i]);
}
return value;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s1 = readline();

    char* s2 = readline();

    int result = makingAnagrams(s1, s2);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
