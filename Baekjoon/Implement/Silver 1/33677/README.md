# [푸앙이와 콩나무](https://www.acmicpc.net/problem/33677)

| 시간 제한 | 메모리 제한 |
| :---: | :---: |
| 1 초 | 1024 MB |

## 문제

잭과 콩나무를 감명 깊게 읽은 푸앙이는 동화책에 나오는 신비한 힘을 지닌 콩을 구해 하늘나라에 있는 거인의 성에 올라가려고 한다. 하지만 신비한 힘을 지닌 콩을 구하지 못한 푸앙이는 대신 평범한 콩나무에 하루에 한 번씩 물을 주어 하늘나라에 올라가려 한다. 콩나무는 다음 규칙을 따라 자란다.

- 물을 $1$만큼 주면 다음 날 콩나무의 길이가 $1$ 증가한다.
- 물을 $3$만큼 주면 다음 날 콩나무의 길이는 $3$배가 된다.
- 물을 $5$만큼 주면 다음 날 콩나무의 길이는 제곱이 된다.
- 다른 양의 물을 준 경우에는 콩나무의 길이가 변하지 않는다.

$0$번째 날의 초기 콩나무 길이는 $0$이다. 푸앙이가 거인의 성에 도착하려면 콩나무의 길이가 정확히 $N$이 되어야 하며, 콩나무의 길이가 $N$이 된 날에 푸앙이는 거인의 성에 도착할 수 있게 된다. 푸앙이가 거인의 성에 도착하려면 적어도 며칠이 필요할지와 적어도 얼마나 물이 필요할 지 구해보자.

## 입력

첫 번째 줄에 거인의 성에 도착하기 위해 필요한 콩나무의 길이 $N$이 주어진다.

## 출력

첫 번째 줄에 푸앙이가 거인의 성에 도착하기 위해 필요한 최소 일수와 최소 일수만에 거인의 성에 도착하기 위해 필요한 물의 양의 최솟값을 공백으로 구분하여 출력한다.

## 제한

- $0 \le N \le 1\,000\,000$

## 예제 입력 1

```
4
```

## 예제 출력 1

```
3 5
```

## 예제 입력 2

```
48
```

## 예제 출력 2

```
5 13
```

## 출처

[University](https://www.acmicpc.net/category/5) > [중앙대학교](https://www.acmicpc.net/category/400) > [중앙대학교 프로그래밍 경진대회 (CPC)](https://www.acmicpc.net/category/1103) > [2025 중앙대학교 프로그래밍 경진대회 (CPC)](https://www.acmicpc.net/category/detail/4458) B2번

- 문제를 만든 사람: [skjd1234](https://www.acmicpc.net/user/skjd1234)
- 문제를 검수한 사람: [asdarwin03](https://www.acmicpc.net/user/asdarwin03), [dkvltmxhf](https://www.acmicpc.net/user/dkvltmxhf), [halin](https://www.acmicpc.net/user/halin), [jinhan814](https://www.acmicpc.net/user/jinhan814), [jk410](https://www.acmicpc.net/user/jk410), [kevinlys00](https://www.acmicpc.net/user/kevinlys00), [mujigae](https://www.acmicpc.net/user/mujigae), [nflight11](https://www.acmicpc.net/user/nflight11), [qvixnh22](https://www.acmicpc.net/user/qvixnh22), [sksms1375](https://www.acmicpc.net/user/sksms1375), [tony9402](https://www.acmicpc.net/user/tony9402), [utilforever](https://www.acmicpc.net/user/utilforever), [wapas](https://www.acmicpc.net/user/wapas), [yup0927](https://www.acmicpc.net/user/yup0927)
