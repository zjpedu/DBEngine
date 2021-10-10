## DBDemo

Implementing the `select ... from ... where ...` clause.

### Install Dependencies

It dependents glog, gflags, gtest. As follows:

```shell
yum install glog glog-devel
yum install gflags gflags-devel
yum install gtest gtest-devel
```

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

* Page Size (512 Bytes) = Header (32 Bytes) + Entry_Size (16 Bytes) * Entry_Num (30)

### Multi-Threads Implementation

* It uses `atomic_flag` to implement the `spin lock`, which is the best performance. Because the  `atomic_flag` is lock-free.
* The `PAGE_SIZE` is greater than 64 beacuse of memory align.

### Experiments

To Do ...

