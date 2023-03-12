#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main() {
    char phone_number[MAX_LEN];
    char* country_code_str;
    char* phone_number_str;
    int country_code;
    long phone_number_int;

    printf("Внесете телефонски број во облик (333) 333-3333: ");
    scanf("%s", phone_number);

    // извлекување на кодот на државата со strtok
    country_code_str = strtok(phone_number, "()");

    // спојување на целиот телефонски број без -
    phone_number_str = strtok(NULL, "-");
    while (phone_number_str != NULL) {
        strcat(country_code_str, phone_number_str);
        phone_number_str = strtok(NULL, "-");
    }

    // конвертирање на кодот на државата во int
    country_code = atoi(country_code_str);

    // конвертирање на седмоцифрениот телефонски број во long
    phone_number_int = atol(phone_number_str);

    // испечатување на кодот на државата и телефонскиот број
    printf("Код на државата: %d\n", country_code);
    printf("Телефонски број: %ld\n", phone_number_int);

    return 0;
}
