#include <string.h>
#include <ctype.h>
#include "validation.h"

/* Return 1 if the ID is positive */
int validateID(int id)
{
    return id > 0;
}

/* Return 1 if the amount is non-negative */
int validateMoney(double amount)
{
    return amount >= 0.0;
}

/* Reject NULL, empty text, or spaces only */
int validateText(const char *text)
{
    if (text == NULL)
        return 0;

    while (*text != '\0') {
        if (!isspace((unsigned char)*text))
            return 1;

        text++;
    }

    return 0;
}

/* Basic email format validation */
int validateEmail(const char *email)
{
    if (email == NULL)
        return 0;

    const char *at = strchr(email, '@');

    if (at == NULL || at == email ||
        strchr(at + 1, '@') != NULL)
        return 0;

    const char *dot = strchr(at + 1, '.');

    if (dot == NULL || dot == at + 1 ||
        dot[1] == '\0')
        return 0;

    return 1;
}

/* Allow digits and common phone number symbols */
int validatePhone(const char *phone)
{
    int digits = 0;

    if (phone == NULL)
        return 0;

    for (int i = 0; phone[i] != '\0'; i++) {
        if (isdigit((unsigned char)phone[i])) {
            digits++;
        } else if (phone[i] != '+' &&
                   phone[i] != ' ' &&
                   phone[i] != '-' &&
                   phone[i] != '(' &&
                   phone[i] != ')') {
            return 0;
        }
    }

    return digits >= 7 && digits <= 15;
}
