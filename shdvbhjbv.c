#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int main(){
    ex_3();
    return 0;
}