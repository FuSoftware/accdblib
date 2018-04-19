#ifndef TABLEPAGE_H
#define TABLEPAGE_H

#include <vector>

namespace ACCDB
{
class File;

class TableDefinition
{
public:
    TableDefinition(std::vector<unsigned char> data, File* parent);
private:
    unsigned long int tbldef_length; //0x0 -> 4 : Total length of the tbldef
    unsigned long int u1; //4 -> 4
    unsigned long int nrows; //8 -> 4 : Number of rows in the table
    unsigned long int autonum; //12 -> 4 : Next value for AutoNumber
    unsigned long int autonum_inc; //16 -> 4 : Increment value of the Autonumber (probably)
    unsigned long int autonum_complex; //20 -> 4 : Complex Autonumber
    unsigned long int u2; //24 -> 4 : Unknown
    unsigned long int u3; //28 -> 4 : Unknown
    unsigned char type; //32 -> 1 : 0x4E User Table, 0x53 System Table
    unsigned short int next_col_id; //36 -> 2 : Incremented with each added column (never decremented)
    unsigned short int n_var_col; //38 -> 2 : Number of variable length columns
    unsigned short int n_col; //40 -> 2 : Number of columns
    unsigned long int  n_index; //42 -> 4 : Number of indexes
    unsigned long int n_real_index; //46 -> 4 : Number of real indices
    unsigned long int row_page_map; //50 -> 4 : A record pointer to a page bitmap of all pages that contain rows in this table (excluding LVAL pages)
    unsigned long int free_space_page_map; //54 -> 4 : A record pointer to a page bitmap for pages containing free space (for inserting rows).

}
}
