#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[100];
    float price;
    int number;
} Product;

typedef struct {
    char address[100];
    int productNumber;
} Order;

void ex_1(){
    float chair_price = 13.99;
    float table_price = 42.00;
    float cups_price = 5.98;
    float plates_price = 21.02;

    int guests = 0;
    
    //number of things ordered
    int num_tables = 0;
    int num_chairs = 0;
    int num_cups = 0;
    int num_plates = 0;

    //tells us how many sets of stuff is required to buy additionally in order to comfortably fit the guests
    int chairs_req;
    int tables_req;
    int cups_req;
    int plates_req;

    char prompt[10];

    printf("Enter number of guests: ");
    scanf("%d", &guests);

    getchar();

//     10
// Table
// Chair 
// Chair
// Chair
// Cups
// Cups
// Dishes
// PARTY!

    do{
        printf("Enter prompt: ");
        fgets(prompt, 10, stdin);

        prompt[strcspn(prompt, "\n")] = 0;
        
        if(strcmp(prompt, "Table") == 0){
            num_tables++;
        } else if(strcmp(prompt, "Chair") == 0){
            num_chairs++;
        } else if(strcmp(prompt, "Cups") == 0){
            num_cups++;
        } else if(strcmp(prompt, "Dishes") == 0){
            num_plates++;
        }

        // *prompt = (char *)calloc(10, sizeof(char));

    }while(strcmp(prompt, "PARTY!") != 0 && strcmp(prompt, "Party!") != 0);

    //  int chairs_req = guests - num_chairs;
    // int tables_req = ceil(guests / 8);
    // int cups_req = ceil(guests / 6);
    // int plates_req = ceil(guests / 6);

    chairs_req = guests - num_chairs;
    if(guests % 8 !=0){
        tables_req = ceil(guests / 8) + 1;
    }
    
    if((num_cups * 6) - guests < 0 && guests % 6 !=0){
        cups_req = ceil(guests / 6) + 1;
    }
    if((num_plates * 6) - guests < 0 && guests % 6 !=0){
        plates_req = ceil(guests / 6) + 1;
    }
    

    printf("%.2f\n", ((chair_price * num_chairs) + (table_price * num_tables) + (cups_price * num_cups) + (plates_price * num_plates)));

    if(chairs_req > num_chairs){
        printf("%d Chairs\n", chairs_req);
    } else if(tables_req > num_tables){
        printf("%d Chairs\n", tables_req);
    }else if(cups_req > num_cups){
        printf("%d Chairs\n", cups_req);
    }else if(plates_req > num_plates){
        printf("%d Chairs\n", plates_req);
    }
}



void ex_2() {
    Product products[100];
    int productCount = 0;

    Order pendingOrders[100];
    int pendingCount = 0;

    char command[20];

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "END") == 0) {
            break;
        }

        if (strcmp(command, "Product") == 0) {
            Product p;
            scanf("%s %f %d", p.name, &p.price, &p.number);
            products[productCount++] = p;

            for (int i = 0; i < pendingCount; i++) {
                if (pendingOrders[i].productNumber == p.number) {
                    printf("Client %s ordered %s\n", pendingOrders[i].address, p.name);

                    for (int j = i; j < pendingCount - 1; j++) {
                        pendingOrders[j] = pendingOrders[j + 1];
                    }
                    pendingCount--;
                    i--;
                }
            }
        }

        if (strcmp(command, "Order") == 0) {
            Order o;
            scanf("%s %d", o.address, &o.productNumber);

            int found = -1;
            for (int i = 0; i < productCount; i++) {
                if (products[i].number == o.productNumber) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                printf("Client %s ordered %s\n", o.address, products[found].name);
            } else {
                pendingOrders[pendingCount++] = o;
            }
        }
    }
}

void ex_3() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Cannot open input.txt\n");
        return;
    }

    char **words = NULL;
    int count = 0;
    char lastChar = '\0';
    char word[51];

    while (fscanf(fin, "%50s", word) == 1) {
        if (count == 0) {
            words = (char**)malloc(sizeof(char*));
            words[0] = (char*)malloc(strlen(word) + 1);
            strcpy(words[0], word);
            lastChar = word[strlen(word) - 1];
            count++;
        } else {
            if (word[0] == lastChar) {
                words = (char**)realloc(words, (count + 1) * sizeof(char*));
                words[count] = (char*)malloc(strlen(word) + 1);
                strcpy(words[count], word);
                lastChar = word[strlen(word) - 1];
                count++;
            }
        }
    }
    fclose(fin);

    // Write to binary file
    FILE *fbin = fopen("output.bin", "wb");
    if (!fbin) {
        printf("Cannot open output.bin\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fwrite(words[i], sizeof(char), strlen(words[i]), fbin);
        if (i < count - 1) {
            fwrite(" ", sizeof(char), 1, fbin);
        }
    }
    fclose(fbin);

    // Read and display binary file char by char
    FILE *fbinr = fopen("output.bin", "rb");
    if (!fbinr) {
        printf("Cannot open output.bin for reading\n");
        return;
    }
    char c;
    while (fread(&c, sizeof(char), 1, fbinr) == 1) {
        printf("%c", c);
    }
    printf("\n");
    fclose(fbinr);

    // Free dynamic memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

void ex_4() {
    char filename[100];
    int key;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter key (2-10): ");
    scanf("%d", &key);

    if (key < 2 || key > 10) {
        printf("Key must be between 2 and 10!\n");
        return;
    }

    // open input file for reading
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    // build output filename e.g. "text.txt" -> "text_encoded.txt"
    char out_filename[110];
    sprintf(out_filename, "encoded_%s", filename);

    // open output file for writing
    FILE *output = fopen(out_filename, "w");
    if (output == NULL) {
        printf("Could not create output file!\n");
        fclose(input);
        return;
    }

    // read char by char, shift each one by key, write to output
    char c;
    while ((c = fgetc(input)) != EOF) {
        fputc(c + key, output);
    }

    fclose(input);
    fclose(output);

    printf("Encoded file saved as: %s\n", out_filename);
}

void ex_6() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int count[26] = {0};

    for (int i = 0; str1[i] != '\0'; i++)
        if (isalpha(str1[i]))
            count[tolower(str1[i]) - 'a']++;

    for (int i = 0; str2[i] != '\0'; i++)
        if (isalpha(str2[i]))
            count[tolower(str2[i]) - 'a']--;

    int anagram = 1;
    for (int i = 0; i < 26; i++)
        if (count[i] != 0) { anagram = 0; break; }

    if (anagram)
        printf("Anagram!\n");
    else
        printf("Not an anagram!\n");
}

//--------------**EXERCISE 7**--------------------------------------------------------------------------------------------

#define MAX_EMPLOYEES 30
#define TAX_RATE 0.0365
#define OVERTIME_RATE 1.5
#define REGULAR_HOURS 40

typedef struct {
    int id;
    float hourly_pay;
    float hours_worked;
    float weekly_salary;
} Employee;

float calculate_salary(float hourly_pay, float hours_worked) {
    float gross = 0;

    if (hours_worked <= REGULAR_HOURS)
        gross = hourly_pay * hours_worked;
    else
        gross = (hourly_pay * REGULAR_HOURS) +
                (hourly_pay * OVERTIME_RATE * (hours_worked - REGULAR_HOURS));

    return gross - (gross * TAX_RATE);
}

int count_employees(FILE *file) {
    fseek(file, 0, SEEK_END);
    return ftell(file) / sizeof(Employee);
}

void add_employee() {
    FILE *file = fopen("employees.bin", "ab+");
    if (file == NULL) {
        printf("Could not open file!\n");
        return;
    }

    int current_count = count_employees(file);
    if (current_count >= MAX_EMPLOYEES) {
        printf("Maximum number of employees (%d) reached!\n", MAX_EMPLOYEES);
        fclose(file);
        return;
    }

    Employee emp;
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter hourly pay: ");
    scanf("%f", &emp.hourly_pay);
    printf("Enter hours worked this week: ");
    scanf("%f", &emp.hours_worked);

    emp.weekly_salary = calculate_salary(emp.hourly_pay, emp.hours_worked);

    fwrite(&emp, sizeof(Employee), 1, file);
    printf("Employee added successfully!\n");

    fclose(file);
}

void display_salaries() {
    FILE *file = fopen("employees.bin", "rb");
    if (file == NULL) {
        printf("No employee file found!\n");
        return;
    }

    int count = count_employees(file);
    if (count == 0) {
        printf("No employees on record!\n");
        fclose(file);
        return;
    }

    rewind(file); // go back to start after count_employees moved the pointer

    printf("\n%-10s %-15s %-15s %-15s\n",
           "ID", "Hourly Pay", "Hours Worked", "Weekly Salary");
    printf("-------------------------------------------------------\n");

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("%-10d %-15.2f %-15.2f %-15.2f\n",
               emp.id, emp.hourly_pay, emp.hours_worked, emp.weekly_salary);
    }

    printf("-------------------------------------------------------\n");
    printf("Total employees: %d\n", count);

    fclose(file);
}

void display_menu() {
    printf("\n===== EMPLOYEE MANAGEMENT =====\n");
    printf("1. Add employee\n");
    printf("2. Display all salaries\n");
    printf("3. Exit\n");
    printf("================================\n");
    printf("Choice: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_employee();    break;
            case 2: display_salaries(); break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}