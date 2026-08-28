#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
#define array_size 50

// UDFs
void addR(char par_name[], int par_bats, int par_hits);
void delR(char par_name[]);
void display();
void update(char par_name[]);
void save();
void retrieve();
void sortByAverage();

int locate(char par_name[]);
int menu();
int isFull();
int isEmpty();
int isValidStats(int par_bats, int par_hits);

float average(int par_bats, int par_hits);

// Global Var
int last = -1;

char player_name[MAX][array_size];
int bats[MAX], hits[MAX];

char current_file[array_size] = "bscs1ab2026.csv"; // default file

int main(){

    char main_name[array_size];
    int main_bats, main_hits;

    retrieve();// populate arrays with values from file

    while(1){
        switch(menu()){
        case 1:
            printf("Input name: ");
            fgets(main_name, array_size, stdin);
            main_name[strcspn(main_name, "\n")] = '\0';

            if(locate(main_name) != -1){
                printf("%s is already in record\n", main_name);
                system("pause");
                continue;
            }

            printf("Input number of bats: ");
            scanf("%d", &main_bats);

            printf("Input number of hits: ");
            scanf("%d", &main_hits);

            if(!isValidStats(main_bats, main_hits)){
                printf("Hits cannot be greater than bats!\n");
                system("pause");
                continue;
            }


            addR(main_name, main_bats, main_hits);
            break;
        case 2:
            printf("Input name: ");
            fgets(main_name, array_size, stdin);
            main_name[strcspn(main_name, "\n")] = '\0';
            delR(main_name);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Input name: ");
            fgets(main_name, array_size, stdin);
            main_name[strcspn(main_name, "\n")] = '\0';
            update(main_name);
            break;
        case 5:
            printf("Saving...\n");
            system("pause");
            save();
            exit(0);
        default:
            printf("1-5 lang po mam/ser\n");
            system("pause");
        }
    }

return 0;
}

void addR(char par_name[], int par_bats, int par_hits){

    if(isFull()){
        printf("Record is already full\n");
        system("pause");
    } else {
        last++;
        strcpy(player_name[last], par_name);
        bats[last] = par_bats;
        hits[last] = par_hits;
        /*printf("%s is successfully recorded\n", par_name);
        system("pause");
        */
    }
}

void delR(char par_name[]){
    int i, position;

    if(isEmpty()){
        printf("Record is empty\n");
        system("pause");
    } else {
        position = locate(par_name);
        if(position == -1){
            printf("%s is not found\n", par_name);
            system("pause");
        } else {
            for(i = position; i < last; i++){
                strcpy(player_name[i], player_name[i+1]);
                bats[i] = bats[i+1];
                hits[i] = hits[i+1];
            }
            last--;
            printf("%s is successfully deleted\n", par_name);
            system("pause");
        }
    }
}

void display(){
    int i;
    float batting_average = 0;
    system("cls");

    if(isEmpty()){
        printf("Nothing to show\n");
    } else {
        sortByAverage();
        printf("%-4s %-20s %-6s %-6s %-6s\n", "No.", "NAME", "BATS", "HITS", "AVERAGE");
        for(i=0;i<=last;i++){
            batting_average = average(bats[i], hits[i]);
            printf("%-4d %-20s %-6d %-6d %-6.2f\n", i+1, player_name[i], bats[i], hits[i], batting_average);
        }
    }
    system("pause");
}

int locate(char par_name[]){
    int i;
    for(i=0;i<=last;i++){
        if(strcmp(player_name[i], par_name) == 0){
            return i;
        }
    }
    return -1;
}

int menu(){
    int menu_choice;

    system("cls");

    printf("MENU\n");
    printf("[1] Add Record\n");
    printf("[2] Delete Record\n");
    printf("[3] Display Record\n");
    printf("[4] Update Record\n");
    printf("[5] Exit\n");
    printf("Select [1-5]: ");
    scanf("%d", &menu_choice);
    getchar();

    return menu_choice;
}

int isFull(){
    return last == MAX - 1;
}

int isEmpty(){
    return last == -1;
}

void update(char par_name[]){
    int i, position, update_choice;

    if(isEmpty()){
        printf("Record is empty\n");
        system("pause");
    } else {
        position = locate(par_name);
        if(position == -1){
            printf("%s is not found\n", par_name);
            system("pause");
        } else {
            while(1){
                system("cls");
                printf("Record of %s\n", player_name[position]);
                printf("Bats: %d\n", bats[position]);
                printf("Hits: %d\n", hits[position]);
                printf("Average %.2f\n", average(bats[position], hits[position]));

                printf("\nUpdate Options \n");
                printf("[1] Update bats\n");
                printf("[2] Update hits\n");
                printf("[3] Return to main menu\n");
                printf("Select [1-3] only: ");
                scanf("%d", &update_choice);
                getchar();

                switch(update_choice){
                case 1:
                    printf("Input new bats: ");
                    scanf("%d", &bats[position]);
                    break;
                case 2:
                    printf("Input new hits: ");
                    scanf("%d", &hits[position]);

                    if(!isValidStats(bats[position], hits[position])){
                        printf("Invalid update! Hits cannot exceed bats.\n");
                        system("pause");
                        return;
                        }
                    break;
                case 3:
                    return;
                default:
                    printf("1-3 lang po mam/ser\n");
                    system("pause");
                    }
                }
            }
        }
    }

float average(int par_bats, int par_hits){
    if(par_bats == 0){
        return 0.0;
    }
    return ((float)par_hits / par_bats) * 100.0;
}


void save(){
    int i;
    FILE *file_pointer;
    file_pointer = fopen(current_file, "w");
    if(file_pointer == NULL){
        printf("Error opening file %s for saving\n", current_file);
        system("pause");
        return;
    }

    for(i = 0; i <= last; i++){
        fprintf(file_pointer, "%s, %d, %d\n", player_name[i], bats[i], hits[i]);
    }
    fclose(file_pointer);
    printf("Data saved to %s successfully!\n", current_file);
    system("pause");
}


void retrieve(){
    char line[array_size*2];
    char retrieve_name[array_size];
    int retrieve_bats, retrieve_hits;
    char choice;
    FILE *file_pointer;

    file_pointer = fopen(current_file, "r");
    if(file_pointer == NULL){
        printf("No file found: %s\n", current_file);
        printf("Do you want to create a new file? (Y/N): ");
        scanf(" %c", &choice);
        getchar(); // consume newline

        if(choice == 'Y' || choice == 'y'){
            printf("Enter the name of the new file (with .csv): ");
            fgets(current_file, array_size, stdin);
            current_file[strcspn(current_file, "\n")] = '\0'; // remove newline

            file_pointer = fopen(current_file, "w");
            if(file_pointer == NULL){
                printf("Error creating file %s\n", current_file);
                system("pause");
                return;
            }
            printf("File %s created successfully!\n", current_file);
            fclose(file_pointer);
        } else {
            printf("No file created. Program will continue without data.\n");
            system("pause");
            return;
        }
    } else {
        // Read existing data
        while(fgets(line, sizeof(line), file_pointer)){
            if(sscanf(line, "%49[^,], %d, %d", retrieve_name, &retrieve_bats, &retrieve_hits) == 3){
                addR(retrieve_name, retrieve_bats, retrieve_hits);
            }
        }
        fclose(file_pointer);
    }
}



int isValidStats(int par_bats, int par_hits){
    if(par_bats < 0 || par_hits < 0){
        return 0;
    }
    if(par_hits > par_bats){
        return 0;
    }
    return 1;
}

void sortByAverage(){
    int i, j;
    float avg1, avg2;

    for(i = 0; i < last; i++){
        for(j = 0; j < last - i; j++){

            avg1 = average(bats[j], hits[j]);
            avg2 = average(bats[j+1], hits[j+1]);

            if(avg1 < avg2){  // descending order

                // swap names
                char temp_name[array_size];
                strcpy(temp_name, player_name[j]);
                strcpy(player_name[j], player_name[j+1]);
                strcpy(player_name[j+1], temp_name);

                // swap bats
                int temp_bats = bats[j];
                bats[j] = bats[j+1];
                bats[j+1] = temp_bats;

                // swap hits
                int temp_hits = hits[j];
                hits[j] = hits[j+1];
                hits[j+1] = temp_hits;
            }
        }
    }
}
