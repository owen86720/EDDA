// EDDA.cpp: 定義應用程式的進入點。
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "dataset/DistributionArray.h"
#include "io/load.h"

int main()
{
    // for(int i = 0;i<8;i++){
    //     std::string fileName = "test" + std::to_string(i) + ".edda";
    //     std::cout << fileName << "\n";
    //     LoadAsHistogram(fileName);
    // }
    DataSet ds = LoadAsHistogram("aaa.bin", 500, 500, 100, 250, 250, 50, 3);
    ds.print();
    return 0;
}
