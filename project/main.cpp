#include <string>
#include <iostream>

#include "MMFile.h"

#define FILE_PATH "../tmp/test_file"

int main() {
    mmf::MMFile file_wrapper(FILE_PATH);
    std::string_view view = file_wrapper.GetView();
    std::cout << view << std::endl;

    return 0;
}