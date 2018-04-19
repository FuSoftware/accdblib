#ifndef HEADERPAGE_H
#define HEADERPAGE_H

#include <vector>
#include <string>

#include "page.h"

//http://jabakobob.net/mdb/first-page.html

namespace ACCDB
{
class File;

class HeaderPage : public Page
{
public:
    HeaderPage(std::vector<unsigned char> data, File *file = 0);
    HeaderPage(int id, File *file = 0);
    void load();

    std::string getFormat();

private:
    unsigned long magic_number; // 0+4 = 0x100
    std::string format_id; //0x04 + 16 = String identifying the file format
    unsigned long version; //0x14 + 4 = Jet file format version
    std::string enc_db_info; //0x18 + 126/128
};

}


#endif // HEADER_H
