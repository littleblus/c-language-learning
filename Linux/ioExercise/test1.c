#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* pf = fopen("blus", "w");
    char str[] = "Linux is not easy!";
    fwrite(str, sizeof(str), 1, pf);
    fclose(pf);
    char* tmp = (char*)malloc(100);
    pf = fopen("blus", "r");
    int ret = fread(tmp, sizeof(str), 1, pf);
    if (ret == 0) {
        printf("fread failed!\n");
    }
    else {
        printf("%s\n", tmp);
    }
    fclose(pf);
    free(tmp);
    return 0;
}