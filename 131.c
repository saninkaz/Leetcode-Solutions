#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>





int palindrome(char* s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--]) {
            return 0;
        }
    }
    return 1;
}

void func(int index, char* s, char** subset, char*** result, int* resultindex,
          int subsetindex, int** returnColumnSizes) 
          {
                if (index == strlen(s)) {
        result[*resultindex] = malloc(((subsetindex+1)*100000) * sizeof(char*));
        (*returnColumnSizes)[*resultindex] = subsetindex;
        for (int i = 0; i < subsetindex; i++) {
            result[*resultindex][i] = malloc((strlen(subset[i]) + 1) * sizeof(char));
            strcpy(result[*resultindex][i], subset[i]);
        }
        (*resultindex)++;
        return;
    }

    for (int i = index; i < strlen(s); i++) {
        if (palindrome(s, index, i)) {
            subset[subsetindex] = malloc((strlen(s) + 1) * sizeof(char));
            strncpy(subset[subsetindex], s + index, i - index + 1);
            subset[subsetindex][i - index + 1] = '\0';
            func(i + 1, s, subset, result, resultindex, subsetindex + 1,
                 returnColumnSizes);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    char*** result = malloc(10000 * sizeof(char**));
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    char** subset = malloc(strlen(s) * sizeof(char*));
    /// char* string=malloc(6400000*sizeof(char));
    int resultindex = 0;
    func(0, s, subset, result, &resultindex, 0, returnColumnSizes);
    *returnSize = resultindex;
    return result;
}

int main()
{
    char s[100000];
    scanf("%s",s);

    char*** answer=malloc(sizeof(char**)*100000);
    int returnsize=0;
    int *returncsize;
    answer=partition(s,&returnsize,&returncsize);
    for(int i=0;i<returnsize;i++)
    {
        for(int j=0;j<returncsize[i];j++)
        {
            printf("%s ",answer[i][j]);
        }
        printf("\n");
    }
}