## DBDemo

### Single Thread Implementation

```shell
cd single_thread
make
./task
```

示例输入：

```shell
{{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}}
```

过滤条件：

```shell
b >= =10 && b <= 50 && a == 1000 || a == 2000 || a == 3000
```

示例输出：

```shell
2000 16
1000 20
1000 31
2000 31
```

### B+ Tree Implementation

Page Size (512 Bytes) = Header (32 Bytes) + Entry_Size (16 Bytes) * Entry_Num (30)

### Lock-free Multi-Thread Implementation

To Do ...
