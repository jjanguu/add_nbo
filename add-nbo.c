#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t add(uint32_t a1, uint32_t a2) {
    return a1 + a2;
}

int main(int argc, char *argv[]) {
    uint32_t a1=0, a2=0;
    FILE *f;
    f = fopen(argv[1],"rb");
    fread(&a1, sizeof(a1),1,f);
    f = fopen(argv[2],"rb");
    fread(&a2, sizeof(a2),1,f);
    a1 = ntohl(a1);
    a2 = ntohl(a2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a1,a1,a2,a2,add(a1,a2),add(a1,a2));
    return 0;
}
