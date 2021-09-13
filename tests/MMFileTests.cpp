#include <gtest/gtest.h>
#include <string_view>

#include "MMFile.h"

#define TEST_FILE1_PATH "../tests/test_files/mmfile_test_file1"
#define TEST_FILE2_PATH "../tests/test_files/mmfile_test_file2"
#define TEST_EMPTY_PATH "../tests/test_files/mmfile_test_empty"
#define TEST_BAD_FILE_PATH "some/not/exist/path"

constexpr std::string_view FILE1_TEXT("Some useful information");
constexpr std::string_view FILE2_TEXT("Some information\n"
                                      "in different\n"
                                      "strings\n"
                                      "\n"
                                      "asd");

TEST(MMFileCounstructor, NoExcept) {
    ASSERT_NO_THROW(mmf::MMFile mmfile);
    ASSERT_NO_THROW(mmf::MMFile mmfile(TEST_FILE1_PATH));
}

TEST(MMFileCounstructor, Throw) {
    ASSERT_THROW(mmf::MMFile mmfile(TEST_BAD_FILE_PATH), mmf::except::FileOpenErr);
    ASSERT_THROW(mmf::MMFile mmfile(TEST_EMPTY_PATH), mmf::except::EmptyFile);
}

TEST(MMFileGetData, GetView) {
    {
        mmf::MMFile mmfile(TEST_FILE1_PATH);
        std::string_view view = mmfile.GetView();
        ASSERT_STREQ(&view[0], &FILE1_TEXT[0]);
    }

    {
        mmf::MMFile mmfile(TEST_FILE2_PATH);
        std::string_view view = mmfile.GetView();
        ASSERT_STREQ(&view[0], &FILE2_TEXT[0]);
    }
}