int main(){
    printf("Plaintext: \"%s\" \n",input);
    printf("Plain   : ");
    print_state(input);
    unsigned char key_128[16] = "202155530sehank";  
    unsigned char key_192[24] = "202155530sehankim123456"; 
    unsigned char key_256[32] = "202155530sehankim1234567890abcde";
    // printf("Key-128 size: %d bytes\n", (int)sizeof(key_128));
    // printf("Key-192 size: %d bytes\n", (int)sizeof(key_192));
    // printf("Key-256 size: %d bytes\n", (int)sizeof(key_256));
    for (int i=0;i<3;i++){
        if(i==0){
            // key 128
            printf("128 bits: ");
            AES(AES128, 10, key_128);
        }
        else if(i==1){
            // key 192
            printf("192 bits: ");
            AES(AES192, 12, key_192);
        }
        else {
            // key 256
            printf("256 bits: ");
            AES(AES256, 14, key_256);
        }
    }
    return 0;
}
