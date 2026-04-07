# [상근이의 여자친구](https://www.acmicpc.net/problem/4454)

| 시간 제한 | 메모리 제한 |
| :---: | :---: |
| 1 초 | 128 MB |

## 문제

상근이는 여자친구를 데리러 가야 한다. 상근이의 차에는 기름이 t만큼 있고, 여자친구는 상근이가 현재 있는 위치와 m킬로미터 떨어져 있다.

상근이는 여자친구를 최대한 빨리 데리러 가야 하기 때문에, 중간에 주유소에 들릴 시간이 없다. 어렸을 때부터 물리, 수학 영재로 전국에 이름을 날리던 상근이는 차의 속도에 따라 소모되는 기름의 양을 계산했다.

속도가 시속 v 킬로미터 일 때, 한시간 동안 소모되는 기름의 양은 다음과 같다.

av<sup>4</sup> + bv<sup>3</sup> + cv<sup>2</sup> + dv

상근이는 출발할 때부터 도착할 때까지 일정한 속도로 이동한다. 기름이 바닥나지 않으면서 최대한 여자친구에게 빨리가려면 시속 몇 킬로미터로 이동해야 하는지 출력한다.

## 입력

입력은 여러 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 음이 아닌 여섯 개의 실수로 이루어져 있다. 이 실수는 순서대로 a, b, c, d, m, t이다. 모든 값은 1000을 넘지 않으며, c, d, m, t값은 양수이다. 항상 답이 존재하는 경우만 입력으로 주어진다.

## 출력

각 테스트 케이스에 대해서 기름이 바닥나지 않으면서 여자친구에게 가장 빨리 도착하려면 시속 몇 킬로미터로 달려야 하는지를 소수점 둘째자리까지 출력한다. (버림해서 출력한다.)

## 예제 입력 1

```
0.000001 0.0001 0.029 0.2 12 100
2.8e-8 7.6e-6 0.0013 0.47 11.65 20.81
1.559e-7 1.8195e-5 0.0022233 0.31292 58.902 85.585
```

## 예제 출력 1

```
134.41
257.45
142.65
```

## 출처

[ICPC](https://www.acmicpc.net/category/1) > [Regionals](https://www.acmicpc.net/category/7) > [North America](https://www.acmicpc.net/category/8) > [Pacific Northwest Regional](https://www.acmicpc.net/category/33) > [2011 Pacific Northwest Region Programming Contest](https://www.acmicpc.net/category/detail/126) H번

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
