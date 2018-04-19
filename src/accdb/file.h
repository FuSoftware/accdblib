#ifndef FILE_H
#define FILE_H

#include <vector>
#include <string>

//https://github.com/brianb/mdbtools/blob/master/HACKING

namespace ACCDB
{

class Page;

class File
{
public:
    File(std::string path);
    File(std::vector<unsigned char> *data);
    void load(std::vector<unsigned char> *data);
    std::vector<unsigned char> *extractPage(int id);

    unsigned int getSize();
    std::vector<unsigned char> *getData();

    unsigned int getPageCount();
    Page* getPage(int id);
    std::vector<Page*> getPages();

private:
    std::vector<unsigned char> *data;
    std::vector<Page*> pages;
};

}


#endif // FILE_H
