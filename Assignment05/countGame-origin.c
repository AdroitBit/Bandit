#include <stdio.h>
#include <stdlib.h>
typedef struct person {
    int limit_n_drink;
    int n_drink;
    int name;
    struct person* next;
    struct person* prev;
} person_t;

void display(person_t* start_person){
    person_t* curr = start_person;
    while(curr != NULL){
        printf("%d %d %d\n",curr->name,curr->limit_n_drink,curr->n_drink);
        curr = curr->next;
    }
}

void display_rev(person_t* start_person){
    person_t* curr = start_person;
    while(curr != NULL){
        printf("%d %d %d\n",curr->name,curr->limit_n_drink,curr->n_drink);
        curr = curr->prev;
    }
}


#include <time.h>
  
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}


int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);

    person_t* first_person;
    first_person = (person_t*)malloc(sizeof(person_t));
    person_t* current_person = first_person;

    int i=0;
    do{
        int limit_n_drink;
        scanf(" %d",&limit_n_drink);
        
        current_person->limit_n_drink = limit_n_drink;
        current_person->n_drink = 0;
        current_person->name = i+1;
        
        ++i;
        if(i<n){
            person_t* next_person = (person_t*)malloc(sizeof(person_t));
            current_person->next = next_person;
            next_person->prev = current_person;
            current_person=next_person;
        }else{
            current_person->next = NULL;
            break;
        }
    }while(i<n);
    
    current_person->next = first_person;
    first_person->prev = current_person;
    //display_rev(first_person);

    //find GigaChad
    int speaking_num=1;
    current_person=first_person;
    while(1){

        if(0){
            break;
        }
        if(speaking_num%k==0){
            current_person->n_drink++;
            printf("%d %d\n",current_person->prev->name,current_person->next->name);
            printf("%d drink | %d %d\n",current_person->name,speaking_num,k);
            if(current_person->n_drink>current_person->limit_n_drink){
                printf("%d is dead\n",current_person->name);

                person_t* temp = current_person;

                current_person->next->prev = current_person->prev;


                if(current_person->next->n_drink<=current_person->next->limit_n_drink){
                    current_person=current_person->next;
                }else{
                    current_person=current_person->next->next;
                }
                

                temp->prev=NULL;
                temp->next=NULL;
                //break;
            }else{
                current_person = current_person->next;
            }
            printf("\n");
        }else{
            printf("%d %d\n",current_person->prev->name,current_person->next->name);
            printf("%d not drink | %d %d\n\n",current_person->name,speaking_num,k);
            current_person=current_person->next;
        }
        
        speaking_num++;
        delay(500); 
    }


    printf("%d\n",current_person->name);





    
    
    
    

    return 0;
}