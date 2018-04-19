#include <iostream>

#include "accdb/headerpage.h"
#include "accdb/utils.h"
#include "accdb/file.h"

#include <chrono>


void testFile(std::string path)
{
    auto start = std::chrono::system_clock::now();

    ACCDB::File *f = new ACCDB::File(path);

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);;

    std::cout << "File size : " << f->getSize() << std::endl;
    std::cout << "Pages : " << f->getPageCount() << std::endl;
    std::cout << "Processed in : " << elapsed.count() << "ms" << std::endl;
    getchar();
}

int main()
{
    testFile("E:\\Prog\\Data\\Pieces.accdb");
    //testFile("E:\\Prog\\Data\\Miracle Fly.accdb");
    return 0;
}
