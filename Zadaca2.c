#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

char* convert_month(char* month);

int main() {
    char date[MAX_LEN];
    char* day_str;
    char* month_str;
    char* year_str;
    int day;
    int year;

    while(1)
    {
    printf("Внесете датум во обликот DD/MM/YYYY: ");
    scanf("%s", date);

    day_str = strtok(date, "/");
    month_str = strtok(NULL, "/");
    year_str = strtok(NULL, "/");

    day = atoi(day_str);
    year = atoi(year_str);

    printf("%d %s %d\n", day, convert_month(month_str), year);
    }
    return 0;
}

char* convert_month(char* month) {
    if (strcmp(month, "01") == 0) {
        return "јануари";
    } else if (strcmp(month, "02") == 0) {
        return "февруари";
    } else if (strcmp(month, "03") == 0) {
        return "март";
    } else if (strcmp(month, "04") == 0) {
        return "април";
    } else if (strcmp(month, "05") == 0) {
        return "мај";
    } else if (strcmp(month, "06") == 0) {
        return "јуни";
    } else if (strcmp(month, "07") == 0) {
        return "јули";
    } else if (strcmp(month, "08") == 0) {
        return "август";
    } else if (strcmp(month, "09") == 0) {
        return "септември";
    } else if (strcmp(month, "10") == 0) {
        return "октомври";
    } else if (strcmp(month, "11") == 0) {
        return "ноември";
    } else if (strcmp(month, "12") == 0) {
        return "декември";
    }
    return "невалиден месец";
}
