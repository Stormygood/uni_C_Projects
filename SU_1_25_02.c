#include <stdio.h>
#include <string.h>
#include <math.h>

void ex_1() {
    for (int i = 1; i < 11; i++) {
        printf("%d\n", i);
    }

}

void ex_2() {
    char toPrint[12] = "*";
    for (int i = 0; i < 10; i++) {
        printf("%s\n", toPrint);
        strcat(toPrint, "*");

    }

}

void ex_3() {
    //lines cycle(vertical spaces)
    for (int j = 1; j < 6; j++) {
        //rows counter (horizontal spaces)
        for (int i = 1; i < 11; i++) {
            if (j == 1 || j == 5) {
                if (i == 10) {
                    //if the counter reaches the rightmost position, print with a new line
                    printf("-\n");
                }else {printf("-");}
            }
            if (j == 2 || j == 3 || j == 4) {
                if (i == 1) {
                    printf("-");
                } else if (i == 10) {
                    printf("-\n");
                }else {
                    printf(" ");
                }
            }
        }
    }
}

void ex_4_1() {
    for (int j = 1; j < 6; j++) {
        for (int i = 1; i < 10; i++) {
            switch (j) {
                case 1:
                    if (i == 5) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    }else {
                        printf(" ");
                    }
                    break;
                case 2:
                    if (i == 4 || i == 6) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    } else {
                        printf(" ");
                    }
                    break;
                case 3:
                    if (i == 3 || i == 7) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    }else {
                        printf(" ");
                    }
                    break;
                case 4:
                    if (i == 2 || i == 8) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    }else {
                        printf(" ");
                    }
                    break;
                case 5:
                    printf("&");
                    break;
                default:
                    break;
            }
        }
    }
}

void ex_4_2() {
    for (int j = 1; j < 6; j++) {
        for (int i = 1; i < 10; i++) {
            switch (j) {
                case 1:
                    if (i == 9) {
                        printf("&\n");
                    } else {
                        printf("&");
                    }
                    break;
                case 2:
                    if (i == 2 || i == 8) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    }else {
                        printf(" ");
                    }
                    break;
                case 3:
                    if (i == 3 || i == 7) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    }else {
                        printf(" ");
                    }
                    break;
                case 4:
                    if (i == 4 || i == 6) {
                        printf("&");
                    } else if (i == 9) {
                        printf(" \n");
                    } else {
                        printf(" ");
                    }

                    break;
                case 5:
                    if (i == 5) {
                        printf("&");
                    } else {
                        printf(" ");
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
void convert(float unit) {
    printf("In milimeters, that's: %.1f\n", unit * 25.4);
    printf("In centimeters, that's: %.2f\n", unit * 2.54);
    printf("In meters, that's: %.3f\n", unit * 0.0254);

}

void ex_5() {
    float inches;
    printf("Convert inches to other units: \n");
    scanf("%f", &inches);
    //Защо IDE-то мрънка за strtof
    convert(inches);
}
void ex_6() {
    float celsius;
    printf("Convert Celsius to Farenheit: \n");
    scanf("%f", &celsius);
    printf("The temp in Farenheit is: %.2f", celsius + 32);
}

void ex_7() {
    int input;
    printf("Please, ebter the degrees: \n");
    scanf("%d", &input);

    printf("The converted degrees turned into radians are: %f", input*3.14/180);
}

void ex_8() {
    int money;
    printf("Please, enter money value: ");
    scanf("%d", &money);;
    printf("The conversion rate is:\nLev - > USD: %.2f\nLev -> Euro: %.2f\nLev ->Pounds: %.2f", money / 1.69, money/1.96, money/2.27);
}

void ex_9() {
    float base_1;
    float base_2;
    float h;

    printf("Please, enter height: \n");
        scanf(("%f"), &h);
    printf("Please, enter Base1t: \n");
        scanf(("%f"), &base_1);
    printf("Please, enter Base 2P: \n");;
        scanf(("%f"), &base_2);
    printf("Area is: %f", ((base_1 + base_2)*h)/2);


}

void ex_10() {
    int angle;
    printf("Enter value of angle: \n");
    scanf("%d", &angle);;
    printf("The converted valu in radians in: %f", angle * 3.14/180);
}

void ex_12() {
    int x_1;
    int x_2;
    int x_3;
    int y_1;
    int y_2;
    int y_3;

    printf("enter first coordinates pair:  \n");
        scanf("%d", &x_1);
        scanf("%d", &y_1);
    // printf("%d %d", x_1, y_1);
    // printf("%d %d\n", x_1, y_1);
    printf("enter second coordinates pair: \n");
    scanf("%d", &x_2);
    scanf("%d", &y_2);
    printf("enter third coordinates pair:  \n");
    scanf("%d", &x_3);
    scanf("%d", &y_3);
    printf("Area of the triangle is: %d", (abs(x_1*y_2 + x_2*y_3 + x_3*y_1 - x_1*y_3 - x_3*y_2 - x_1*y_2))/2);
}

void ex_11() {
    int x_1;
    int x_2;
    int y_1;
    int y_2;
    int x_3;
    int y_3;

    printf("enter first coordinates pair:  \n");
    scanf("%d", &x_1);
    scanf("%d", &y_1);
    // printf("%d %d", x_1, y_1);
    // printf("%d %d\n", x_1, y_1);
    printf("enter second coordinates pair: \n");
    scanf("%d", &x_2);
    scanf("%d", &y_2);
    x_3 = x_2;
    y_3 = y_1;
    // printf("%d %d", x_3, y_3);
    printf("Area of the rectangle is: %d", (abs(x_1*y_2 + x_2*y_3 + x_3*y_1 - x_1*y_3 - x_3*y_2 - x_1*y_2)));
}

void ex_13() {
    printf("Hall area\n4");
    float area_desk = 0.7*1.2;
    float area_podium_and_door = area_desk*3;
    float length;
    float width;
    scanf("%f %f", &length, &width);
    //gets the free area for desks by subtracting from the full area of the room, the area of the hallway, the podium and the door
    printf("Area of the entire room is: %.2f\n", width*length - area_podium_and_door - length);
    //finds how many desks, theoretically, can fit in the room by dividing the area of the room, by the area of a singular desk.
    printf("%.0f", (width*length - area_podium_and_door - length)/area_desk);

}

void ex_14() {
    printf("Veggies & Fruits\n");
    float veggie_price;
    float fruit_price;
    int veggie_kilos;
    int fruit_kilos;

    scanf("%f", &veggie_price);
    scanf("%f", &fruit_price);
    scanf("%d", &veggie_kilos);
    scanf("%d", &fruit_kilos);

    float veggie_wins = veggie_price * veggie_kilos;
    float fruit_wins = fruit_price * fruit_kilos;
    // printf("Sold veggies: %.2f", veggie_wins);
    printf("Sold fruits: %.2f Lev -> %.2f EUR\n", veggie_wins, veggie_wins/1.96);

    // printf("Sold veggies: %.2f", fruit_wins);
    printf("Solf veggies: %.2f Lev -> %.2f EUR", fruit_wins, fruit_wins/1.96);
}

void ex_15() {
    int side;
    int bench_area = 2;
    int tile_width;
    int tile_length;

    scanf("%d", &side);
    scanf("%d", &tile_width);
    scanf("%d", &tile_length);

    printf("Required tiles: %.2f\n", (pow(side, 2) - bench_area )/ (tile_width * tile_length));
    printf("Time required: %.2f minutes", ((pow(side, 2) - bench_area )/ (tile_width * tile_length))*0.2);
}

void ex_16() {
    int working_days;
    float daily_wage;
    float conversion_rate;
    scanf("%d", &working_days);
    scanf("%f", &daily_wage);
    scanf("%f", &conversion_rate);

    float monthly_salary = daily_wage * working_days;
    float bonus = monthly_salary * 2;

    printf("%.2f", monthly_salary);
}
int main() {
    // ex_5();

    // printf("The sine of 30 is: %f", sin(30));
    // ex_11();
    int code;
    printf("Enter work code: \n");
    scanf("%d", &code);
    switch (code) {
        case 1:
            ex_1();
            break;
        case 2:
            ex_2();
            break;
        case 3:
            ex_3();
            break;
        case 4:
            float subcode;
            printf("Variant?\n");
            scanf("%d", &code);
            if (code == 1) {
                ex_4_1();
            } else {
                ex_4_2();
            }
            break;
        case 5:
            ex_5();
            break;
        case 6:
            ex_6();
            break;
        case 7:
            ex_7();
            break;
        case 8:
            ex_8();
            break;
        case 9:
            ex_9();
            break;
        case 10:
            ex_10();
            break;
        case 11:
            ex_11();
            break;
        case 12:
            ex_12();
            break;
        case 13:
            ex_13();
            break;
        case 14:
            ex_14();
            break;
        case 15:
            ex_15();
            break;
        case 16:
            ex_16();
            break;
        default:
            break;
    }
    return 0;


}
