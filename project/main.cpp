#include <string>
#include <iostream>

#include "MMFile.h"

#define FILE_PATH "../tests/test_files/mmfile_test_file1"

int main() {
    mmf::MMFile file_wrapper(FILE_PATH);
    std::string_view view = file_wrapper.GetView();
    std::cout << view << std::endl;

    return 0;
}