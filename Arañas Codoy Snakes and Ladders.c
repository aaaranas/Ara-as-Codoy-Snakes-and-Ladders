#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct snakes_ladders {
    int S1, s1, S2, s2, S3, s3;
    int L1, l1, L2, l2, L3, l3;
};

struct player {
    int a;
    int b;
    int c;
    int d;
    char currentPlayer;
};

void createGrid(int *snakes_ladders_ptr, int *players_ptr) {
    for(int i = 10; i >= 0; i--) {
        printf("+");
        for(int j = 10; j > 0; j--) {
            printf("----+");
        }
        printf("\n");

        if(i != 0) {
            if(i%2 == 0) {
                for(int k = 10; k >= 0; k--) {
                    if(i==10 && k==10) {
                        int isSnakeTail = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 1) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 3) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 5);
                        int isSnakeHead = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12)) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 2) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 4);
                        int isLadderBottom = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 7) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 9) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 11);
                        int isLadderTop = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 6) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 8) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 10);
                        if(isSnakeTail || isSnakeHead) {
                            if(isSnakeHead)
                                printf("%-5s", "|#S");
                            if(isSnakeTail)
                                printf("%-5s", "|#s");
                        } else if(isLadderBottom || isLadderTop) {
                            if(isLadderTop)
                                printf("%-5s", "|#L");
                            if(isLadderBottom)
                                printf("%-5s", "|#l");
                        } else {
                            printf("%-5s", "|#");
                        }
                    } else {
                        if(k != 0) {
                            int isSnakeTail = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 1) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 3) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 5);
                            int isSnakeHead = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12)) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 2) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 4);
                            int isLadderBottom = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 7) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 9) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 11);
                            int isLadderTop = *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 6) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 8) || *(snakes_ladders_ptr+(((i*10-(10-k))-1)*12) + 10);
                            if(isSnakeTail || isSnakeHead) {
                                if(isSnakeHead)
                                    printf("%-5s", "|S");
                                if(isSnakeTail)
                                    printf("%-5s", "|s");
                            } else if(isLadderBottom || isLadderTop) {
                                if(isLadderTop)
                                    printf("%-5s", "|L");
                                if(isLadderBottom)
                                    printf("%-5s", "|l");
                            } else {
                                printf("%-5s", "|");
                            }
                        } else {
                            printf("%-5s", "|");
                        }

//                        printf("|%-4i", i*10-(10-k));
                    }
                }
                printf("\n");
                for(int l = 10; l >= 0; l--) {
                    if(l != 0) {
                        char players[4] = "";
                        if(*(players_ptr) == i*10-(10-l))
                            strcat(players, "a");
                        if(*(players_ptr + 1) == i*10-(10-l))
                            strcat(players, "b");
                        if(*(players_ptr + 2) == i*10-(10-l))
                            strcat(players, "c");
                        if(*(players_ptr + 3) == i*10-(10-l))
                            strcat(players, "d");

                        printf("|%4s", players);
                    } else {
                        printf("|%4");
                    }
                }
            } else {
                for(int k = 10; k >= 0; k--) {
                    if(k != 0) {
                        int isSnakeTail = *(snakes_ladders_ptr+((i*10-(k))*12) + 1) || *(snakes_ladders_ptr+((i*10-(k))*12) + 3) || *(snakes_ladders_ptr+((i*10-(k))*12) + 5);
                        int isSnakeHead = *(snakes_ladders_ptr+((i*10-(k))*12)) || *(snakes_ladders_ptr+((i*10-(k))*12) + 2) || *(snakes_ladders_ptr+((i*10-(k))*12) + 4);
                        int isLadderBottom = *(snakes_ladders_ptr+((i*10-(k))*12) + 7) || *(snakes_ladders_ptr+((i*10-(k))*12) + 9) || *(snakes_ladders_ptr+((i*10-(k))*12) + 11);
                        int isLadderTop = *(snakes_ladders_ptr+((i*10-(k))*12) + 6) || *(snakes_ladders_ptr+((i*10-(k))*12) + 8) || *(snakes_ladders_ptr+((i*10-(k))*12) + 10);
                        if(isSnakeTail || isSnakeHead) {
                            if(isSnakeHead)
                                printf("%-5s", "|S");
                            if(isSnakeTail)
                                printf("%-5s", "|s");
                        } else if(isLadderBottom || isLadderTop) {
                            if(isLadderTop)
                                printf("%-5s", "|L");
                            if(isLadderBottom)
                                printf("%-5s", "|l");
                        }
                        else {
                            printf("%-5s", "|");
                        }
                    } else
                        printf("%-5s", "|");
                }
                printf("\n");
                for(int l = 10; l >= 0; l--) {
                    if(l != 0) {
                        char players[4] = "";
                        if(*(players_ptr) == (i*10) - l + 1)
                            strcat(players, "a");
                        if(*(players_ptr + 1) == (i*10) - l + 1)
                            strcat(players, "b");
                        if(*(players_ptr + 2) == (i*10) - l + 1)
                            strcat(players, "c");
                        if(*(players_ptr + 3) == (i*10) - l + 1)
                            strcat(players, "d");

                        printf("|%4s", players);
                    } else {
                        printf("|%-4");
                    }

                }
            }

            printf("\n");
        }

    }
}

void spawner(int *snakes_ladder_ptr) {
    srand(time(NULL));
    int S1 = (rand() % 100) + 1;
    int s1 = rand() % S1;
    int S2 = (rand() % 100) + 1;
    int s2 = rand() % S2;
    int S3 = (rand() % 100) + 1;
    int s3 = rand() % S3;

    while(S1 == S2 || S1 == S3 || S2 == S3 || S1 < 2 || S2 < 2 || S3 < 2) { //CHECK IF SNAKE HEADS ARE CONFLICTING AND VALID
            S2 = (rand() % 100) + 1;
            s2 = rand() % S2;
            S3 = (rand() % 100) + 1;
            s3 = rand() % S3;
            S1 = (rand() % 100) + 1;
            s1 = rand() % S1;
    }

    int l1 = rand() % 100;
    int L1 = rand() % l1;
    int l2 = rand() % 100;
    int L2 = rand() % l2;
    int l3 = rand() % 100;
    int L3 = rand() % l3;

    while(L1 == L2 || L1 == L3 || L2 == L3 ||
        S1 == L1 || S1 == L2 || S1 == L3 ||
        S2 == L1 || S2 == L2 || S2 == L3 ||
        S3 == L1 || S3 == L2 || S3 == L3 ||
        L3 < 2 || L2 < 2 || L1 < 2 ||
        l1 < 3 || l2 < 3 || l3 < 3) { //CHECK IF LADDERS ARE CONFLICTING EACH OTHER AND WITH SNAKE HEADS
        L2 = rand() % 100;
        l2 = rand() % L2;
        L3 = rand() % 100;
        l3 = rand() % L3;
        L3 = rand() % 100;
        l3 = rand() % L3;
    }

    printf("S1: %i | s1: %i \n", S1, s1);
    printf("S2: %i | s2: %i \n", S2, s2);
    printf("S3: %i | s3: %i \n", S3, s3);
    printf("L1: %i | l1: %i \n", L1, l1);
    printf("L2: %i | l2: %i \n", L2, l2);
    printf("L3: %i | l3: %i \n", L3, l3);

    //ASSIGN VALUES FOR SNAKES HEADS TO DOWN AND LADDERS TO CLIMB
    *(snakes_ladder_ptr+((S1-1)*12)) = s1;
    *(snakes_ladder_ptr+((s1-1)*12) + 1) = 1;
    *(snakes_ladder_ptr+((S2-1)*12) + 2) = s2;
    *(snakes_ladder_ptr+((s2-1)*12) + 3) = 1;
    *(snakes_ladder_ptr+((S3-1)*12) + 4) = s3;
    *(snakes_ladder_ptr+((s3-1)*12) + 4) = 1;
    *(snakes_ladder_ptr+((L1-1)*12) + 6) = l1;
    *(snakes_ladder_ptr+((l1-1)*12) + 7) = 1;
    *(snakes_ladder_ptr+((L2-1)*12) + 8) = l2;
    *(snakes_ladder_ptr+((l2-1)*12) + 9) = 1;
    *(snakes_ladder_ptr+((L3-1)*12) + 10) = l3;
    *(snakes_ladder_ptr+((l3-1)*12) + 11) = 1;

}

int rollDice() {
    srand(time(NULL));
    return ((rand()%6) + 1);
}

int play(int *players, int counter, int *snakes_ladders_arr_ptr) {
    printf("%c's turn.\n", *(players+4));
    printf("%c, press <enter> to roll.\n", *(players+4));
    char enter = 0;
    int isLandOnSnake = 0;
    int isLandOnLadder = 0;
    int winner = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    int diced = rollDice();
    *(players+counter) = *(players+counter) + diced;
    if(*(players+counter) > 100) {
        *(players+counter) = *(players+counter) - 100;
    } else if(*(players+counter) == 100) {
        printf("%c WINS!", *(players+4));
        winner = 1;
    }

    if(*(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) < 0 || *(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) > 1) {
        *(players+counter) = *(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12);
        isLandOnSnake = 1;
    } else if(*((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 2) < 0 || *((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 2) > 1) {
        *(players+counter) = *(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12 + 2);
        isLandOnSnake = 1;
    } else if(*((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 4) < 0 || *((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 4) > 1) {
        *(players+counter) = *(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12 + 4);
        isLandOnSnake = 1;
    }

    if(*((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 6) < 0 || *((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 6) > 1) {
        *(players+counter) = *(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12 + 6);
        isLandOnLadder = 1;
    } else if(*((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 8) < 0 || *((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 8) > 1) {
        *(players+counter) = *(snakes_ladders_arr_ptr + (*(players+counter) - 1)*12 + 8);
        isLandOnLadder = 1;
    } else if(*((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 10) < 0 || *((snakes_ladders_arr_ptr + (*(players+counter) - 1)*12) + 10) > 1) {
        *(players + counter) = *(snakes_ladders_arr_ptr + (*(players + counter) - 1) * 12 + 10);
        isLandOnLadder = 1;
    }
    createGrid(snakes_ladders_arr_ptr, players);
    printf("%c rolls a %i\n", *(players+4), diced);

    if(isLandOnSnake)
        printf("%c lands on a snake and goes down!\n", *(players+4));
    if(isLandOnLadder)
        printf("%c lands on a ladder and goes up!\n", *(players+4));

    if(counter==0)
        *(players+4) = 'b';
    if(counter==1)
        *(players+4) = 'c';
    if(counter==2)
        *(players+4) = 'd';
    if(counter==3)
        *(players+4) = 'a';

    if(winner) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    struct snakes_ladders grid[10][10]; //INITIALIZE GRID
    struct player players; //INITIALIZE PLAYERS
    int *snakes_ladders_arr_ptr = grid; //GRID POINTER

    int *players_ptr = &players;
    //INITIALIZE PLAYER POSITION TO 1
    players.a = 1;
    players.b = 1;
    players.c = 1;
    players.d = 1;
    players.currentPlayer = 'a';

    for(int i = 0; i < 100; i++) {   //ASSIGN INITIAL VALUES
        for(int j = 0; j < 12; j++) {
            *(snakes_ladders_arr_ptr+ (i*12) + j) = 0;
        }
    }

    spawner(snakes_ladders_arr_ptr);

    createGrid(snakes_ladders_arr_ptr, players_ptr);

    int counter = 0;
    int running = 1;

    while(running) {
        running = play(players_ptr, counter, snakes_ladders_arr_ptr);
        if(counter==3) {
            counter = 0;
        } else {
            counter++;
        }
    }
    return 0;
}
