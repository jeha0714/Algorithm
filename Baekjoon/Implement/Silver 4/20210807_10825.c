#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct //반 학생들 이름 및 성적 구조체.
{
    char name[11];
    short korean;
    short english;
    short math;
    
}Student_Score;


int compare (const void * first, const void * second) { //문제 조건에 따라 조건 구현.
    
    if ( ((Student_Score *)first) -> korean < ((Student_Score *)second) -> korean ) { //국어점수가 감소하는 순서.
        return 1;
    }
    
    else if ( ((Student_Score *)first) -> korean == ((Student_Score *)second) -> korean ) { //영어 점수가 증가하는 순서
        
        if ( ((Student_Score *)first) -> english < ((Student_Score *)second) -> english ) {
            return -1;
        }
        
        else if ( ((Student_Score *)first) -> english == ((Student_Score *)second) -> english )  {//수학 점수가 감소하는 순서.
                
                
                if ( ((Student_Score *)first) -> math < ((Student_Score *)second) -> math ) {
                    return 1;
                }
                else if ( ((Student_Score *)first) -> math == ((Student_Score *)second) -> math )  { //사전순으로 증가하는 순서.
                
                    return strcmp(((Student_Score *)first) -> name, ((Student_Score *)second) -> name);
                }
                else {return -1;}
            
        }
            
        else {return 1;}
        
    }
    else {return -1;}
    
}



int main() {
    
    int N; //반 학생 수 N명.
    scanf("%d", &N);
    Student_Score all_Student[N]; //구조체 배열로 구현.
    
    for (int i = 0 ; i < N; i++) { //인적사항 기입.
        
        scanf("%s %hd %hd %hd", all_Student[i].name, &all_Student[i].korean, &all_Student[i].english, &all_Student[i].math);
    }
    
    
    qsort (all_Student, N, sizeof(all_Student[0]), compare); //정렬.
    
    
    for (int i = 0 ; i < N ; i++) {
        printf("%s\n", all_Student[i].name);
    }
    
    
    return 0;
}