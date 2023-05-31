#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//  used to get only the contents of ast-dump from here to the end
int HERE; 

struct data_t {
    uint8_t buffer[8];
    int x;
};

#define SIZE (sizeof(struct data_t))

uint8_t src[SIZE];

void function1(int idx) {
    struct data_t* data = (struct data_t*) malloc(sizeof(struct data_t));
    struct data_t* tmp = data;

    printf("B:%c\n", tmp->buffer[idx]);
    free(data);
}

int main() {
    printf("size %ld\n", SIZE);
    int idx;
    scanf("%d", &idx);
    function1(idx);
    return 0;
}