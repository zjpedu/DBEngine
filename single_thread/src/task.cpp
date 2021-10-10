#include "btree.hpp"
#include <glog/logging.h>  // yum install glog glog-devel
#include <gflags/gflags.h> // yum install gflags gflags-devel

static const int START_INDEX = 10;
static const int END_INDEX = 51;

typedef struct Row
{
    int a;
    int b;
} Row;

void task(Row *rows, int nrows)
{
    // construct b plus tree index
    btree *bt = new btree();
    for (int i = 0; i < nrows; i++)
    {
        bt->btree_insert(rows[i].b, (char *)&rows[i]);
    }
    
    // printf("%d\n", (*(Row*)bt->btree_search(16)).a); // point query
    // printf("%x\n", bt->btree_search(16)); point query
    unsigned long *bufs = new unsigned long[nrows]{};
    int offset = 0;
    bt->btree_search_range(START_INDEX, END_INDEX, bufs, offset);
    for (int i = 0; i < offset; i++)
    {
        auto tmp = (*(Row *)(char *)bufs[i]);
        if (1000 == tmp.a || 2000 == tmp.a || 3000 == tmp.a)
            printf("%d %d\n", tmp.a, tmp.b);
    }
    delete[] bufs;
    delete bt;
}

int main(int argc, char *argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_colorlogtostderr=true;  //set output color
    FLAGS_log_dir = "./logs";  // create the directory by myself
    LOG(INFO) << "The main started!" << endl;
    
    Row rows[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
    int len = sizeof(rows) / sizeof(rows[0]);
    task(rows, len);
    return 0;
}
