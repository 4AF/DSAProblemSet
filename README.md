# 数据结构与算法Moodle平台作业题

## 一、线性表作业

### 1、[顺序表删除](1-1.c)

```
在已给出的顺序表中删除x元素
用例1：输入 1 2 x 4 5
输出 1 2 4 5
用例2：输入 x 11 22 x 22
输出 11 22 22
用例3 输入 x y x x x y
输出 y y
用例4： 输入 1 2 3 4 x
输出：1 2 3 4
```

### 2、[顺序表插入](1-2.c)

```
将元素x插入到给定顺序表的指定位置
用例1：输入 1 2 3 4 5，位置3
输出： 1 2 x 3 4 5
用例2：输入 1 2 3 4 5， 位置1
输出：x 1 2 3 4 5
用例3：输入 1 2 3 4 5，位置6
输出：1 2 3 4 5 x
用例4：输入 ，位置1；
输出：x
```

### 3、[构建一个约瑟夫环](1-3.c)

```
构建一个大小可变的约瑟夫环，并输出步长为3时的剩余元素
用例1：输入 41；
输出： 16 31
用例2：输入2
输出：1 2
用例3：输入16
输出：1 8
用例4：输入100
输出：58 91
```

### 4、[商品归类](1-4.c)

```
将已有商品链表和新进商品链表，进行归类整合

用例：输入： 已有：A 3, C 5, D 6;
新进：A 2, B 3, C 5, E 7, F 8;

输出：A 5, B 3, C 10, D 6, E 7, F 8;
```

## 二、受限线性表作业

### 1、[表达式括号匹配](2-1.c)

```
对给出得表达式进行括号匹配，若成功输出“匹配成功”，若不成功则输出“缺少X括号”；
用例1：输入：{a+[b*(d+c)]}
输出：匹配成功
用例2：输入：(a+b)*c]
输出：缺少[括号
用例3：输入：{[(a+b)*(c+d)]+e
输出：缺少}括号
用例4：输入：{[(a+b)*(c+d)]+e)
输出：缺少(括号缺少}括号
```

### 2、[实现杨辉三角](2-2.c)

```
使用大小为100得队列存储杨辉三角形，并输出杨辉三角形得第x行
用例1：输入：1
输出：1
用例2：输入：5
输出：1 4 6 4 1
用例3：输入：20
输出：1 19 171 969 3876 11628 27132 50388 75582 92378 92378 75582 50388 27132 11628 3876 969 171 19 1
用例4：输入：100
输出：队列已满
```

### 3、[火车车厢重排](2-3.c)

```
实现有三个缓冲轨得火车重排算法，使得无序得火车车厢，重排为小号车厢在前端，大号车厢在后端得有序序列。
用例1：输入：4 2 1 3 5
输出：5 4 3 2 1
用例2：1 2 3 4 5
输出：重排失败
```

### 4、[实现字符串匹配得KMP算法](2-4.c)

```
实现主串为“abacababdeadcde”，模式串为任意输入串得，字符串匹配结果，同时输出模式串得Next数组；
用例1：输入：abab
输出：匹配成功
-1001；
用例2：输入：ababb
输出：匹配未成功
-10012
用例3：deadc
输出：匹配成功
-10001
用例4：输入：abced
输出：匹配未成功
-10000
```

## 三、树与二叉树作业

### 1、[二叉树的遍历](3-1.c)

```
对给定的二叉树分别输出其先序遍历、中序遍历后序遍历序列。测试用例中，0代表空。
测试用例1：输入：AB0C
输出：ABC
CBA
CBA
测试用例2：输入：ABC0DE000F
输出：ABDFCE
BFDAEC
FDBECA
```

### 2、[哈夫曼编码](3-2.c)

```
对于给定的字符集合A,B,C,D,E,F,G,H，依次按给定的出现频率构建哈夫曼树，并输出字符串ABCDEFGH的哈夫曼序列。哈夫曼树要求左孩子不大于右孩子。
测试用例1：输入：1 2 4 8 16 32 64 128
输出：00000000000001000001000010001001011
测试用例2：输入：5 10 7 9 11 13 14 16
输出：1010011101101010011011100
```

### 3、[平衡二叉查找树](3-3.c)

```
对于给定的整数序列，构造平衡二叉查找树，并分层遍历构成的二叉查找树，关键字间以空格分隔。
测试用例1：输入：3 10 24 65 32
输出：10 3 32 24 65
测试用例2：输入：16 7 10 9 30
输出：10 7 16 9 30
```

### 4、[大项堆](3-4.c)

```
利用筛选法对给定的关键字序列构成大顶堆，并采用顺序表存储输出该大顶堆（关键字之间以空格分隔）。
测试用例1：输入：14, 16, 21, 18, 30, 35
输出：35 30 21 18 16 14
测试用例2：3 13 4 7 12 1 6 2 9 8
输出：13 12 6 9 8 1 4 2 7 3
```

## 四、图作业

### 1、[图的遍历](4-1.c)

```
根据给定的顶点为A,B,C,D,E,F,G，H，I的做组成图的邻接矩阵，给出图的深度优先及广度优先遍历序列。
用例1：输入：
0 1 1 1 -1 -1 -1 -1 -1
1 0 1 -1 1 -1 -1 -1 -1
1 1 0 -1 -1 1 -1 -1 -1
1 -1 -1 0 -1 1 -1 -1 -1
-1 1 -1 -1 0 -1 1 -1 -1
-1 -1 1 1 -1 0 -1 1 -1
-1 -1 -1 -1 1 -1 0 -1 1
-1 -1 -1 -1 -1 1 -1 0 1
-1 -1 -1 -1 -1 -1 1 1 0
输出：ABCFDHIGE
ABCDEFGHI

用例2：输入：
0 1 1 1 -1 -1 -1 -1 -1
-1 0 1 -1 1 -1 -1 -1 -1
-1 -1 0 -1 -1 1 -1 -1 -1
-1 -1 -1 0 -1 -1 -1 -1 -1
-1 1 -1 -1 0 -1 1 -1 -1
-1 -1 1 1 -1 0 -1 1 -1
-1 -1 -1 -1 -1 -1 0 -1 1
-1 -1 -1 -1 -1 -1 -1 0 1
-1 -1 -1 -1 -1 -1 -1 -1 0

输出：ABCFDHIEG
ABCDEFGHI
```

### 2、[最短路径](4-2.c)

```
求给定图的中顶点A（第一个顶点，即邻接矩阵中第一行第一列）到其他顶点的最短路径。

用例： 输入：
0 10 -1 25 80
-1 0 40 -1 -1
-1 -1 0 -1 10
-1 -1 20 0 55
-1 -1 -1 -1 0

输出：0 10 45 25 55
```

### 3、[最小生成树](4-3.c)

```
求出所给出图的最小生成树的最小代价。
用例：输入：
0 4 3 -1 7 -1
4 0 1 9 -1 10
3 1 0 8 2 -1
-1 9 8 0 12 5
7 -1 2 12 0 13
-1 10 -1 5 13 0

输出：19
```

## 五、排序作业

### 1、[希尔排序](5-1.c)

```
写出给出序列，以希尔排序，gap=3，2，1的排序结果。

用例：:3 35 13 15 20 5 9 14 6 37 59 64
输出：3 14 5 9 20 6 15 35 13 37 59 64
3 6 5 9 13 14 15 35 20 37 59 64
3 5 6 9 13 14 15 20 35 37 59 64
```

### 2、[2-路归并排序](5-2.c)

```
写出给出序列的2路归并排序每趟的结果。

用例：输入：3 35 13 15 20 5 9 14 6 37 59 64
输出：3 13 35 15 5 20 9 6 14 37 59 64
3 13 35 5 15 20 6 9 14 37 59 64
3 5 13 15 20 35 6 9 14 37 59 64
3 5 6 9 13 14 15 20 35 37 59 64
```

### 3、[快速排序](5-3.c)

```
给出已给序列快速排序的每趟结果。

用例：输入：3 35 13 15 20 5 9 14 6 37 59 64
输出：3 35 13 15 20 5 9 14 6 37 59 64
3 6 13 15 20 5 9 14 35 37 59 64
3 5 6 15 20 13 9 14 35 37 59 64
3 5 6 14 9 13 15 20 35 37 59 64
3 5 6 13 9 14 15 20 35 37 59 64
3 5 6 9 13 14 15 20 35 37 59 64
```

### 4、[基数排序](5-4.c)

```
给出已给序列基数排序得每趟收集结果

用例：输入：3 35 13 15 20 5 9 14 6 37 59 64
输出：20 3 13 14 64 35 15 5 6 37 9 59
3 5 6 9 13 14 15 20 35 37 59 64
```

