# 문제 . 1103


게임판 위에서 동전을 몇번 움직여야하는지 구해야하는 문제이다.
처음 접근은 DFS만을 통해서 접근을했다가 4^(50+50) 시간복잡도로 시간 초과가 나서 DFS+DP 를 통해서 접근하였다.
######
총 두가지의 가지가 있다. 한사이클 안에서 같은 곳을 방문했을때 이는 무한대로 게임을 할수있으므로 exit(0) 을 통해 게임 종료 

그리고 한사이클 내에서 같은 곳이아닌 이전에 dp테이블 내에서 접근을 했던경우는 이미 dp테이블에 최대의 경로가 저장되어있기 때문에 그 지점에서는 DFS를 구성하는것이 아닌 DP값만 return 해준다. dp[now_y][now_x]=max(dp[now_y][now_x],dfs(now_y,now_x)+1) 을 통해서 dp값을 update해준다.

