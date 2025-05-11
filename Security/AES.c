#include <stdio.h>
#include <string.h>
#define AES128 16
#define AES192 24
#define AES256 32

unsigned char Sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
    0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
    0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
    0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
    0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
    0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
    0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
    0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
    0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
    0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
    0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
    0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
    0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
    0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
    0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
    0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
    0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

unsigned char InvSbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38,
    0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87,
    0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d,
    0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2,
    0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16,
    0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda,
    0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a,
    0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02,
    0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea,
    0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85,
    0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89,
    0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20,
    0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31,
    0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d,
    0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0,
    0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26,
    0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

unsigned char Rcon[11] = {
    0x00, // 사용 안함
    0x01, 0x02, 0x04, 0x08, 0x10,
    0x20, 0x40, 0x80, 0x1B, 0x36
};

// 함수 프로토타입 선언
void KeyExpansion(unsigned char* key, unsigned char* expandedKey, int keyLen, int round);
void SubBytes(unsigned char* state);
void ShiftRowTrans(unsigned char* state);
void MixColumnTrans(unsigned char* state);
void AddRoundKey(unsigned char* state, unsigned char* roundKey);
void InvMixColumnTrans(unsigned char* state);
void InvShiftRowTrans(unsigned char* state);
void InvSubBytes(unsigned char* state);
void RotWord(unsigned char* word);
void SubWord(unsigned char* word);
unsigned char gmul(unsigned char a, unsigned char b);

// AES 블록 암호화
void AES_encrypt_block(unsigned char* input, unsigned char* output, unsigned char* key, int keyLen, int round) {
    unsigned char state[16];
    memcpy(state, input, 16);

    unsigned char expandedKey[240]; // 최대 크기로 설정 (AES-256 기준 240 바이트 필요)
    KeyExpansion(key, expandedKey, keyLen, round);

    AddRoundKey(state, expandedKey);
    for (int i = 1; i < round; i++) {
        SubBytes(state);
        ShiftRowTrans(state);
        MixColumnTrans(state);
        AddRoundKey(state, &expandedKey[i * 16]);
    }
    SubBytes(state);
    ShiftRowTrans(state);
    AddRoundKey(state, &expandedKey[round * 16]);

    memcpy(output, state, 16);
}

// AES 블록 복호화
void AES_decrypt_block(unsigned char* input, unsigned char* output, unsigned char* key, int keyLen, int round) {
    unsigned char state[16];
    memcpy(state, input, 16);

    unsigned char expandedKey[240]; // 최대 크기로 설정
    KeyExpansion(key, expandedKey, keyLen, round);

    AddRoundKey(state, &expandedKey[round * 16]);
    for (int i = round - 1; i >= 1; i--) {
        InvShiftRowTrans(state);
        InvSubBytes(state);
        AddRoundKey(state, &expandedKey[i * 16]);
        InvMixColumnTrans(state);
    }
    InvShiftRowTrans(state);
    InvSubBytes(state);
    AddRoundKey(state, expandedKey);

    memcpy(output, state, 16);
}

// 패딩 함수 (PKCS#7)
int pad(unsigned char* input, int len, unsigned char* output) {
    int padding_len = 16 - (len % 16);
    memcpy(output, input, len);
    for (int i = 0; i < padding_len; i++) {
        output[len + i] = padding_len;
    }
    return len + padding_len;
}

// 패딩 제거 함수
int unpad(unsigned char* input, int len) {
    int pad = input[len - 1];
    return len - pad;
}

// 상태 출력
void print_hex(const char* label, unsigned char* data, int len) {
    printf("%s", label);
    for (int i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

// AES Process
void aes_process(unsigned char* input, int len, unsigned char* key, int keyLen, int round) {
    unsigned char padded[32];
    int padded_len = pad(input, len, padded);

    unsigned char ciphertext[32];
    for (int i = 0; i < padded_len; i += 16) {
        AES_encrypt_block(padded + i, ciphertext + i, key, keyLen, round);
    }

    unsigned char decrypted[32];
    for (int i = 0; i < padded_len; i += 16) {
        AES_decrypt_block(ciphertext + i, decrypted + i, key, keyLen, round);
    }

    int decrypted_len = unpad(decrypted, padded_len);

    printf("Original : %s\n", input);
    print_hex("Encrypted: ", ciphertext, padded_len);
    printf("Decrypted: ");
    for (int i = 0; i < decrypted_len; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");
}

// SubBytes 구현
void SubBytes(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        state[i] = Sbox[state[i]];
    }
}

// ShiftRowTrans 구현
void ShiftRowTrans(unsigned char* state) {
    unsigned char temp[16];
    memcpy(temp, state, 16);

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            state[row + 4 * col] = temp[row + 4 * ((col + row) % 4)];
        }
    }
}

// Galois Field 곱셈
unsigned char gmul(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    for (int i = 0; i < 8; i++) {
        if (b & 1)
            p ^= a;
        int high_bit_set = a & 0x80;
        a <<= 1;
        if (high_bit_set)
            a ^= 0x1b; // irreducible polynomial x^8 + x^4 + x^3 + x + 1
        b >>= 1;
    }
    return p;
}

// MixColumnTrans 구현
void MixColumnTrans(unsigned char* state) {
    unsigned char temp[16];
    memcpy(temp, state, 16);

    for (int col = 0; col < 4; col++) {
        int i = col * 4;

        unsigned char s0 = temp[i];
        unsigned char s1 = temp[i + 1];
        unsigned char s2 = temp[i + 2];
        unsigned char s3 = temp[i + 3];

        state[i]     = gmul(0x02, s0) ^ gmul(0x03, s1) ^ s2 ^ s3;
        state[i + 1] = s0 ^ gmul(0x02, s1) ^ gmul(0x03, s2) ^ s3;
        state[i + 2] = s0 ^ s1 ^ gmul(0x02, s2) ^ gmul(0x03, s3);
        state[i + 3] = gmul(0x03, s0) ^ s1 ^ s2 ^ gmul(0x02, s3);
    }
}

// AddRoundKey 구현
void AddRoundKey(unsigned char* state, unsigned char* roundKey) {
    for (int i = 0; i < 16; i++) {
        state[i] ^= roundKey[i];
    }
}

// RotWord 구현
void RotWord(unsigned char* word) {
    unsigned char temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}

// SubWord 구현
void SubWord(unsigned char* word) {
    for (int i = 0; i < 4; i++) {
        word[i] = Sbox[word[i]];
    }
}

// KeyExpansion 구현
void KeyExpansion(unsigned char* key, unsigned char* expandedKey, int keyLen, int round) {
    int i;
    unsigned char temp[4];
    int expandedKeySize = 16 * (round + 1); // 16바이트 * (라운드+1)

    for (i = 0; i < keyLen; i++) {
        expandedKey[i] = key[i];
    }

    int bytesGenerated = keyLen;
    int rconIter = 1;

    while (bytesGenerated < expandedKeySize) {
        for (i = 0; i < 4; i++) {
            temp[i] = expandedKey[bytesGenerated - 4 + i];
        }

        if (bytesGenerated % keyLen == 0) {
            RotWord(temp);
            SubWord(temp);
            temp[0] ^= Rcon[rconIter++];
        } else if (keyLen > 24 && (bytesGenerated % keyLen == 16)) {
            // AES-256 추가 처리
            SubWord(temp);
        }

        for (i = 0; i < 4; i++) {
            expandedKey[bytesGenerated] = expandedKey[bytesGenerated - keyLen] ^ temp[i];
            bytesGenerated++;
        }
    }
}

// InvMixColumnTrans 구현
void InvMixColumnTrans(unsigned char* state) {
    unsigned char temp[16];
    memcpy(temp, state, 16);

    for (int col = 0; col < 4; col++) {
        int i = col * 4;

        unsigned char s0 = temp[i];
        unsigned char s1 = temp[i + 1];
        unsigned char s2 = temp[i + 2];
        unsigned char s3 = temp[i + 3];

        state[i]     = gmul(0x0e, s0) ^ gmul(0x0b, s1) ^ gmul(0x0d, s2) ^ gmul(0x09, s3);
        state[i + 1] = gmul(0x09, s0) ^ gmul(0x0e, s1) ^ gmul(0x0b, s2) ^ gmul(0x0d, s3);
        state[i + 2] = gmul(0x0d, s0) ^ gmul(0x09, s1) ^ gmul(0x0e, s2) ^ gmul(0x0b, s3);
        state[i + 3] = gmul(0x0b, s0) ^ gmul(0x0d, s1) ^ gmul(0x09, s2) ^ gmul(0x0e, s3);
    }
}

// InvShiftRow 구현
void InvShiftRowTrans(unsigned char* state) {
    unsigned char temp[16];
    memcpy(temp, state, 16);

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            state[row + 4 * col] = temp[row + 4 * ((col - row + 4) % 4)];
        }
    }
}

// InvSubBytes 구현
void InvSubBytes(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        state[i] = InvSbox[state[i]];
    }
}

int main() {
    unsigned char input[] = "202155530sehanKim123";
    int inputLen = strlen((char*)input);

    unsigned char key128[16] = "202155530sehank";
    unsigned char key192[24] = "202155530sehankim123456";
    unsigned char key256[32] = "202155530sehankim1234567890abcde";

    // 128비트
    printf("=== AES-128 ===\n");
    aes_process(input, inputLen, key128, AES128, 10);

    // 192비트
    printf("\n=== AES-192 ===\n");
    aes_process(input, inputLen, key192, AES192, 12);

    // 256비트
    printf("\n=== AES-256 ===\n");
    aes_process(input, inputLen, key256, AES256, 14);

    return 0;
}