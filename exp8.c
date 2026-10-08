#include <stdio.h>
#include <string.h>

int main() {
    char key[]="CIPHER";
    char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[27];
    char text[100];
    int used[26]={0};
    int i,j=0;

    for(i=0;key[i];i++) {
        int x=key[i]-'A';
        if(!used[x]) {
            cipher[j++]=key[i];
            used[x]=1;
        }
    }

    for(i=0;i<26;i++)
        if(!used[i])
            cipher[j++]=alphabet[i];

    cipher[26]='\0';

    printf("Cipher alphabet: %s\n",cipher);

    printf("Enter plaintext: ");
    scanf("%s",text);

    for(i=0;text[i];i++)
        text[i]=cipher[text[i]-'A'];

    printf("Ciphertext: %s",text);

    return 0;
}
