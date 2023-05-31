#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HERE;

// #define PUBKEY_SIZE 32
// #define HASH_SIZE 32
// #define BLOCKHASH_SIZE HASH_SIZE

// typedef struct PubkeysHeader {
//     uint8_t num_required_signatures; // 1
//     // 8 - poison
//     uint8_t num_readonly_signed_accounts; // 1
//     // 8 - poison
//     uint8_t num_readonly_unsigned_accounts; // 1
//     // 8 - poison
//     size_t pubkeys_length; // 8
//     // 8 - poison
//     uint8_t random_data[32];
// } PubkeysHeader;

// typedef struct Hash {
//     uint8_t data[HASH_SIZE];
// } Hash;

// typedef struct Hash Blockhash;

// typedef struct Pubkey {
//     uint8_t data[PUBKEY_SIZE];
// } Pubkey;

// typedef struct MessageHeader {
//     PubkeysHeader pubkeys_header; // 64
//     // 8 poison
//     const Pubkey* pubkeys; // 8
//     // 8 poison
//     const Blockhash* blockhash; // 8
//     // 8 poison
//     size_t instructions_length; // 8
//     // 8 poison
// } MessageHeader;


// typedef struct PrintConfig {
//     MessageHeader header; // 120
//     // 8 - poison
//     bool expert_mode; // 1
//     // 7 - poison
//     // 8 - poison
//     const Pubkey* signer_pubkey; // 8
//     // 8 - poison
// } PrintConfig; // 160

// struct X {
//     uint8_t a; // 1
//     // 8 - poison
//     uint8_t b[16]; // 16
//     // 8 - poison
//     uint8_t d; // 1
// };

// struct Y {
//     uint8_t e; // 1
//     // 8 - poison
//     struct X f;
// };


// struct C {
//     uint8_t g[8];
//     // 8 - poison
//     struct X h;
//     // 8 - poison
//     struct Y i;
// };

// union U {
//     int x;
//     uint64_t y;
//     char z[20];
// };

// struct containU {
//     union U u;
//     // 8 - poison
//     int x; // 4
//     // 8 - poison
// } __attribute__ ((randomize_layout));


struct vla {
    int len; // 4
    // bb
    // struct {
    //     int a; // 4
    //     // bb
    //     int b; // 4
    //     // bb
    // };
    // // bb
    int64_t x[];
};

int main() {
    int len = 4;
    struct vla* x = (struct vla*) malloc(sizeof(struct vla) + len * sizeof(int64_t));
    
    x->len = len;
    // x->a = 1;
    // x->b = 2;

    for (int i = 0; i < len; i++) {
        x->x[i] = i * 7;
    }
    memset(x, 0, sizeof(*x));
    free(x);

    // printf("sizeof(vla) = 0x%lx\n", sizeof(struct vla));

    // printf("sizeof(Y) = 0x%lx\n", sizeof(struct Y));
    // printf("sizeof(X) = 0x%lx\n", sizeof(struct X));
    return 0;
}
