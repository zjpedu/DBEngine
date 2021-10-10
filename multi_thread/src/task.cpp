#include "btree.hpp"
#include <glog/logging.h>  // yum install glog glog-devel
#include <gflags/gflags.h> // yum install gflags gflags-devel
#include <thread>

static const int START_INDEX = 10;
static const int END_INDEX = 51;

typedef struct Row
{
    int a;
    int b;
} Row;

btree *bt = new btree();
void insert(Row *rows, int nrows)
{
    // construct b plus tree index
    
    for (int i = 0; i < nrows; i++)
    {
        bt->btree_insert(rows[i].b, (char *)&rows[i]);
    }
}

void search(int nrows, int proc){
    // printf("%d\n", (*(Row*)bt->btree_search(16)).a); // point query
    // printf("%x\n", bt->btree_search(16)); point query
    unsigned long *bufs = new unsigned long[(nrows)*proc + nrows]{};
    int offset = 0;
    bt->btree_search_range(START_INDEX, END_INDEX, bufs, offset);
    cout << "offset: " << offset << endl;
    for (int i = 0; i < offset; i++)
    {
        auto tmp = (*(Row *)(char *)bufs[i]);
        if (1000 == tmp.a || 2000 == tmp.a || 3000 == tmp.a)
            printf("%d %d\n", tmp.a, tmp.b);
    }
    delete[] bufs;
    return;
}

int main(int argc, char *argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_colorlogtostderr=true;  //set output color
    FLAGS_log_dir = "./logs";  // create the directory by myself
    LOG(INFO) << "The main started!" << endl;

    // int proc;
    // proc = sysconf(_SC_NPROCESSORS_ONLN);  // get cpu number
    // cout << "proc: " << proc << endl;
    // LOG_IF(FATAL, proc < 0) << "There is no avaliable cpu!" << endl;

    Row rows[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
    int len = sizeof(rows) / sizeof(rows[0]);
    insert(rows, len);
    cout << "pre-filled end!" << endl;

    // multi-thread
    Row rows1[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
    Row rows2[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
    Row rows3[] = {{1000, 20}, {1000, 31}, {500, 75}, {2000, 31}, {2000, 16}, {4500, 50}};
    vector<std::thread> vthreads(3);
    vthreads[0] = std::thread(insert, rows1, len);
    vthreads[1] = std::thread(insert, rows2, len);
    vthreads[2] = std::thread(insert, rows3, len);

    for(auto & u: vthreads){
        u.join();
    }
    
    search(len, 4);
    delete bt;
    return 0;
}
