#ifndef DATAPAGE_H
#define DATAPAGE_H

#include "page.h"
#include <vector>

namespace ACCDB
{

class File;
class DataPage : public Page
{
public:
    DataPage(int id, File *file = 0);
    void load();

private:
};

}


#endif // DATAPAGE_H
