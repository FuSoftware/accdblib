#include "tablepage.h"
#include "page.h"
#include "utils.h"
#include "file.h"


ACCDB::TablePage::TablePage(int id, File* file) : Page(id, file)
{

}

void ACCDB::TablePage::load()
{
    this->free_bytes = this->getUShort(2);
    this->next_page = this->getULong(4);
}

int ACCDB::TablePage::getNextPage()
{
    return this->next_page;
}
