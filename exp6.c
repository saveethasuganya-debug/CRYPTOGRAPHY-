#include <stdio.h>

int main()
{
    char cipher[100];
    int i, c, p;
    int a = 9, b = 21;
    int inv = 3;   // inverse of 9 mod 26

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            c = cipher[i] - 'A';
            p = (inv * (c - b + 26)) % 26;
            cipher[i] = p + 'A';
        }
    }

    printf("Plaintext: %s", cipher);

    return 0;
}
