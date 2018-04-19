#include "file.h"
#include "utils.h"

#include "page.h"
#include "headerpage.h"
#include "tablepage.h"
#include "datapage.h"

#include <iostream>

ACCDB::File::File(std::string path)
{
    this->load(readFile(path));
}


ACCDB::File::File(std::vector<unsigned char> *data)
{
    this->load(data);
}

void ACCDB::File::load(std::vector<unsigned char> *data)
{
    this->data = data;

    if(this->data->size() % Page::PAGE_SIZE == 0)
    {
        int n = this->data->size() / Page::PAGE_SIZE;


        this->pages.resize(n);
        this->pages[0] = new HeaderPage(0,this);

        for(int i=1;i<n;i++)
        {
            int type = Page::extractType(this->data, i);

            Page *p = 0;

            switch(type)
            {
            case 0x0100: //First Page
                p = new HeaderPage(i, this);
                break;
            case 0x0101: //Data Page
                p = new DataPage(i, this);
                break;
            case 0x0102: //Table Def Page
                p = new TablePage(i, this);
                break;
            case 0x0000: //Unknown
            case 0x0201: //Unknown
            case 0x0401: //Unknown
            case 0x0501: //Unknown
            case 0x0801: //Unknown
            case 0x0901: //Unknown
                p = new Page(i, this);
                break;
            default:
                std::cout << type << std::endl;
                p = new Page(i, this);

            }

            this->pages[i] = p;
        }
    }
    else
    {
        std::cerr << "Error while loading file, size isn't a multiple of " << Page::PAGE_SIZE << " (File = " << getSize()<< " bytes)" << std::endl;
    }

    this->data = data;
}

std::vector<unsigned char> *ACCDB::File::extractPage(int id)
{
    std::vector<unsigned char> *data = split(this->data, id * 4096, 4096, false);
    return data;
}

unsigned int ACCDB::File::getSize()
{
    return this->getData()->size();
}

std::vector<unsigned char> *ACCDB::File::getData()
{
    return this->data;
}

unsigned int ACCDB::File::getPageCount()
{
    return this->getPages().size();
}

ACCDB::Page* ACCDB::File::getPage(int id)
{
    return this->getPages()[id];
}

std::vector<ACCDB::Page*> ACCDB::File::getPages()
{
    return this->pages;
}
