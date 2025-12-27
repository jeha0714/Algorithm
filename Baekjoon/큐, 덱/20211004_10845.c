#include <stdio.h>
#include <string.h>


int main(void)
{
    int num_Func;   scanf("%d", &num_Func); // 명령의 수
    int array_Queue[ num_Func ]; // 큐를 배열로 선언. 
    int Front = 0, Rear = 0;
    
    
    for (int now_Func = 0; now_Func < num_Func ; now_Func++ )
    {
        char func[7]; scanf("%s", func); // 명령이 주어짐
        
        if ( strcmp(func, "push") == 0 )
        {
            int push_Num; scanf("%d", &push_Num); // 큐에 삽입될 정수
            
            array_Queue[ Rear++ ] = push_Num;
        }
        
        else if ( strcmp(func, "pop") == 0 )
        {
            if ( Front == Rear )
                printf("-1\n");
            else
                printf("%d\n", array_Queue[ Front++ ] );
        }
        
        else if ( strcmp(func, "size") == 0 )
        {
            printf("%d\n", Rear - Front);
        }
        
        else if ( strcmp(func, "empty") == 0 )
        {
            if ( Front == Rear )
                printf("1\n");
            else
                printf("0\n");
        }
        
        else if ( strcmp(func, "front") == 0 )
        {
            if ( Front == Rear )
                printf("-1\n");
            else
                printf("%d\n", array_Queue[ Front ] );
        }
        
        else if ( strcmp(func, "back") == 0 )
        {
            if ( Front == Rear )
                printf("-1\n");
            else
                printf("%d\n", array_Queue[ Rear - 1 ] );
        }
        
    }
    
    
    
    return 0;
}