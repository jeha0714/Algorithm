# [[PCCE 기출문제] 9번 / 이웃한 칸](https://school.programmers.co.kr/learn/courses/30/lessons/250125)

## 문제 설명

각 칸마다 색이 칠해진 2차원 격자 보드판이 있습니다. 그중 한 칸을 골랐을 때, 위, 아래, 왼쪽, 오른쪽 칸 중 같은 색깔로 칠해진 칸의 개수를 구하려고 합니다.

보드의 각 칸에 칠해진 색깔 이름이 담긴 이차원 문자열 리스트 `board`와 고른 칸의 위치를 나타내는 두 정수 `h`, `w`가 주어질 때 `board[h][w]`와 이웃한 칸들 중 같은 색으로 칠해져 있는 칸의 개수를 return 하도록 solution 함수를 완성해 주세요.

이웃한 칸들 중 몇 개의 칸이 같은 색으로 색칠되어 있는지 확인하는 과정은 다음과 같습니다.

```
1. 정수를 저장할 변수 n을 만들고 board의 길이를 저장합니다.
2. 같은 색으로 색칠된 칸의 개수를 저장할 변수 count를 만들고 0을 저장합니다.
3. h와 w의 변화량을 저장할 정수 리스트 dh, dw를 만들고 각각 [0, 1, -1, 0], [1, 0, 0, -1]을 저장합니다.
4. 반복문을 이용해 i 값을 0부터 3까지 1 씩 증가시키며 아래 작업을 반복합니다.
    4-1. 체크할 칸의 h, w 좌표를 나타내는 변수 h_check, w_check를 만들고 각각 h + dh[i], w + dw[i]를 저장합니다.
    4-2. h_check가 0 이상 n 미만이고 w_check가 0 이상 n 미만이라면 다음을 수행합니다.
        4-2-a. board[h][w]와 board[h_check][w_check]의 값이 동일하다면 count의 값을 1 증가시킵니다.
5. count의 값을 return합니다.
```

- 위의 의사코드와 작동방식이 다른 코드를 작성해도 상관없습니다.

---

## 제한사항

- 1 ≤ `board`의 길이 ≤ 7
  - `board`의 길이와 `board[n]`의 길이는 동일합니다.
- 0 ≤ `h`, `w` < `board`의 길이
- 1 ≤ `board[h][w]`의 길이 ≤ 10
  - `board[h][w]`는 영어 소문자로만 이루어져 있습니다.

---

## 입출력 예

| board | h | w | result |
| --- | --- | --- | --- |
| [["blue", "red", "orange", "red"], ["red", "red", "blue", "orange"], ["blue", "orange", "red", "red"], ["orange", "orange", "red", "blue"]] | 1 | 1 | 2 |
| [["yellow", "green", "blue"], ["blue", "green", "yellow"], ["yellow", "blue", "blue"]] | 0 | 1 | 1 |

---

## 입출력 예 설명

입출력 예 #1

- 주어진 보드를 나타내면 아래 그림과 같고, `board[1][1]`의 인접한 칸들은 화살표가 가리키는 칸들입니다. 따라서 `board[1][1]` 주변의 "red" 칸은 총 2개입니다.

![9-1.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/cb8c0433-a307-4184-b224-6185c87dfc07/9-1.jpg)

입출력 예 #2

- 주어진 보드를 나타내면 아래 그림과 같고, `board[0][1]`의 인접한 칸들은 화살표가 가리키는 칸들입니다. 따라서 `board[0][1]` 주변의 "green"칸은 총 1개입니다.

![9-2.jpg](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/a9fdec91-df64-4240-82b3-c63d9555e689/9-2.jpg)

---

- cpp를 응시하는 경우 리스트는 배열과 동일한 의미이니 풀이에 참고해주세요.
  - ex) 번호가 담긴 정수 <u>**리스트**</u> `numbers`가 주어집니다. => 번호가 담긴 정수 <u>**배열**</u> `numbers`가 주어집니다.
- java를 응시하는 경우 리스트는 배열, 함수는 메소드와 동일한 의미이니 풀이에 참고해주세요.
  - ex) solution <u>**함수**</u>가 올바르게 작동하도록 한 줄을 수정해 주세요. => solution <u>**메소드**</u>가 올바르게 작동하도록 한 줄을 수정해 주세요.
