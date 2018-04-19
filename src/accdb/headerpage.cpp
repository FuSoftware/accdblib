#include "headerpage.h"
#include "utils.h"
#include "file.h"


ACCDB::HeaderPage::HeaderPage(int id, File *file) : Page(id,file)
{
    this->load();
}

void ACCDB::HeaderPage::load()
{
    this->magic_number = this->getULong(0);
    this->format_id = this->getString(4,16);
    this->version = this->getULong(20);
    this->enc_db_info = this->getString(24,128);
}

std::string ACCDB::HeaderPage::getFormat()
{
    return this->format_id;
}
