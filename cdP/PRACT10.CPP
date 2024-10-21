#include <stdio.h>
#include <string.h>

void pm(char abc[], char exp1[], int& addr);
void plus(char abc[], char exp1[], int& addr);
void div(char abc[], char exp1[], int& addr);

int main() {
    int ch, i, j, l, addr = 100;
    char ex[10], abc[20], exp1[20], xyz[20], id1[5], op[5], id2[5];

    while (1) {
        printf("\n1. Assignment\n2. Arithmetic\n3. Relational\n4. Exit\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                printf("\nEnter the expression with assignment operator: ");
                scanf("%s", abc);
                l = strlen(abc);
                xyz[0] = '\0';
                i = 0;

                while (abc[i] != '=' && i < l) {
                    xyz[i] = abc[i];
                    i++;
                }
                xyz[i] = '\0'; // Null-terminate the identifier part
                strcpy(exp1, abc + i + 1); // Right-hand side after '='
                
                printf("\nThree address code:\ntemp = %s\n%s = temp\n", exp1, xyz);
                break;
            }

            case 2: {
                printf("\nEnter the expression with arithmetic operator: ");
                scanf("%s", ex);
                strcpy(abc, ex);
                l = strlen(abc);
                exp1[0] = '\0';

                for (i = 0; i < l; i++) {
                    if (abc[i] == '+' || abc[i] == '-') {
                        if (i + 2 < l && (abc[i + 2] == '/' || abc[i + 2] == '*')) {
                            pm(abc, exp1, addr);
                            break;
                        } else {
                            plus(abc, exp1, addr);
                            break;
                        }
                    } else if (abc[i] == '/' || abc[i] == '*') {
                        div(abc, exp1, addr);
                        break;
                    }
                }
                break;
            }

            case 3: {
                printf("Enter the expression with relational operator: ");
                scanf("%s %s %s", id1, op, id2);
                if ((strcmp(op, "<") != 0) && (strcmp(op, ">") != 0) &&
                    (strcmp(op, "<=") != 0) && (strcmp(op, ">=") != 0) &&
                    (strcmp(op, "==") != 0) && (strcmp(op, "!=") != 0)) {
                    printf("Expression is error\n");
                } else {
                    printf("\n%d\tif %s %s %s goto %d\n", addr, id1, op, id2, addr + 3);
                    addr++;
                    printf("%d\tT := 0\n", addr);
                    addr++;
                    printf("%d\tgoto %d\n", addr, addr + 2);
                    addr++;
                    printf("%d\tT := 1\n", addr);
                }
                break;
            }

            case 4:
                return 0; // Exit the program

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void pm(char abc[], char exp1[], int& addr) {
    int l = strlen(abc);
    int i = 0;

    // Find the position of the operator
    while (abc[i] != '+' && abc[i] != '-' && i < l) {
        i++;
    }
    strncpy(exp1, abc, i); // left side of the operator
    exp1[i] = '\0'; // Null-terminate the string

    printf("Three address code:\ntemp = %s\n", exp1);
    printf("temp1 = temp %c %c\n", abc[i], abc[i + 1]);
}

void div(char abc[], char exp1[], int& addr) {
    int i = 0;
    while (abc[i] != '/' && abc[i] != '*' && i < strlen(abc)) {
        i++;
    }
    strncpy(exp1, abc, i + 2); // include the operator and next character
    exp1[i + 2] = '\0'; // Null-terminate the string
    printf("Three address code:\ntemp = %s\n", exp1);
    printf("temp1 = temp %c %c\n", abc[i], abc[i + 1]);
}

void plus(char abc[], char exp1[], int& addr) {
    int i = 0;
    while (abc[i] != '+' && abc[i] != '-' && i < strlen(abc)) {
        i++;
    }
    strncpy(exp1, abc, i + 2); // include the operator and next character
    exp1[i + 2] = '\0'; // Null-terminate the string
    printf("Three address code:\ntemp = %s\n", exp1);
    printf("temp1 = temp %c %c\n", abc[i], abc[i + 1]);
}
