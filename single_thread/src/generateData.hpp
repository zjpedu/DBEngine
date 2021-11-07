#include <iostream>
#include <cstdio>
using namespace std;

FILE *openFile(char *fileName, char *mode) {
    FILE *fp = fopen(fileName, mode);
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void generateData(int num_ways, int run_size){
    char input_file[] = "input.txt";

    FILE *in = openFile(input_file, "w");

    srand(unsigned(time(NULL)));

    // https://www.runoob.com/w3cnote/cpp-rand-srand.html
    // 生成两个数字，第一个数的范围是 [1000, 5000]，第二个数的范围是 [20, 100]
    for (int i = 0; i < num_ways * run_size; i++)
        fprintf(in, "%d,%d\n", (rand() % (5000-1000+1) + 1000), (rand() % (100-20+1) + 20));
    fclose(in);
}

/**
int main(){
    generateData();
    return 0;
}
*/
