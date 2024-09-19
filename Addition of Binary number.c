// Porgram to add binary number
#include<stdio.h>
#include<string.h>

int binaryToDecimal(char binary[]) {
    int decimal = 0, len = strlen(binary);

    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += 1 << (len - 1 - i);
        }
    }

    return decimal;
}

char* decimalToBinary(int decimal) {
    int binaryNum[32];
    int i = 0;

    while (decimal > 0) {
        binaryNum[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    char* binary = (char*)malloc((i + 1) * sizeof(char));
    binary[i] = '\0';

    for (int j = i - 1; j >= 0; j--) {
        if (binaryNum[j] == 1) {
            binary[i - 1 - j] = '1';
        } else {
            binary[i - 1 - j] = '0';
        }
    }

    return binary;
}

char* addBinary(char binary1[], char binary2[]) {
    int decimal1 = binaryToDecimal(binary1);
    int decimal2 = binaryToDecimal(binary2);

    int sum = decimal1 + decimal2;

    return decimalToBinary(sum);
}

int main() {
    char binary1[33], binary2[33];

    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    char* result = addBinary(binary1, binary2);

    printf("The sum of the two binary numbers is: %s\n", result);

    return 0;
}