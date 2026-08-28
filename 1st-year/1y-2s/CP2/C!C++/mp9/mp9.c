#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define array_size 50

typedef struct node {
    char name[array_size];
    int quiz1, quiz2, quiz3;
    struct node *next;
} link;

link *individual;

void initializer();
void addR(link *newNode);
void delR(char p_name[]);
void display();
void search(char p_name[]);
void classAverage();
void highestAverage();
void updateScore(char p_name[]);
void save();
void retrieve();

int menu();

float average(int p_quiz1, int p_quiz2, int p_quiz3);

int main(){
    initializer();
    retrieve();

    link *m_individual;

    while(1){
        switch(menu()){
        case 1:
            link *position;
            int duplicate = 0;

            position = individual;

            m_individual = (link*)malloc(sizeof(link));

            printf("Enter name: ");
            fgets(m_individual ->name, array_size, stdin);
            m_individual ->name[strcspn(m_individual ->name, "\n")] = '\0';

            while(position != NULL){
                if(strcmp(position ->name, m_individual ->name) == 0){
                    printf("%s is already recorded\n", position ->name);
                    system("pause");
                    duplicate = 1;
                    break;
                }
                position = position ->next;
            }

            if(duplicate){
                free(m_individual);
                continue;
            }

            printf("Quiz 1 Score: ");
            scanf("%d", &m_individual ->quiz1);

            printf("Quiz 2 Score: ");
            scanf("%d", &m_individual ->quiz2);

            printf("Quiz 3 Score: ");
            scanf("%d", &m_individual ->quiz3);
            getchar();

            addR(m_individual);
            break;
        case 2:
            printf("Enter name: ");
            fgets(m_individual ->name, array_size, stdin);
            m_individual ->name[strcspn(m_individual ->name, "\n")] = '\0';

            delR(m_individual ->name);
            break;
        case 3:
            printf("Enter Name: ");
            fgets(m_individual ->name, array_size, stdin);
            m_individual ->name[strcspn(m_individual ->name, "\n")] = '\0';

            search(m_individual ->name);
            break;
        case 4:
            printf("Enter Name: ");
            fgets(m_individual ->name, array_size, stdin);
            m_individual ->name[strcspn(m_individual ->name, "\n")] = '\0';

            updateScore(m_individual ->name);
            break;
       case 5:
            display();
            highestAverage();
            break;
        case 6:
            printf("Saving...\n");
            save();
            exit(0);
        default:
            printf("Please select [1-4] only\n");
            system("pause");
        }
    }

return 0;
}


void initializer(){
    individual = NULL;
}

void addR(link *newNode){
    link *position, *queue;

    position = queue = individual;

    while(position != NULL && strcmp(position->name, newNode->name) < 0){
        queue = position;
        position = position->next;
    }

    if(position == individual){
        individual = newNode;
    }
    else{
        queue->next = newNode;
    }

    newNode->next = position;
}

void delR(char p_name[]){
    link *newNode, *position, *queue;

    position = queue = individual;

    while(position != NULL && strcmp(position ->name, p_name) != 0){
        queue = position;
        position = position ->next;
    }

        if (position == NULL) {
        printf("Not found!\n");
    }
    else {

        if (position == individual) {
            individual = individual -> next;
        }
        else {
            queue -> next = position -> next;
        }
        free(position);
    }
}

void display(){
    link *position;
    position = individual;
    float avg = 0;

    printf("head -> ");

    while(position != NULL){
        avg = average(position ->quiz1, position ->quiz2, position ->quiz3);
        printf("[%s, %d, %d, %d, %.2f] -> ", position ->name, position ->quiz1, position ->quiz2, position ->quiz3, avg);
        position = position ->next;
    }
    printf("NULL\n");
}

void search(char p_name[]){
    link *position;
    int found = 0;

    position = individual;

    while(position != NULL){
        if(strcmp(position ->name, p_name) == 0){
            printf("Student Found\n");
            printf("Name: %s\n", position ->name);
            printf("Quiz 1: %d\n", position ->quiz1);
            printf("Quiz 2: %d\n", position ->quiz2);
            printf("Quiz 3: %d\n", position ->quiz3);
            found = 1;
            break;
        }
        position = position ->next;
    }
    if(!found){
        printf("Student not found\n");
    }
    system("pause");
}

void classAverage(){
    link *temp = individual;
    int s_counter = 0;
    int q_counter = 0;
    float c_average = 0;
    while(temp != NULL){
        s_counter += (temp ->quiz1 + temp ->quiz2 + temp ->quiz3);
        q_counter++;
        temp = temp ->next;
    }
    c_average = ((float)s_counter) / (q_counter * 3);
    printf("Class Average: %.2f\n", c_average);
    system("pause");
}

void highestAverage(){
    link *temp = individual;
    float highest = 0;
    float avg = 0;

    while(temp != NULL){
        avg = average(temp->quiz1, temp->quiz2, temp->quiz3);

        if(avg > highest){
            highest = avg;
        }

        temp = temp->next;
    }

    temp = individual;

    while(temp != NULL){
        avg = average(temp->quiz1, temp->quiz2, temp->quiz3);

        if(avg == highest){
            printf("\nTop Student:\n");
            printf("Name: %s\n", temp->name);
            printf("Average: %.2f\n", avg);
        }

        temp = temp->next;
    }

    system("pause");
}

void updateScore(char p_name[]){
    link *position;

    position = individual;

    while(position != NULL){
        if(strcmp(position ->name, p_name) == 0){
            int choice;
            while(1){
                system("cls");
                printf("UPDATE MENU");
                printf("Record of: %s\n", p_name);
                printf("Quiz 1: %d\n", position ->quiz1);
                printf("Quiz 2: %d\n", position ->quiz2);
                printf("Quiz 3: %d\n", position ->quiz3);
                printf("Average: %.2f\n", average(position ->quiz1, position ->quiz2, position ->quiz3));

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
                        scanf("%d", &position ->quiz1);
                        break;
                case 2: printf("Enter new score on Quiz 2: ");
                        scanf("%d", &position ->quiz2);
                        break;
                case 3: printf("Enter new score on Quiz 3: ");
                        scanf("%d", &position ->quiz3);
                        break;
                case 4: return;
                default: printf("1-4 lang po ma'am/ser\n");
                        system("pause");
                }
            }
            system("pause");
        }
        position = position ->next;
    }
}

void save(){
    int i;
    FILE *file_pointer;

    link *current;

    file_pointer = fopen("bscs_1ab_26.csv", "w");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        current = individual;
        while(current != NULL){
            fprintf(file_pointer, "%s, %d, %d, %d\n", current ->name, current ->quiz1, current ->quiz2, current ->quiz3);
            current = current ->next;
        }
        fclose(file_pointer);
    }
}

void retrieve(){
    int i;
    link *r_individual;

    char line[array_size * 2];

    FILE *file_pointer;

    file_pointer = fopen("bscs_1ab_26.csv", "r");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        while(fgets(line, sizeof(line), file_pointer)){
            r_individual = (link*)malloc(sizeof(link));
            sscanf(line, "%49[^,], %d, %d, %d", r_individual ->name, &r_individual ->quiz1, &r_individual ->quiz2, &r_individual ->quiz3);
            addR(r_individual);
        }
    }
    fclose(file_pointer);
}

int menu(){
    int choice;

    system("cls");
    printf("MENU\n");
    printf("[1] Add Record\n");
    printf("[2] Delete Record\n");
    printf("[3] Search Record\n");
    printf("[4] Update Record\n");
    printf("[5] Display Records\n");
    printf("[6] Exit\n");
    printf("Select [1-6] only: ");
    scanf("%d", &choice);
    getchar();

    return choice;
}


float average(int p_quiz1, int p_quiz2, int p_quiz3){
    return ((float) p_quiz1 + p_quiz2 + p_quiz3) / 3.0;
}
