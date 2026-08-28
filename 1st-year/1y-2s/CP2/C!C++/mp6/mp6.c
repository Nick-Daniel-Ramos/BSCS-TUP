#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
#define array_size 50

char name[MAX][array_size];
int quiz1[MAX], quiz2[MAX], quiz3[MAX];
int last = -1;

void addR(char p_name[], int p_q1, int p_q2, int p_q3);
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
    char m_name[array_size];
    int m_quiz1, m_quiz2, m_quiz3;

    retrieve();

    while(1){
        switch(menu()){
            case 1:
            printf("Input name: ");
            fgets(m_name, array_size, stdin);
            m_name[strcspn(m_name, "\n")] = '\0';

            if(locate(m_name) != -1){
                printf("%s is already in record\n", m_name);
                system("pause");
                continue;
            }

            printf("Input Quiz 1 score: ");
            scanf("%d", &m_quiz1);

            printf("Input Quiz 2 score: ");
            scanf("%d", &m_quiz2);

            printf("Input Quiz 3 score: ");
            scanf("%d", &m_quiz3);
            getchar();

            addR(m_name, m_quiz1, m_quiz2, m_quiz3);
            break;
        case 2:
            printf("Input name: ");
            fgets(m_name, array_size, stdin);
            m_name[strcspn(m_name, "\n")] = '\0';
            delR(m_name);
            break;
        case 3:
            printf("Input name: ");
            fgets(m_name, array_size, stdin);
            m_name[strcspn(m_name, "\n")] = '\0';
            update(m_name);
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

void addR(char p_name[], int p_q1, int p_q2, int p_q3){
    int i, j;
    char temp_name[array_size];
    int temp_q1, temp_q2, temp_q3;

    if(isFull()){
        printf("Record is already full\n");
        system("pause");
    } else {
        last++;
        strcpy(name[last], p_name);
        quiz1[last] = p_q1;
        quiz2[last] = p_q2;
        quiz3[last] = p_q3;

        for(i = 0; i < last; i++){
            for(j = i + 1; j <= last; j++){
                if(strcmp(name[i], name[j]) > 0){

                    strcpy(temp_name, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], temp_name);

                    temp_q1 = quiz1[i];
                    quiz1[i] = quiz1[j];
                    quiz1[j] = temp_q1;

                    temp_q2 = quiz2[i];
                    quiz2[i] = quiz2[j];
                    quiz2[j] = temp_q2;

                    temp_q3 = quiz3[i];
                    quiz3[i] = quiz3[j];
                    quiz3[j] = temp_q3;
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
                strcpy(name[i], name[i + 1]);
                quiz1[i] = quiz1[i + 1];
                quiz2[i] = quiz2[i + 1];
                quiz3[i] = quiz3[i + 1];
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
            avg = average(quiz1[i], quiz2[i], quiz3[i]);

            printf("%-4d %-20s %-10d %-10d %-10d %-10.2f %-10s\n",
                   i+1,
                   name[i],
                   quiz1[i],
                   quiz2[i],
                   quiz3[i],
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
                printf("Record of: %s\n", name[position]);
                printf("Quiz 1: %d\n", quiz1[position]);
                printf("Quiz 2: %d\n", quiz2[position]);
                printf("Quiz 3: %d\n", quiz3[position]);
                printf("Average: %.2f\n", average(quiz1[position], quiz2[position], quiz3[position]));

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
                        scanf("%d", &quiz1[position]);
                        break;
                case 2: printf("Enter new score on Quiz 2: ");
                        scanf("%d", &quiz2[position]);
                        break;
                case 3: printf("Enter new score on Quiz 3: ");
                        scanf("%d", &quiz3[position]);
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
            fprintf(file_pointer, "%s, %d, %d, %d\n", name[i], quiz1[i], quiz2[i], quiz3[i]);
        }
    }
    fclose(file_pointer);
}

void retrieve(){
    int i;
    char line[array_size * 2];
    char r_name[array_size];
    int r_quiz1, r_quiz2, r_quiz3;
    FILE *file_pointer;

    file_pointer = fopen("bscs_1ab_26.csv", "r");
    if(file_pointer == NULL){
        printf("Error opening the file\n");
        system("pause");
    } else {
        while(fgets(line, sizeof(line), file_pointer)){
            sscanf(line, "%49[^,], %d, %d, %d", r_name, &r_quiz1, &r_quiz2, &r_quiz3);
            addR(r_name, r_quiz1, r_quiz2, r_quiz3);
        }
    }
    fclose(file_pointer);
}

int locate(char p_name[]){
    int i;
    for(i = 0; i <= last; i++){
        if(strcmp(name[i], p_name) == 0){
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
