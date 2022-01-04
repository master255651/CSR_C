#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vars.h"
void CSR_encrypt(char* word)
{
    char* alphabet = GetAlphabet();
    char enc[25];
    int key, i, j, k;
    printf("key: ");
    scanf("%i", &key);
    for (i = 0; i < strlen(word); i++)
        for (j = 0; j < strlen(alphabet); j++)
            if (word[i] == alphabet[j])
            {
                if ((j + key) < strlen(alphabet))
                    enc[i] = alphabet[j + key];
                else
                {
                    k = (j + key) - strlen(alphabet);
                    enc[i] = alphabet[k];
                }
            }
    printf("encrypt: ");
    for (i = 0; i < strlen(word); i++)
        printf("%c", enc[i]);
    printf("\n");
}
void CSR_decrypt(char* word)
{
    char* alphabet = GetAlphabet();
    char dec[25];
    int key, i, j, k;
    printf("key: ");
    scanf("%i", &key);
    for (i = 0; i < strlen(word); i++)
        for (j = 0; j < strlen(alphabet); j++)
            if (word[i] == alphabet[j])
            {
                if ((j - key) > 0)
                    dec[i] = alphabet[j - key];
                else
                {
                    k = (j - key) + strlen(alphabet);
                    dec[i] = alphabet[k];
                    if(k > 25)
                    {
                        dec[i] = alphabet[k%26];
                    }
                }
            }
    printf("decrypt: ");
    for (i = 0; i < strlen(word); i++)
        printf("%c", dec[i]);
    printf("\n");
}
void CSR_enc_math(char* word)
{
    char* numbers = GetNumbers();
    char enc[25];
    int key, i, j, k;
    printf("key: ");
    scanf("%i", &key);
    for(i=0; i<strlen(word); i++)
        for(j=0; j<strlen(numbers); j++)
            if(word[i]==numbers[j])
            {
                k=(j+key)%strlen(numbers);
                enc[i]=numbers[k];
            }
    printf("encrypt: ");
    for (i = 0; i < strlen(word); i++)
        printf("%c", enc[i]);
    printf("\n");
}
void CSR_dec_math(char* word)
{
    char* numbers = GetNumbers();
    char dec[25];
    int key, i, j, k;
    printf("key: ");
    scanf("%i", &key);
    for(i=0; i<strlen(word); i++)
        for(j=0; j<strlen(numbers); j++)
            if(word[i]==numbers[j])
            {
                k=(j-key)%strlen(numbers);
                dec[i]=numbers[k];
            }
    printf("decrypt: ");
    for (i = 0; i < strlen(word); i++)
        printf("%c", dec[i]);
    printf("\n");
}

