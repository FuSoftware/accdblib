#ifndef PAGE_H
#define PAGE_H

#include <vector>
#include <string>

namespace ACCDB
{
class File;

class Page{
public:
    Page(int id, File* parent);

    virtual void load();

    unsigned short getType();
    unsigned int getOffset(unsigned int offset = 0);
    std::vector<unsigned char> *getFileData();

    unsigned long getULong(int offset, bool reverse = true);
    unsigned short getUShort(int offset, bool reverse = true);
    std::string getString(int offset, int length);

    static const int PAGE_SIZE = 4096;
    static unsigned short extractType(std::vector<unsigned char> *data, int id);

protected:
    unsigned int page_offset = 0;
    unsigned short page_signature; //2 bytes, identifies the page type
    std::vector<unsigned char>::const_iterator d_it;
    File* parent;
};
}

#endif
