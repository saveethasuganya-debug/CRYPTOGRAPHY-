#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[500];
    char plain[500];
    int freq[26] = {0};
    int map[26];
    int i, j, max;

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    /* Count frequency */
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            freq[cipher[i] - 'A']++;
    }

    /* Display frequency */
    printf("\nLetter Frequency:\n");

    for(i = 0; i < 26; i++)
        printf("%c = %d\n", 'A' + i, freq[i]);

    /* Find most frequent letter */
    max = 0;

    for(i = 1; i < 26; i++)
    {
        if(freq[i] > freq[max])
            max = i;
    }

    printf("\nMost frequent letter = %c\n", 'A' + max);

    /* Assume most frequent letter represents E */
    for(i = 0; i < 26; i++)
        map[i] = i;

    map[max] = 'E' - 'A';

    /* Decrypt */
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            plain[i] = map[cipher[i] - 'A'] + 'A';
        else
            plain[i] = cipher[i];
    }

    plain[i] = '\0';

    printf("\nPossible plaintext:\n%s", plain);

    return 0;
}
