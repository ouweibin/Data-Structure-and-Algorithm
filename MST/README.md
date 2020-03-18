## 最小生成树

#### 有权图

- 有权图的表示

  Edge类



#### 最小生成树问题和切分定理

- Minimum Span Tree（针对带权无向图并且是连通图）

  找出V-1条边，连接V个顶点，使总权值最小

- 切分定理

  切分

  横切边

  **给定任意切分，横切边中权值最小的边一定属于最小生成树**



#### Prim算法的第一个实现

- Lazy Prim

  时间复杂度`O(ElogE)`



#### Prim算法的优化

- 使用IndexMinHeap数据结构

  时间复杂度`O(ElogV)`



#### Kruskal算法

- 先对权值排序

- 使用Union Find快速判断是否有环

- 时间复杂度`O(ElogE)`



#### 最小生成树算法的思考



#### 参考

1. [算法与数据结构--综合提升篇（c++版）](https://coding.imooc.com/class/71.html)