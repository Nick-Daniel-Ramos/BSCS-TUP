#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 128
#define SCORE_TO_WIN 10

typedef struct Record{
    char name[MAX_PLAYERS];
    char password[MAX_PLAYERS];
    int age;
    int operation[4];
    int total_wins;
} Player;

Player player_list[MAX_PLAYERS];

char* operation_names[] = { "Addition", "Subtraction", "Multiplication", "Division" };
char operation_symbols[] = { '+', '-', '*', '/' };

void auth_menu();
void game_menu(int player_index);

void save() {
    FILE* file = fopen("records.csv", "w");
    if (!file) return;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (player_list[i].name[0] == '\0') continue;
        fprintf(file, "%s,%s,%d,%d,%d,%d,%d,%d\n",
            player_list[i].name,
            player_list[i].password,
            player_list[i].age,
            player_list[i].operation[0],
            player_list[i].operation[1],
            player_list[i].operation[2],
            player_list[i].operation[3],
            player_list[i].total_wins);
    }
    fclose(file);
}

void load() {
    FILE* file = fopen("records.csv", "r");
    if (!file) return;
    int i = 0;
    while (i < MAX_PLAYERS) {
        Player p = {0};
        int result = fscanf(file, "%127[^,],%127[^,],%d,%d,%d,%d,%d,%d\n",
            p.name, p.password, &p.age,
            &p.operation[0], &p.operation[1], &p.operation[2], &p.operation[3],
            &p.total_wins);
        if (result != 8) break;
        player_list[i++] = p;
    }
    fclose(file);
}

int locate(char* name){
    for (int i = 0; i < MAX_PLAYERS; i++)
        if (strcmp(player_list[i].name, name) == 0)
            return i;
    return -1;
}

int locate_name_password(char* name, char* password){
    for (int i = 0; i < MAX_PLAYERS; i++)
        if (strcmp(player_list[i].name, name) == 0 && strcmp(player_list[i].password, password) == 0)
            return i;
    return -1;
}

void addP(Player new_player){
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (player_list[i].name[0] == '\0') {
            player_list[i] = new_player;
            printf("Registered successfully!\n");
            system("pause");
            return;
        }
    }
    printf("Player list is full.\n");
    system("pause");
}

void sort(int operation){
    for (int i = 0; i < MAX_PLAYERS - 1; i++) {

        int highest_index = i;

        for (int j = i + 1; j < MAX_PLAYERS; j++) {
            int score_j = operation < 4
                ? player_list[j].operation[operation]
                : player_list[j].total_wins;
            int score_best = operation < 4
                ? player_list[highest_index].operation[operation]
                : player_list[highest_index].total_wins;
            if (score_j > score_best || (score_j == score_best && strcmp(player_list[j].name, player_list[highest_index].name) < 0)) {
                highest_index = j;
            }
        }

        if (highest_index != i) {
            Player temp = player_list[i];
            player_list[i] = player_list[highest_index];
            player_list[highest_index] = temp;
        }
    }
}

void leaderboard(int operation){
    sort(operation);

    printf("\nTop 10 - %s\n", operation < 4 ? operation_names[operation] : "Overall");

    int entries_shown = 0;

    for (int i = 0; i < MAX_PLAYERS && entries_shown < 10; i++) {
        if (player_list[i].name[0] == '\0')
            continue;
        int score = operation < 4
            ? player_list[i].operation[operation]
            : player_list[i].total_wins;
        printf("%d. %-20s %d wins\n", entries_shown + 1, player_list[i].name, score);
        entries_shown++;
    }

    if (entries_shown == 0)
        printf("No records yet.\n");
    printf("\n");
}

void leaderboard_menu(int player_index){
    char saved_name[MAX_PLAYERS];
    strcpy(saved_name, player_list[player_index].name);

    int choice = 0;
    while (choice != 6) {
        system("cls");
        printf("Leaderboards\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Overall\n");
        printf("6. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice >= 1 && choice <= 5) {
            leaderboard(choice - 1);
            system("pause");
        } else if (choice != 6) {
            printf("Invalid choice.\n");
        }
    }

    player_index = locate(saved_name);

}

int get_time_limit(double time_limit, int* answer) {
    char input[32];
    int len = 0;
    clock_t start = clock();

    while (1) {
        double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
        if (elapsed >= time_limit) {
            printf("\n");
            return 0;
        }

        if (!_kbhit()) continue;

        char key = _getch();

        if (key == '\r') {
            printf("\n");
            if (len > 0) {
                input[len] = '\0';
                *answer = atoi(input);
                return 1;
            }
        } else if (key == 8 && len > 0) {
            input[--len] = '\0';
            printf("\b \b");
        } else if ((key == '-' && len == 0) || (key >= '0' && key <= '9')) {
            input[len++] = key;
            printf("%c", key);
            fflush(stdout);
        }
    }
}

float response_time(int operation){
    float base_time[] = { 1.5f, 1.5f, 1.5f, 1.5f };
    float random_range[] = { 2.0f, 2.0f, 2.0f, 2.0f };
    return base_time[operation] + ((float)rand() / RAND_MAX) * random_range[operation];
}

void score_bar(char* label, int current_score){
    printf("%-10s [", label);

    for (int i = 0; i < SCORE_TO_WIN; i++)
        printf(i < current_score ? "#" : ".");

    printf("] %d/%d\n", current_score, SCORE_TO_WIN);
}

int question_answer(int operation, float time_limit){

    int number_a = rand() % 20 + 1;
    int number_b = rand() % 20 + 1;
    int correct_answer;
    int i;

    if (operation == 0)
        correct_answer = number_a + number_b;
    else if (operation == 1){
            if(number_a <= number_b){
                int temp = number_a;
                number_a = number_b;
                number_b = temp;
            }
            correct_answer = number_a - number_b;
        }
    else if (operation == 2){
        number_a = rand() % 10 + 1;
        number_b = rand() % 10 + 1;
        correct_answer = number_a * number_b;
    }
    else
        do{
            number_a = rand() % 20 + 1;
            number_b = rand() % 20 + 1;
            correct_answer = number_a / number_b;
    } while(number_a % number_b != 0);


    printf("%d %c %d = ", number_a, operation_symbols[operation], number_b);
    fflush(stdout);

    int player_answer = 0;
    int answered_in_time = get_time_limit((double)time_limit, &player_answer);

    if (!answered_in_time) {
        printf("Time's up! Robot gets the point.\n");
        return 0;
    } else if (player_answer != correct_answer) {
        printf("Wrong! The answer was %d. Robot gets the point.\n", correct_answer);
        return 0;
    } else {
        printf("Correct! You get the point.\n");
        return 1;
    }
}

void play_match(int player_index, int operation){
    int player_score = 0;
    int robot_score = 0;
    int question_number = 0;
    char player_name[MAX_PLAYERS];
    strcpy(player_name, player_list[player_index].name);

    system("cls");
    printf("%s vs Robot - %s - First to %d wins!\n\n", player_name, operation_names[operation], SCORE_TO_WIN);
    printf("Answer correctly before time runs out to earn a point.\n");
    printf("Wrong answer or timeout = robot earns the point.\n\n");
    system("pause");

    while (player_score < SCORE_TO_WIN && robot_score < SCORE_TO_WIN) {
        question_number++;
        system("cls");
        printf("Q%d | %s vs Robot | %s\n\n", question_number, player_name, operation_names[operation]);
        score_bar(player_name, player_score);
        score_bar("Robot", robot_score);
        printf("\n");

        float robot_time_limit = response_time(operation);
        int player_got_it_right = question_answer(operation, robot_time_limit);

        if (player_got_it_right)
            player_score++;
        else
            robot_score++;

        printf("\n");
        score_bar(player_name, player_score);
        score_bar("Robot", robot_score);

        printf("\n");

        if (player_score < SCORE_TO_WIN && robot_score < SCORE_TO_WIN) {
            printf("Press Enter for the next question...");
            getchar();
        }
    }

    system("cls");

    if (player_score >= SCORE_TO_WIN) {
        printf("You win! Well done, %s.\n\n", player_name);
        player_index = locate(player_name);
        player_list[player_index].operation[operation]++;
        player_list[player_index].total_wins++;
        save();
    } else {
        printf("Robot wins. Better luck next time!\n\n");
    }

    score_bar(player_name, player_score);
    score_bar("Robot", robot_score);
    printf("\nFinal Score - You: %d | Robot: %d\n", player_score, robot_score);
    leaderboard(4);
    system("pause");


}

void game_menu(int player_index){
    while (1) {
        system("cls");
        printf("Game Menu\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Leaderboards\n");
        printf("6. Logout\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice >= 1 && choice <= 4) {
            play_match(player_index, choice - 1);
        } else if (choice == 5) {
            leaderboard_menu(player_index);
        } else if (choice == 6) {
            save();
            return;
        } else {
            printf("Invalid choice.\n");
        }
    }
}


void register_player(){
    Player new_player = {0};

    printf("Name: ");
    fgets(new_player.name, MAX_PLAYERS, stdin);
    new_player.name[strcspn(new_player.name, "\n")] = 0;

    if (locate(new_player.name) != -1) {
        printf("That name is already taken.\n");
        system("pause");
        return;
    }

    printf("Password: ");
    fgets(new_player.password, MAX_PLAYERS, stdin);
    new_player.password[strcspn(new_player.password, "\n")] = 0;

    addP(new_player);
}


void login(){
    char l_name[MAX_PLAYERS];
    char l_password[MAX_PLAYERS];

    printf("Username: ");
    fgets(l_name, MAX_PLAYERS, stdin);
    l_name[strcspn(l_name, "\n")] = 0;

    if (locate(l_name) == -1) {
        printf("Username not found. Please register first.\n");
        system("pause");
        return;
    }

    printf("Password: ");
    fgets(l_password, MAX_PLAYERS, stdin);
    l_password[strcspn(l_password, "\n")] = 0;

    int matched_index = locate_name_password(l_name, l_password);

    if (matched_index != -1) {
        printf("Login successful.\n");
        game_menu(matched_index);
    } else {
        printf("Wrong password.\n");
    }
}

void auth_menu(){
    while (1) {
        system("cls");
        printf("Math Game\n");
        printf("1. Login\n2. Register\n3. Exit\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            login();
        } else if (choice == 2) {
            register_player();
        } else if (choice == 3) {
            save();
            return;
        } else {
            printf("Invalid choice.\n");
        }
    }
}

int main(){
    load();
    srand(time(NULL));
    auth_menu();
    return 0;
}
