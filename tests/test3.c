#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// #define TX_FLAG_TYPE   0x01
#define ADDRESS_LENGTH 20
#define MAX_TICKER_LEN 12  // 10 characters + ' ' + '\0'
// #define INT128_LENGTH  16
#define INT256_LENGTH  32
#define MAX_ITEMS      2
#define MAX_BIP32_PATH 10
#define COLLECTION_NAME_MAX_LEN 70


typedef struct tokenDefinition_t {
    uint8_t address[ADDRESS_LENGTH];  // must be first item
#ifdef HAVE_CONTRACT_NAME_IN_DESCRIPTOR
    uint8_t contractName[ADDRESS_LENGTH];
#endif
    char ticker[MAX_TICKER_LEN];
    uint8_t decimals;
} tokenDefinition_t;

typedef struct nftInfo_t {
    uint8_t contractAddress[ADDRESS_LENGTH];  // must be first item
    char collectionName[COLLECTION_NAME_MAX_LEN + 1];
} nftInfo_t;

typedef struct bip32_path_t {
    uint8_t length;
    uint32_t path[MAX_BIP32_PATH];
} bip32_path_t;

typedef union extraInfo_t {
    tokenDefinition_t token;
    nftInfo_t nft;
} extraInfo_t;


typedef struct publicKeyContext_t {
    uint8_t publicKey[32];
    char address[41];
    uint8_t chainCode[INT256_LENGTH];
    bool getChaincode;
} publicKeyContext_t;



typedef struct transactionContext_t {
    bip32_path_t bip32;
    uint8_t hash[INT256_LENGTH];
    union extraInfo_t extraInfo[MAX_ITEMS];
    uint8_t tokenSet[MAX_ITEMS];
    uint8_t currentItemIndex;
} transactionContext_t;

typedef struct messageSigningContext_t {
    bip32_path_t bip32;
    uint8_t hash[INT256_LENGTH];
    uint32_t remainingLength;
} messageSigningContext_t;


typedef struct messageSigningContext712_t {
    bip32_path_t bip32;
    uint8_t domainHash[32];
    uint8_t messageHash[32];
} messageSigningContext712_t;

// typedef union {
//     publicKeyContext_t publicKeyContext;
//     transactionContext_t transactionContext;
//     messageSigningContext_t messageSigningContext;
//     messageSigningContext712_t messageSigningContext712;
// } tmpCtx_t;

//  struct bip32_path_t {
//      0x0000      |  0x0001     uint8_t length;
//      XXX 15-byte hole      
//      0x0010      |  0x0028     uint32_t path[10];
//      XXX  8-byte padding   
// }



// struct messageSigningContext_t {
//  0x0000      |  0x0040    bip32_path_t bip32;
//  XXX  8-byte hole     
//  0x0048      |  0x0020    uint8_t hash[32];
//  XXX  8-byte hole     
//  0x0070      |  0x0004    uint32_t remainingLength;
//  XXX 12-byte padding  
// }



typedef struct {
    messageSigningContext_t publicKeyContext;
} tmpCtx_t;


int HERE;

int main() {
    int holes = 8 + 12 + 8 + 8 + 8 + 15;
    printf("%ld\n", sizeof(tmpCtx_t) - holes);
    
    tmpCtx_t* context = (tmpCtx_t*) malloc(sizeof(tmpCtx_t));
    int size = 0;


    scanf("%d", &size);
    memset(context, 1, size);

    free(context);
    return 0;
}
