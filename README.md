## DBDemo

Implementing the `select ... from ... where ...` clause.

### Install Dependencies


In centos 7, it dependents glog, gflags, gtest. As follows:

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

```shell
cd multi_thread
make
./task
```

示例输入：
```shell
# main thread
Row rows[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};

// other threads
Row rows1[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
Row rows2[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
Row rows3[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
```

过滤条件：

```shell
b >= =10 && b <= 50 && a == 1000 || a == 2000 || a == 3000
```

示例输出：
```shell
2000 16
2000 16
2000 16
2000 16
1000 20
1000 20
1000 20
1000 20
1000 31
2000 31
1000 31
2000 31
1000 31
2000 31
2000 31
1000 31
```

### To Do

* Performance experiments on big data.
    * time and space 
* Unit tests and Integration Testing using the `gtest` tool.


