#include <iostream>
#include "column.h"
#include "dataframe.h"

int main(int argc, char** argv) {

    FloatColumn* fc = new FloatColumn();
    std::cout << fc->is_float_column();
    Column* c = dynamic_cast<Column*>(fc);
    std::cout << c->is_float_column();
    return 0;
}