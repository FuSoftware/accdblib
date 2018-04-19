#include "page.h"
#include "file.h"
#include "utils.h"

ACCDB::Page::Page(int id, File *parent)
{
    this->parent = parent;
    this->page_offset = id * Page::PAGE_SIZE;
    this->page_signature = this->getUShort(0);
}

void ACCDB::Page::load()
{

}

unsigned short ACCDB::Page::getType()
{
    return this->page_signature;
}

unsigned short ACCDB::Page::extractType(std::vector<unsigned char> *data, int id)
{
    return toUShort(data, true, id * Page::PAGE_SIZE);
}

unsigned int ACCDB::Page::getOffset(unsigned int offset)
{
    return this->page_offset + offset;
}

std::vector<unsigned char> *ACCDB::Page::getFileData()
{
    return this->parent->getData();
}

unsigned long ACCDB::Page::getULong(int offset, bool reverse)
{
    return toULong(this->getFileData(), reverse, getOffset(offset));
}

unsigned short ACCDB::Page::getUShort(int offset, bool reverse)
{
    return toUShort(this->getFileData(), reverse, getOffset(offset));
}

std::string ACCDB::Page::getString(int offset, int length)
{
    return toString(this->getFileData(), offset, length);
}

