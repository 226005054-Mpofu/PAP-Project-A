
#ifndef VALIDATION_H
#define VALIDATION_H

/* Validate identification numbers */
int validateID(int id);

/* Validate financial amounts */
int validateMoney(double amount);

/* Validate names and other text */
int validateText(const char *text);

/* Validate email addresses */
int validateEmail(const char *email);

/* Validate telephone numbers */
int validatePhone(const char *phone);

#endif
