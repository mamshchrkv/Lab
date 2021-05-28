#include "PolynomialFunction.h"
#include "VectorFunction.h"
#include <stdlib.h>
#include"pch.h"
#include <string.h>
const char* MSG[] = { "1.EXIT", "2.Enter Polynomial (in integer)", "3. Enter Polynomial (in double)", "4. Sum", "5. Sub" , "6. Scalar" , "7. Value", "8. Print list" };
const int SMSG = 8;
int getmenu() {
    int ch = 0;
    do {
        printf( "You're wrong. Try again!");
        for (int i = 0; i < SMSG; i++) {
            puts(MSG[i]);
        }
        puts("Make your choice: ");
        ch = getchar() - '0';
        while (getchar() != '\n') {}
    } while (ch < 1 || ch > SMSG);

    return ch;
}
int main() {
    int turn = 1;
    int res = 0;
    vector** PolynomsZ = NULL;
    vector** PolynomsR = NULL;
    int countR = 0;
    int countZ = 0;
    while (turn) {
        res = getmenu();
        switch (res) {
        case 1: {
            printf("Goodbye");
            turn = 0;
            break;
        }
        case 2: {
            PolynomsZ = (vector**)realloc(PolynomsZ, (countZ + 1) * sizeof(vector*));
            PolynomsZ[countZ] = create(sizeof(int));
            printf("Enter degree\n");
            int degree;
            scanf_s("%d", &degree);
            printf("Enter factors\n");
            int* q = (int*)calloc(degree + 1, sizeof(int));
            for (int i = 0; i < degree + 1; i++) {
                scanf_s("%d", q + i);
            }
            printf("Thanks\n");
            push(PolynomsZ[countZ], q, degree + 1, sizeof(int));
            free(q);
            countZ++;
            //scanf("%*c");
            break;
        }
        case 3: {
            PolynomsR = (vector**)realloc(PolynomsR, (countR + 1) * sizeof(vector*));
            PolynomsR[countR] = create(sizeof(int));
            printf("Enter degree\n");
            int degree;
            scanf_s("%d", &degree);
            printf("Enter factors\n");
            double* q = (double*)calloc(degree + 1, sizeof(double));
            for (int i = 0; i < degree + 1; i++) {
                scanf_s("%lf", q + i);
            }
            printf("Thanks\n");
            push(PolynomsR[countR], q, degree + 1, sizeof(double));
            free(q);
            countR++;
            //scanf("%*c");
            break;
        }
        case 4: {
            printf("Choose type:\n 1.Integer\n 2.Double\n");
            int choose;
            scanf_s("%d", &choose);
            switch (choose) {
            case 1: {
                PolynomsZ = (vector**)realloc(PolynomsZ, (countZ + 1) * sizeof(vector*));
                int NUM1, NUM2;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter NUM2\n");
                scanf_s("%d", &NUM2);
                PolynomsZ[countZ] = sumZ(PolynomsZ[NUM1], PolynomsZ[NUM2]);
                printf("Sum result: ");
                printZ(PolynomsZ[countZ]);
                countZ++;
                break;
            }
            case 2: {
                PolynomsR = (vector**)realloc(PolynomsR, (countR + 1) * sizeof(vector*));
                int NUM1, NUM2;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter NUM2\n");
                scanf_s("%d", &NUM2);
                PolynomsR[countR] = sumR(PolynomsR[NUM1], PolynomsR[NUM2]);
                printf("Sum result: ");
                printR(PolynomsR[countR]);
                countR++;
                break;
            }
            }
            //scanf("%*c");
            break;
        }
        case 5: {
            printf("Choose type:\n 1.Integer\n 2.Double\n");
            int choose;
            scanf_s("%d", &choose);
            switch (choose) {
            case 1: {
                int NUM1, NUM2;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter NUM2\n");
                scanf_s("%d", &NUM2);
                PolynomsZ = (vector**)realloc(PolynomsZ, (countZ + 1) * sizeof(vector*));
                PolynomsZ[countZ] = subZ(PolynomsZ[NUM1], PolynomsZ[NUM2]);
                printf("Sub result: ");
                printZ(PolynomsZ[countZ]);
                countZ++;
                break;
            }
            case 2: {
                int NUM1, NUM2;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter NUM2\n");
                scanf_s("%d", &NUM2);
                PolynomsR[countR] = subR(PolynomsR[NUM1], PolynomsR[NUM2]);
                printf("Sub result: ");
                printR(PolynomsR[countR]);
                countR++;
                break;
            }
            }
            //scanf("%*c");
            break;
        }
        case 6: {
            printf("Choose type:\n 1.Integer\n 2.Double\n");
            int choose;
            scanf_s("%d", &choose);
            switch (choose) {
            case 1: {
                int NUM1, NUM2;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter scalar\n");
                scanf_s("%d", &NUM2);
                scalarZ(PolynomsZ[NUM1], NUM2);
                printf("Result: ");
                printZ(PolynomsZ[NUM1]);
                break;
            }
            case 2: {
                int NUM1;
                double NUM2;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter scalar\n");
                scanf_s("%lf", &NUM2);
                scalarR(PolynomsR[NUM1], NUM2);
                break;
            }
            }
            //scanf("%*c");
            break;
        }
        case 7: {
            printf("Choose type:\n 1.Integer\n 2.Double\n");
            int choose;
            scanf_s("%d", &choose);
            switch (choose) {
            case 1: {
                int NUM1, c, result;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter point\n");
                PolynomsZ = (vector**)realloc(PolynomsZ, (countZ + 1) * sizeof(vector*));
                PolynomsZ[-1] = create(sizeof(int));
                printf("Enter degree\n");
                int degree;
                scanf_s("%d", &degree);
                printf("Enter factors\n");
                int* q = (int*)calloc(degree + 1, sizeof(int));
                for (int i = 0; i < degree + 1; i++) {
                    scanf_s("%d", q + i);
                }
                c = countZ++;
                result = gornerZ(PolynomsZ[NUM1], PolynomsZ[-1]);
                printf("Value at point: %d", result);
                break;
            }
            case 2: {
                int NUM1;
                double result;
                printf("Enter NUM1\n");
                scanf_s("%d", &NUM1);
                printf("Enter point\n");
                PolynomsR = (vector**)realloc(PolynomsR, (countR + 1) * sizeof(vector*));
                PolynomsR[-1] = create(sizeof(double));
                printf("Enter degree\n");
                int degree;
                scanf_s("%d", &degree);
                printf("Enter factors\n");
                double* q = (double*)calloc(degree + 1, sizeof(double));
                for (int i = 0; i < degree + 1; i++) {
                    scanf_s("%fl", q + i);
                }
                result = gornerR(PolynomsR[NUM1], PolynomsZ[-1]);
                break;
            }
            }
            //scanf("%*c");
            break;
        }
        case 8: {
            printf("Choose type:\n 1.Integer\n 2.Double\n");
            int choose;
            scanf_s("%d", &choose);
            switch (choose) {
            case 1: {
                for (int i = 0; i < countZ; i++) {
                    printf("%d)", i);
                    printZ(PolynomsZ[i]);
                }
            }
            case 2: {
                for (int i = 0; i < countR; i++) {
                    printf("%d)", i);
                    printR(PolynomsR[i]);
                }
            }
            }
            //scanf("%*c");
            break;
        }
        }
    }
    for (int i = 0; i < countZ; i++) {
        del(PolynomsZ[i]);
    }
    for (int i = 0; i < countR; i++) {
        del(PolynomsR[i]);
    }
    free(PolynomsZ);
    free(PolynomsR);
    return 0;
}