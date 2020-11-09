#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//encrypts the cipher text
char *encrypt(char *plaintext){

    //permutation key
    int key[8] = {5, 2, 6, 0, 7, 3, 1, 4};

    //memory allocation
    char *ciphertext = (char *) malloc(9);


    int i = 0;
    while (plaintext[i] != '\0'){
        ciphertext[i] = plaintext[key[i]];
        i++;
    }
    return ciphertext;
}

//decrypts the cipher text
char *decrypt(char *ciphertext){

    //permutation key
    int decryptKey[8] = {3, 6, 1, 5, 7, 0, 2, 4};

    //memory allocation
    char *decryptedtext = (char *) malloc(9);


    int y = 0;
    while (ciphertext[y] != '\0'){
        decryptedtext[y] = ciphertext[decryptKey[y]];
        y++;
    }
    return decryptedtext;
}

//compares plaintext to recovered string
char *compare(char *x, char *y){
    int result = strcmp (x, y);
    if (result == 0){
        return "True";
    }
    else {
        return "False";
    }
}

//padding method
char *padding(char* plaintext){
    int size = strlen(plaintext);
    char *paddedtext = (char*) malloc(sizeof(char) *8);
    strcpy(paddedtext, plaintext);
    if (size != 8){
        size--;
    }
    while (size != 8){
        paddedtext[size]= '_';
        size++;
    }
    paddedtext[size] = '\0';
    return paddedtext;
}


//main method
int main() {

    char plaintext[9];

    //asks user for string
    printf("\nEnter a string: ");
    fgets(plaintext, 9, stdin);
    char *padded = padding(plaintext);

    printf("Plaintext = %s\n", padded);
    char *ciphertext = encrypt(padded);
    printf("Ciphertext = %s\n", ciphertext);
    char *decrypted = decrypt(ciphertext);
    printf("Recovered text = %s\n", decrypted);

    char *comparison = compare(padded, decrypted);
    printf("Recovered text == Plaintext? %s\n", comparison);


}

