# [1039] 교환

# 문제
0으로 시작하지 않는 정수 N이 주어진다. 이때, M을 정수 N의 자릿수라고 했을 때, 다음과 같은 연산을 K번 수행한다.

1 ≤ i < j ≤ M인 i와 j를 고른다. 그 다음, i번 위치의 숫자와 j번 위치의 숫자를 바꾼다. 이때, 바꾼 수가 0으로 시작하면 안 된다.

위의 연산을 K번 했을 때, 나올 수 있는 수의 최댓값을 구하는 프로그램을 작성하시오.
# 입력
첫째 줄에 정수 N과 K가 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, K는 10보다 작거나 같은 자연수이다.
# 출력
첫째 줄에 문제에 주어진 연산을 K번 했을 때, 만들 수 있는 가장 큰 수를 출력한다. 만약 연산을 K번 할 수 없으면 -1을 출력한다.
# 예제 입력 1
```python
16375 1
```  

# 예제 출력 1
```python1
76315

```

# 풀이
<br>
DFS만을 가지고 풀이를 진행 했는데 문자열의 길이가 최대 7이고 깊이가 10이상을 넘어가므로 21^10의 시간 복잡도를 갖게 되는것을
확인했다. 그래서 이를 트리형태로 구성하다보면 같은 깊이에 중복되는 숫자가 많이 존재하는것을 확인 이를 해결하기 위해 DFS 와 DP를 결합했다.
2차원DP를 이용해 dp[number][depth]=max(dp[number][depth] , dfs(number,depth+1) 의 형식으로 접근한다면 같은 레벨에있는 경우 
이미 존재했던 수라면 dp에 해당하는 수를 return함으로써 중복을 줄였다.

