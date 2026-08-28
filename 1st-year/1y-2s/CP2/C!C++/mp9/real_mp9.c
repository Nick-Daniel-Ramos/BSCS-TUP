#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define array_size 50

typedef struct records{
    char name[array_size];
    int quiz1, quiz2, quiz3;
} data;

typedef struct node{
    data student;
    struct node *next;
} NODE;

NODE *head;

void initializer();
void addR(NODE *p_individual);
void delR(char p_name[]);
void display();
void update(char p_name[]);
void save();
void retrieve();

int locate(char p_name[]);
int isEmpty();
int menu();

float average(int p_q1, int p_q2, int p_q3);

int main(){

    NODE *m_individual;

    initializer();

    retrieve();

    while(1){
        switch(menu()){
            case 1:
            m_individual = (NODE*)malloc(sizeof(NODE));
            printf("Input name: ");
            fgets(m_individual ->student.name, array_size, stdin);
            m_individual ->student.name[strcspn(m_individual ->student.name, "\n")] = '\0';

            if(locate(m_individual ->student.name) != -1){
                printf("%s is already in record\n", m_individual ->student.name);
                system("pause");
                continue;
            }

            printf("Input Quiz 1 score: ");
            scanf("%d", &m_individual ->student.quiz1);

            printf("Input Quiz 2 score: ");
            scanf("%d", &m_individual ->student.quiz2);

            printf("Input Quiz 3 score: ");
            scanf("%d", &m_individual ->student.quiz3);
            getchar();

            addR(m_individual);
            break;
        case 2:
            printf("Input name: ");
            m_individual = (NODE*)malloc(sizeof(NODE));
            fgets(m_individual ->student.name, array_size, stdin);
            m_individual ->student.name[strcspn(m_individual ->student.name, "\n")] = '\0';
            delR(m_individual ->student.name);
            break;
        case 3:
            printf("Input name: ");
            m_individual = (NODE*)malloc(sizeof(NODE));
            fgets(m_individual ->student.name, array_size, stdin);
            m_individual ->student.name[strcspn(m_individual ->student.name, "\n")] = '\0';
            update(m_individual ->student.name);
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

void initializer(){
    head = NULL;
}

void addR(NODE *p_individual){

    NODE *current, *previous;

    p_individual ->next = NULL;
    current = head;
    previous = NULL;

    while(current != NULL && strcmp(current ->student.name, p_individual ->student.name) < 0){
        previous = current;
        current = current ->next;
    }
    if(previous == NULL){
        p_individual ->next = head;
        head = p_individual;
    }
    else{
        previous ->next = p_individual;
        p_individual ->next = current;
    }
}

void delR(char p_name[]){

    NODE *current, *previous;

    current = head;
    previous = NULL;

    while(current != NULL){

        if(strcmp(current->student.name, p_name) == 0){

            if(previous == NULL){
                head = current->next;
            }
            else{
                previous->next = current->next;
            }

            free(current);
            printf("Record deleted.\n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Record not found.\n");
}

void display(){
    NODE *temp = head;
    int counter = 1;
    float avg = 0;
    printf("%-4s %-20s %-10s %-10s %-10s %-10s %-10s\n",
       "No.",
       "NAME",
       "QUIZ 1",
       "QUIZ 2",
       "QUIZ 3",
       "AVERAGE",
       "REMARKS");
    while(temp != NULL){
        avg = average(temp ->student.quiz1, temp ->student.quiz2, temp ->student.quiz3);
        printf("%-4d %-20s %-10d %-10d %-10d %-10.2f %-10s\n",
               counter++,
               temp ->student.name,
               temp ->student.quiz1,
               temp ->student.quiz2,
               temp ->student.quiz3,
               avg,
               avg >= 75 ? "PASSED" : "FAILED");
        temp = temp ->next;
    }
    system("pause");
}

void update(char p_name[]){

    NODE *current;

    current = head;

    while(current != NULL){
        if(strcmp(current->student.name, p_name) == 0){
            int choice;
            while(1){
                system("cls");
                printf("UPDATE MENU");
                printf("Record of: %s\n", current ->student.name);
                printf("Quiz 1: %d\n", current ->student.quiz1);
                printf("Quiz 2: %d\n", current ->student.quiz2);
                printf("Quiz 3: %d\n", current ->student.quiz3);
                printf("Average: %.2f\n", average(current ->student.quiz1, current ->student.quiz2, current ->student.quiz3));

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
                        scanf("%d", &current ->student.quiz1);
                        break;
                case 2: printf("Enter new score on Quiz 2: ");
                        scanf("%d", &current ->student.quiz2);
                        break;
                case 3: printf("Enter new score on Quiz 3: ");
                        scanf("%d", &current ->student.quiz3);
                        break;
                case 4: return;
                default: printf("1-4 lang po ma'am/ser\n");
                        system("pause");
                }
            }
        }
        current = current ->next;
    }
}

void save(){

    NODE *temp = head;

    FILE *file_pointer;

    file_pointer = fopen("bscs_1ab_26.csv", "w");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        while(temp != NULL){
            fprintf(file_pointer, "%s, %d, %d, %d\n", temp ->student.name, temp ->student.quiz1, temp ->student.quiz2, temp ->student.quiz3);
            temp = temp ->next;
        }
    }
    fclose(file_pointer);
}

void retrieve(){
    NODE *r_individual;
    FILE *file_pointer;
    char buffer[1024];

    file_pointer = fopen("bscs_1ab_26.csv", "r");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        while(fgets(buffer, sizeof(buffer), file_pointer)){
            r_individual = (NODE*)malloc(sizeof(NODE));
            sscanf(buffer, "%[^,], %d, %d, %d", r_individual ->student.name, &r_individual ->student.quiz1, &r_individual ->student.quiz2, &r_individual ->student.quiz3);
            addR(r_individual);
        }
    }
    fclose(file_pointer);
}

int locate(char p_name[]){
    NODE *temp = head;
    int counter = 1;

    while(temp != NULL){
        if(strcmp(temp->student.name, p_name) == 0){
            return counter;
        }
        temp = temp->next;
        counter++;
    }

    return -1;
}

int isEmpty(){
    return head == NULL;
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
