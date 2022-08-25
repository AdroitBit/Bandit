/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############

*/



#include <stdio.h>

#define CHAR_WALL '#'
#define CHAR_WALKABLE ' '
#define CHAR_PATH '.'
#define CHAR_START 'S'
#define CHAR_GOAL 'G'

#define NO_MOVE '\0'
#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'




int print_maze(char* maze, int w,char* movesets,int movesets_len){
    for(int i=0;i<w;++i){
        for(int j=0;j<w;++j){
            printf("%c",maze[i*w+j]);
        }
        printf("\n");
    }

    return 0;
}


int current_point(int* res_x,int* res_y,char* maze, int w, char* moveset,int moveset_len){
    int x,y;
    for(int j=0;j<w;++j){
        for(int i=0;i<w;++i){
            if(maze[j*w+i]==CHAR_START){
                x=i;
                y=j;
            }
        }
    }
    for(int i=0;i<moveset_len;++i){
        switch(moveset[i]){
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
        }
    }
    *res_x=x;
    *res_y=y;
    return 0;
}

int next_possible_moves(char* next_moves,char* maze, int w,char* movesets,int moveset_len){
    int x,y;
    current_point(&x,&y,maze,w,movesets,moveset_len);
    int n=0;
    if(maze[y*w+x+1]==CHAR_WALKABLE || maze[y*w+x+1]==CHAR_GOAL){
        next_moves[n]=RIGHT;
        ++n;
    }
    if(maze[y*w+x-1]==CHAR_WALKABLE || maze[y*w+x-1]==CHAR_GOAL){
        next_moves[n]=LEFT;
        ++n;
    }
    if(maze[(y+1)*w+x]==CHAR_WALKABLE || maze[(y+1)*w+x]==CHAR_GOAL){
        next_moves[n]=DOWN;
        ++n;
    }
    if(maze[(y-1)*w+x]==CHAR_WALKABLE || maze[(y-1)*w+x]==CHAR_GOAL){
        next_moves[n]=UP;
        ++n;
    }
    next_moves[n]=NO_MOVE;
    return n;
} 

int traverse_maze(char* maze, int w,char* movesets,int movesets_len){
    int x,y;
    current_point(&x,&y,maze,w,movesets,movesets_len);
    print_maze(maze,w,movesets,movesets_len);

    if(maze[y*w+x]==CHAR_GOAL){
        return movesets_len;
    }
    
    int n=0;
    char next_moves[4];
    next_possible_moves(next_moves,maze,w,movesets,movesets_len);
    for(int i=0;next_moves[i]!=NO_MOVE;++i){
        movesets[movesets_len]=next_moves[i];
        int l=traverse_maze(maze,w,movesets,movesets_len+1);
        if(l==-1){
            continue;
        }
        if(l>0){
            return l;
        }
    }
    return -1;
}




int main(){
    int w;
    char maze[2000];//50 max width
    char movesets[100];
    scanf("%d",&w);
    getchar();
    for(int j=0;j<w;++j){
        fgets(&maze[j*w],1000,stdin);
    }

   
    //printf("Works good");

    traverse_maze(maze,w,movesets,0);

    //print_maze(maze,w,movesets);



    /*

    int x,y;
    current_point(&x,&y,maze,w,movesets,0);
    print_maze(maze,w,movesets);
    printf("%d %d\n",x,y);

    

    char next_moves[8];
    printf("Works good");
    next_possible_moves(next_moves,maze,w,movesets,movesets);
    for(int i=0;i<4;++i){
    
        printf("%c",next_moves[i]);
    }
    */



    //init_maze(maze,w);
    //print_maze(maze,w);

    
    return 0;
}