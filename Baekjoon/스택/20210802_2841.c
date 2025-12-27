#include <stdio.h>


int top[6] = {-1, -1, -1, -1, -1, -1}; //줄별로 stack을 구현했기에 맞춰서 top도 구현했다.
int stack[6][500010]; //스택을 줄별로 구현했다.

void push(int num_of_Melody, int fret) { 
    
    stack[num_of_Melody - 1][++top[num_of_Melody - 1]] = fret;
}

void pop (int num_of_Melody) {
    
    top[num_of_Melody - 1]--;
}



int main() {
    
    int min_Finger_Moving = 0;
    int N, F; //사실 fret은 왜 할당 받아야하는지 이해할 수 없다. 다음 구현에서 사용 안함.
    scanf("%d %d", &N, &F);
    
    
    for (int now_turn = 1; now_turn <= N; now_turn++) {
        
        int num_String, num_Fret; //num_String은 줄의 번호, num_Fret은 눌러야 하는 프렛의 번호.
        scanf("%d %d", &num_String, &num_Fret);
        
        
        if (top[num_String - 1] != -1) {
            
            if ( stack[num_String - 1][top[num_String - 1]] < num_Fret) { //해당 줄 top에 있는 프렛보다 클 경우.
                
                push(num_String, num_Fret);
                min_Finger_Moving++;
            }
            else if (stack[num_String - 1][top[num_String - 1]] == num_Fret) { //해당 줄 top에 있는 프렛과 같은 경우.
                
                continue;
            }
            else { //해당 줄 top 에 있는 수보다 fret이 작을 경우.
                
                while(1) {
                    
                    pop(num_String); min_Finger_Moving++; //pop을 함과 동시에 손가락을 때니 이때도 움직임 +1 해준다.

                    if ( stack[num_String - 1][top[num_String - 1]] < num_Fret) { //해당 줄 top에 있는 프렛보다 클 경우.
                
                        push(num_String, num_Fret);
                        min_Finger_Moving++;
                        break;
                    }
                    else if (stack[num_String - 1][top[num_String - 1]] == num_Fret) { //해당 줄 top에 있는 프렛과 같은 경우.
                
                        break;
                    }
                    else {
                        
                        continue;
                    }
                    
                }
                
            }
            
        }
        else {//해당 줄에 스택이 비어있는 경우.
            
            push(num_String, num_Fret); //탑이 비어있으면 push해야지.
            min_Finger_Moving++; //당연하게도 손가락 한번 튕겨주고.
        }
        
    }
    
    
    printf("%d", min_Finger_Moving);
    
    return 0;
}