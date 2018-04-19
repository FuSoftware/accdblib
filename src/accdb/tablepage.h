#ifndef TABLEPAGE_H
#define TABLEPAGE_H

#include <vector>

#include "page.h"
//http://jabakobob.net/mdb/table-page.html

namespace ACCDB
{

class File;

class TablePage : public Page
{
public:
    TablePage(std::vector<unsigned char> data, File* file = 0);
    TablePage(int id, File* file = 0);

    void load();

    int getNextPage();

private:
    unsigned int free_bytes; //0x02 -> 2 : Free bytes in the page
    unsigned int next_page; //0x04 -> 4 : If this page is too small, contains the index of the following definition (needs concatenation)
};


}

#endif
