#include "nbo.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("usage : ./add-nbo <file1> <file2>\n");
        return 1;
    }

    FILE *FP1, *FP2;
    uint32_t a, b, s, check1, check2;

    FP1 = fopen(argv[1], "rb");
    FP2 = fopen(argv[2], "rb");

    if (!FP1 || !FP2){
        printf("fopen error : %s\n", strerror(errno));
        file_close(FP1, FP2);
        return 1;
    }

    check1 = fread(&a, sizeof(uint32_t), 1, FP1); check2 = fread(&b, sizeof(uint32_t), 1, FP2);

    if (check1 != 1 || check2 != 1 ){
        file_close(FP1, FP2);
        printf("fread error\n");
        return 1;
    }

    a = ntohl(a);
    b = ntohl(b);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);

    file_close(FP1, FP2);
    return 0;
}
