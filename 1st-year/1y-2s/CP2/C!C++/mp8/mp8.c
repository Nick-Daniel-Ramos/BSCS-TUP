#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
#define array_size 50

typedef struct records{
    char name[array_size];
    int quiz1, quiz2, quiz3;
} data;

data individual[MAX];
int last = -1;

void addR(data p_individual);
void delR(char p_name[]);
void display();
void update(char p_name[]);
void save();
void retrieve();

int locate(char p_name[]);
int isEmpty();
int isFull();
int menu();

float average(int p_q1, int p_q2, int p_q3);

int main(){

    data m_individual;

    retrieve();

    while(1){
        switch(menu()){
            case 1:
            printf("Input name: ");
            fgets(m_individual.name, array_size, stdin);
            m_individual.name[strcspn(m_individual.name, "\n")] = '\0';

            if(locate(m_individual.name) != -1){
                printf("%s is already in record\n", m_individual.name);
                system("pause");
                continue;
            }

            printf("Input Quiz 1 score: ");
            scanf("%d", &m_individual.quiz1);

            printf("Input Quiz 2 score: ");
            scanf("%d", &m_individual.quiz2);

            printf("Input Quiz 3 score: ");
            scanf("%d", &m_individual.quiz3);
            getchar();

            addR(m_individual);
            break;
        case 2:
            printf("Input name: ");
            fgets(m_individual.name, array_size, stdin);
            m_individual.name[strcspn(m_individual.name, "\n")] = '\0';
            delR(m_individual.name);
            break;
        case 3:
            printf("Input name: ");
            fgets(m_individual.name, array_size, stdin);
            m_individual.name[strcspn(m_individual.name, "\n")] = '\0';
            update(m_individual.name);
            break;
        case 4:
            display();
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

void addR(data p_individual){
    int i, j;
    data temp_individual;

    if(isFull()){
        printf("Record is already full\n");
        system("pause");
    } else {
        last++;

        individual[last] = p_individual;

        for(i = 0; i < last; i++){
            for(j = i + 1; j <= last; j++){
                if(strcmp(individual[i].name, individual[j].name) > 0){

                    temp_individual = individual[i];
                    individual[i] = individual[j];
                    individual[j] = temp_individual;
                }
            }
        }
//        printf("Record of %s is successfully added\n", p_name);
//        system("pause");
    }
}

void delR(char p_name[]){
    int i, position;
    if(isEmpty()){
        printf("Record is empty\n");
        system("pause");
    } else {
        position = locate(p_name);
        if(position == -1){
            printf("%s is not found\n", p_name);
            system("pause");
        } else {
            for(i = position; i < last; i++){
                individual[i] = individual[i + 1];
            }
            last--;
            printf("Record of %s is successfully deleted\n", p_name);
            system("pause");
        }
    }
}

void display(){
    int i;
    float avg = 0.0;
    if(isEmpty()){
        printf("Nothing to display\n");
    } else {
        printf("%-4s %-20s %-10s %-10s %-10s %-10s %-10s\n",
               "No.",
               "NAME",
               "QUIZ 1",
               "QUIZ 2",
               "QUIZ 3",
               "AVERAGE",
               "REMARKS");
        for(i = 0; i <= last; i++){
            avg = average(individual[i].quiz1, individual[i].quiz2, individual[i].quiz3);

            printf("%-4d %-20s %-10d %-10d %-10d %-10.2f %-10s\n",
                   i+1,
                   individual[i].name,
                   individual[i].quiz1,
                   individual[i].quiz2,
                   individual[i].quiz3,
                   avg,
                   avg >= 75 ? "PASSED" : "FAILED");
        }
    }
    system("pause");
}

void update(char p_name[]){
    int i, position;
    if(isEmpty()){
        printf("Record is empty\n");
        system("pause");
    } else {
        position = locate(p_name);
        if(position == -1){
            printf("%s not found", p_name);
            system("pause");
        } else {
            int choice;

            while(1){
                system("cls");
                printf("UPDATE MENU");
                printf("Record of: %s\n", individual[position].name);
                printf("Quiz 1: %d\n", individual[position].quiz1);
                printf("Quiz 2: %d\n", individual[position].quiz2);
                printf("Quiz 3: %d\n", individual[position].quiz3);
                printf("Average: %.2f\n", average(individual[position].quiz1, individual[position].quiz2, individual[position].quiz3));

                printf("\nUPDATE OPTIONS\n");
                printf("[1] Update Quiz 1\n");
                printf("[2] Update Quiz 2\n");
                printf("[3] Update Quiz 3\n");
                printf("[4] Return to Main Menu\n");
                printf("Select [1-4] only: ");
                scanf("%d", &choice);
                getchar();

                switch(choice){
                case 1: printf("Enter new score on Quiz 1: ");
                        scanf("%d", &individual[position].quiz1);
                        break;
                case 2: printf("Enter new score on Quiz 2: ");
                        scanf("%d", &individual[position].quiz2);
                        break;
                case 3: printf("Enter new score on Quiz 3: ");
                        scanf("%d", &individual[position].quiz3);
                        break;
                case 4: return;
                default: printf("1-4 lang po ma'am/ser\n");
                        system("pause");
                }
            }
        }
        printf("%s is successfully updated\n", p_name);
        system("pause");
    }
}

void save(){
    int i;
    FILE *file_pointer;

    file_pointer = fopen("bscs_1ab_26.csv", "w");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        for(i = 0; i <= last; i++){
            fprintf(file_pointer, "%s, %d, %d, %d\n", individual[i].name, individual[i].quiz1, individual[i].quiz2, individual[i].quiz3);
        }
    }
    fclose(file_pointer);
}

void retrieve(){
    int i;
    data r_individual;
    char line[array_size * 2];

    FILE *file_pointer;

    file_pointer = fopen("bscs_1ab_26.csv", "r");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        while(fgets(line, sizeof(line), file_pointer && !isFull())){
            sscanf(line, "%49[^,], %d, %d, %d", r_individual.name, &r_individual.quiz1, &r_individual.quiz2, &r_individual.quiz3);
            addR(r_individual);
        }
    }
    fclose(file_pointer);
}

int locate(char p_name[]){
    int i;
    for(i = 0; i <= last; i++){
        if(strcmp(individual[i].name, p_name) == 0){
            return i;
        }
    }
    return -1;
}

int isEmpty(){
    return last == -1;
}

int isFull(){
    return last == MAX - 1;
}

int menu(){
    int choice;

    system("cls");
    printf("MENU\n");
    printf("[1] Add Record\n");
    printf("[2] Delete Record\n");
    printf("[3] Update Record\n");
    printf("[4] Display Record\n");
    printf("[5] Exit\n");
    printf("Select [1-5] only: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

float average(int p_q1, int p_q2, int p_q3){
    return ((float)(p_q1 + p_q2 + p_q3)) / 3;
}
