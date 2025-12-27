#include <stdio.h>

#include <string.h>

int main()

{

    // 암호가 하나 주어짐.

    char code[5001]; scanf("%s", code );

    // 암호의 길이

    int len = strlen( code ); 

    

    // 열의 의미는 해당 인덱스까지 도달 했을 때

    // 1행은 이전 인덱스를 이용하지 현재 인덱스만을 이용 했을 때의 해석의 가짓수

    // 2행은 이전 인덱스를 사용하여 이전 및 현재 인덱스를 합쳐서 이용 했을 때의 해석의 가짓수

    int num_Translate[ 5000 ][2];

    

    // 초기값이 주어진다.

    // 처음부터 값이 0이라면 암호 해독이 불가능하다.

    if ( code[0] == '0')

    {

        printf("0");

        return 0;

    }

    else

    {

        num_Translate[0][0] = 1; num_Translate[0][1] = 0;

    }

    

    

    // 인덱스를 증가해나가면서 끝까지 도달한 경우의 가짓수를 저장한다.

    for (int now_Index = 1; now_Index < len; now_Index++ )

    {

        // 현재 인덱스에 해당하는 암호값이 0인 경우

        if ( code[ now_Index ] == '0' )

        {

            // 이전 인덱스 암호값이 0이거나 3이상인 경우 암호를 해독할 수 없다.

            if ( code[ now_Index - 1 ] == '0' || code[ now_Index - 1 ] >= '3' )

            {

                printf("0");

                return 0;

            }

            

            else

            {

                num_Translate[ now_Index ][0] = 0;

                num_Translate[ now_Index ][1] = num_Translate[ now_Index - 1 ][0];

            }

        }

        

        

        //앞의 인덱스에 해당하는 암호값이 0인 경우

        else if ( code[ now_Index - 1 ] == '0' )

        {

            num_Translate[ now_Index ][0] = num_Translate[ now_Index - 1 ][1];

            num_Translate[ now_Index ][1] = 0;

        }

        

        

        // 이전 인덱스나 현재 인덱스의 암호값이 둘다 0이 아닌 경우

        else

        {

            // 이전 인덱스 암호값이 1인 경우

            if ( code[ now_Index - 1 ] == '1' )

            {

                num_Translate[ now_Index ][0] = num_Translate[ now_Index - 1 ][0] + num_Translate[ now_Index - 1 ][1];

                num_Translate[ now_Index ][0] %= 1000000;

                

                num_Translate[ now_Index ][1] = num_Translate[ now_Index - 1 ][0] % 1000000;

            }

            

            // 이전 인덱스 암호값이 2인 경우

            else if ( code[ now_Index - 1 ] == '2' )

            {

                // 현재 인덱스 암호값이 1이상 6이하라면 앞 인덱스와 붙여서 해석 할 수도 있다.

                if ( '1' <= code[ now_Index ] && code[ now_Index] <= '6')

                {

                    num_Translate[ now_Index ][0] = num_Translate[ now_Index - 1 ][0] + num_Translate[ now_Index - 1 ][1];

                    num_Translate[ now_Index ][0] %= 1000000;

                    

                    num_Translate[ now_Index ][1] = num_Translate[ now_Index - 1 ][0] % 1000000;

                }

                

                // 앞 인덱스 암호값과 붙여서 해석 할 수 없는 경우

                else

                {

                    num_Translate[ now_Index ][0] = num_Translate[ now_Index - 1 ][0] + num_Translate[ now_Index - 1 ][1];

                    num_Translate[ now_Index ][0] %= 1000000;

                    

                    num_Translate[ now_Index ][1] = 0;

                }

                

            }

            

            // 이전 인덱스 암호값이 3이상인 경우

            else

            {

                num_Translate[ now_Index ][0] = num_Translate[ now_Index - 1 ][0] + num_Translate[ now_Index - 1 ][1];

                num_Translate[ now_Index ][0] %= 1000000;

                    

                num_Translate[ now_Index ][1] = 0;

            }

            

        }

    }

    

    // 결과값은 마지막 암호를 이전값과 함께 해독한 경우와 마지막 암호 하나만으로 해독한경우의 합을 출력해준다.

    printf("%d", ( num_Translate[ len - 1 ][0] + num_Translate[ len - 1 ][1] ) % 1000000 );

    return 0;

}

