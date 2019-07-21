#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO -1
#define BLACK 2
#define WHITE 1

typedef struct gamestate {
    int wake_time;
    int shirt_color;
    int ran;
    int found_friend;
    int take_a_look;
    int dead;

    int black_shirt;
    int white_shirt;
    int blue_shirt;
    int not_alone_on_bus;
    int alone_on_bus;
    int death_times;
}stateT;

void wake_up(stateT *game);
void getting_ready(stateT *game);
void otw(stateT *game);
void in_school(stateT *game);
void boom(stateT *game);
void after_boom(stateT *game);

int decision(void);
void clear(void);
void initailise(stateT *game);

void initailise(stateT *game) {
    game->wake_time = 0;
    game->shirt_color = 0;
    game->ran = 0;
    game->found_friend = 0;
    game->take_a_look = 0;
    game->dead = NO;
}

int main() {
    
    stateT *newgame = malloc(sizeof(struct gamestate));

    newgame->death_times = 0;
    newgame->black_shirt = 0;
    newgame->white_shirt = 0;
    newgame->blue_shirt = 0;
    newgame->alone_on_bus = 0;
    newgame->not_alone_on_bus = 0;
    
    printf("\n");
    printf("Welcome to testdersnatch!\n");
    printf("Start? Y/N: ");
    
    char ans;
    
    scanf("%c", &ans);

    if (ans == 'y') {
        clear();
        printf("Lets begin\n\n");
        while (newgame->death_times < 3) {
            initailise(newgame);
            wake_up(newgame);
            getting_ready(newgame);
            otw(newgame);
            in_school(newgame);
            boom(newgame);
            after_boom(newgame);
            if (newgame->dead == NO) {
                break;
            }
        }
        
        
    } else {
        clear();
        printf("ok bye");
    }

    free(newgame);

    return 0;
}

//--------------------THE STORY--------------------
//-------------------------------------------------
void wake_up(stateT *game) {
    int choice = 0;
        while(1) {
            printf("--'BEEP' 'BEEP' 'BEEP'\n\n");
            printf("--You wake up to the sound of the alarm clock...\n");
            
            if (game->death_times == 1) {
                printf("\n--You seem to have had one crazy dream\n");
                printf("--can't remember it though...\n\n");
            } else if (game->death_times == 2) {
                printf("\n--You have a really wierd feeling...\n");
                printf("--like you've woke up like this before...\n\n");
            }
            printf("--You look at the time, 8:%d0am\n",game->wake_time);
            if (game->death_times < 2) {
                printf("--You decide to:\n\n");
            } else {
                printf("--This is all too familiar!\n");
                printf("--you:\n\n");
            }
            

            printf("1. Stop the alarm and wake up\n");
            if (game->wake_time < 4 && game->death_times < 2) {
                printf("2. Press snooze and go back to sleep\n");
            }
            
            choice = decision();
            clear();

            if (choice == 1) {
                printf("--You wake up\n\n");
                break;
            } else if (choice == 2 && game->wake_time < 4 && game->death_times < 2) {
                printf("--You go back to sleep...\n\n");
                game->wake_time++;
            }
        }
}

void getting_ready(stateT *game) {
    int choice = 0;
    printf("--You pick up your phone to check what time the bus to school is coming\n");
    if (game->death_times < 2) {
        if (game->wake_time < 3) {
            printf("--Seems you still have time\n");
        } else {
            printf("--You are late, the bus reaches the stop in like 1 min!\n");
        }
    } else {
        printf("--but before looking\n"); 
        printf("--Somehow you already know that you're early for the bus\n");
    }

    printf("--You open your wordrobe and see two T shirts you like\n");
    if (game->death_times == 1) {
        printf("--Hmmm...\n--Major deja vu...\n");
    } else if (game->death_times == 2) {
        printf("\n--These are the same two shirts you've always like!\n");
        printf("--All this has happened before! Those 'dreams'...\n");
        printf("--You pick the blue shirt instead in your fustration\n");
    }
    printf("--You decide to pick:\n\n");
    if (game->death_times > 1) {
        printf("1. The blue shirt\n");
    } else {
        printf("1. The plain white tee\n");
        printf("2. The black tee\n");
    }

    choice = decision();
    clear();

    if (game->death_times > 1) {
        if (choice == 1) {
            printf("--You swipe the blue shirt of its hanger\n");
            game->blue_shirt++;
        }
    } else {
        if (choice == 1) {
            printf("--Nothing beats a clasic white shirt!\n\n");
            game->shirt_color = WHITE;
            game->white_shirt++;
        } else if (choice == 2) {
            printf("--A safe black tee is the way to go!\n\n");
            game->shirt_color = BLACK;
            game->black_shirt++;
        }
    }

    if (game->wake_time < 3) {
        if (game->death_times > 1) {
            printf("You get changed, bolt out the front door and wait at the bustop \n\n");
        }
        printf("--You get changed and head downstairs for breakfast\n");
        printf("--After breakfast, you walk out to the bus stop\n\n");
    } else {
        printf("--You get changed and bolt through the front door\n\n");
    }
}

void otw(stateT *game) {
    int choice = 0;
    if (game->wake_time < 3) {
        printf("--The bus arrives and you get on\n");
        if (game->death_times > 1) {
            if (game->alone_on_bus == 0 && game->not_alone_on_bus == 0) {
                printf("--You try to remember what you know\n");
                printf("--or at least what you think you know from those 'dreams' you've had\n");
                printf("--Seems like you've never been this early before");
            } else if (game->alone_on_bus == 0 && game->not_alone_on_bus > 1) {
                printf("--You know stephanie is on the bus, but your mind's a mess now\n");
            } else if (game->alone_on_bus > 1 && game->not_alone_on_bus == 0) {
                printf("--The bus is crowded as it was 'the last time'\n");
            } else {
                printf("--You know stephanie is on the bus, but your mind's a mess now\n");
            }
        }
        if (game->death_times > 1) {
            printf("--You decide to:\n\n");
        } else {
            printf("--The bus seems like its a bit crowded, you decide to:\n\n");
        }

        printf("1. Stand where you are and wip out your phone\n");
        printf("2. Look around for seats anyways\n");

        choice = decision();
        clear();

        if (choice == 1) {
            if (game->death_times > 1) {
                printf("--You nervously take out and use your phone");
            } else {
                printf("--You wip out your phone and scroll through instagram\n\n");   
            }
            game->found_friend = NO;
            game->alone_on_bus++;
        } else {
            if (game->death_times > 1 && game->not_alone_on_bus > 0) {
                printf("--You head straight to where stephanie is seating\n");
            }
            printf("--You start to look around for seats\n\n");
            printf("--What this? you see your friend Stephanie on board too\n");
            printf("--AND she has an empty seat next to her *lucky!*. You go up to her and say hi\n\n");
            game->found_friend = YES;
            game->not_alone_on_bus++;

            if (game->shirt_color == WHITE) {
                printf("--She says 'Hey there Delilah, whats it like in new york?'\n");
                printf("--You stand there confused at first then realise, its the plain white tee shirt\n");
            } else {
                printf("--She says 'Wow! what a coincidence! you stalking me or something?\n");
            } 
            printf("--You roll your eyes, sit down and continue talking\n\n");
            printf("1. Enter 1 to continue: ");
            int i;
            scanf("%d", &i);
            while (i != 1) {
                printf("Please press 1\n");
                scanf("%d", &i);
            }
            if (i == 1) {
                clear();
            }
        }
    } else {
        printf("--You get out onto the walkway just in time to see the bus leave your stop\n");
        printf("--You try to run for it but obviously don't catch it\n\n");
        printf("--From here you remember that the first class is Comp4128-Programming Challenges,\n");
        printf("--attendence carries 5%% to the final grade and being late now means you lose that 5%%\n");
        printf("--You decide to:\n\n");

        printf("1. Run, can't afford to lose that 5%%\n");
        printf("2. Walk, I'm gonna retake it next sem anyways!\n");

        choice = decision();
        clear();

        if (choice == 1) {
            printf("You run to school!\n");
            game->ran = YES;
        } else if (choice == 2) {
            printf("You walk to school like a boss\n");
            game->ran = NO;
        }
    }
}

void in_school(stateT *game) {
    int choice = 0;
    if (game->wake_time < 3) {
        printf("--The bus pulls up to front of the school\n");
        if (game->found_friend == YES) {
            printf("--You and Stephanie alight the bus\n");
            printf("--She's abit late for her class so you and stephanie go seperate ways\n\n");
        } else if (game->found_friend == NO) {
            printf("--You alight the bus and head to class\n\n");
        }

        printf("--While walking to class, you see a crowd gather in the middle of the library lawn\n");
        printf("--They seem to be gathering around something\n");
        printf("--You decide to:\n\n");
        printf("1. Continue walking to class\n");
        printf("2. Take a look\n");

        choice = decision();
        clear();

        if (choice == 1) {
            printf("--You continue to walk to class\n");
            game->take_a_look = NO;
        } else if (choice == 2) {
            printf("--You are curious and decide to take a look\n");
            game->take_a_look = YES;
        }

    } else {
        if (game->ran == YES) {
            printf("--You arrived to school with very little minutes to spare\n");
            printf("--You run pass the library lawn\n");
            printf("--You see a crowd gather in the middle of the libary lawn\n");
            printf("--They seem to be gathering around something\n");
            printf("--You decide to:\n\n");
            printf("1. Continue running to class\n");
            printf("2. Take a look\n");

            choice = decision();
            clear();

            if (choice == 1) {
                printf("--You are late so no time to be curious\n");
                game->take_a_look = NO;
            } else if (choice == 2) {
                printf("--Just a quick look\n");
                game->take_a_look = YES;
                game->death_times++;
            }
        } else {
            printf("--You take your time walking. Since you're gonna miss your first class,\n");
            printf("--it means you're early for the second class\n");
            printf("--You think of what you're gonna do when you reach school so early\n\n");
            printf("--The school is now a block away, you can see it\n");
            printf("--Suddenly, a great big flash blinds you for a while and you fall to the ground\n");
            printf("--Everything's a blur, like in slowmotion. You open your eyes\n");
            printf("--You decide to:\n\n");
            printf("1. RUN AWAY!\n");
            printf("2. Run towards the school\n");

            choice = decision();
            clear();

            if (choice == 1) {
                printf("--WTF! was that a bomb!? in the school? You get yup and start running away from the school\n\n");
                game->take_a_look = NO;
            } else if (choice == 2) {
                printf("--For some reason, you feel the need to know what was that\n");
                printf("--As if by instinct, you run towards the school\n");
                game->take_a_look = YES;
            }

        }
    }
}

void boom(stateT *game) {
    if (game->ran == NO) {
        if (game->take_a_look == NO) {
            printf("--Oh gosh! What? How? what is going on?!\n");
            printf("--Never in your life you'd think this would happen to you!\n");
            printf("--You look over your shoulder, the light seems to be fading\n");
            printf("--You look back to the front\n\n");
            printf("--You realise you've been running without looking\n");
            printf("--You're on the road and from the corner of your eye you see a bus coming towards you\n");
            printf("--before you can react...\n\n");

            printf("1. Enter 1 to continue: ");
            int i;
            scanf("%d", &i);
            while (i != 1) {
                printf("Please press 1\n");                
                scanf("%d", &i);
            }
            if (i == 1) {
                clear();
                game->dead = YES;
                game->death_times++;
            }

        } else {
            printf("--You arrive at the library\n");
            printf("--there's people screaming and running away\n");
            printf("--You look over at the lawn\n");
            printf("--there are bodies lying on the ground\n");
            printf("--Your body freezes and you can't move a muscle\n\n");
            printf("1. Enter 1 to continue: ");
            int i;
            scanf("%d", &i);
            while (i != 1) {
                printf("Please press 1\n");
                scanf("%d", &i);
            }
            if (i == 1) {
                clear();
            }

        }
    } else if (game->take_a_look == YES) {
        printf("--You push pass the crowd trying to see what everyone's seeing\n");
        printf("--You break through to the middle\n");
        printf("--In the middle there's a crater and in it sits a wierd blue, glowing rock\n");
        printf("--A meteor?\n\n");
        printf("--Suddenly, the rock gets brighter and brighter until\n");
        printf("--BOOM! a great big flash. You are blinded by the light. you feel a great heat or cold\n");
        printf("--you can't tell\n");
        printf("--and then...\n\n");

        printf("1. Enter 1 to continue: ");
        int i;
        scanf("%d", &i);
        while (i != 1) {
            printf("Please pick a valid choice\n\n");                
            printf("Your choice: ");
            scanf("%d", &i);
        }
        if (i == 1) {
            clear();
            game->dead = YES;
            game->death_times++;
        } 
    } else {
        printf("--You arrive at your class door\n");
        printf("--You're about to open it when a big flash appears from behind you\n");
        printf("--like as if a lightning struct nearby but... no thunder\n");
        printf("--You look around\n");

        printf("1. Enter 1 to continue: ");
            int i;
            scanf("%d", &i);
            while (i != 1) {
                printf("Please press 1\n");
                scanf("%d", &i);
            }
            if (i == 1) {
                clear();
            }
    }
}

void after_boom(stateT *game) {
    
    if (game->dead == NO) {
        int choice = 0;
        printf("1. die\n");
        printf("2. live\n");

        choice = decision();
        clear();
        if (choice == 1) {
            printf("LOL\n");
            game->dead = YES;
            game->death_times++;
        } else if (choice == 2) {
            printf("LIVE\n");
        }
    }
}





//--------------------HELPERS--------------------
//-----------------------------------------------
int decision(void) {
    printf("\n");
    printf("Your choice: ");
    int choice = 0;
    scanf("%d", &choice);
    printf("\n");

    while (choice != 1 && choice != 2) {
        printf("Please pick a valid choice\n\n");                
        printf("Your choice: ");
        scanf("%d", &choice);
    }
    
    return choice;
}

void clear(void) {
    system("cls");
}


