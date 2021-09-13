#include "MMFile.h"

#include <string>
#include <exception>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

namespace mmf {
    MMFile::MMFile(const std::string &fileName) {
        if ((m_fd = open(fileName.c_str(), O_RDONLY, 0)) < 0) {
            throw except::FileOpenErr();
        }

        struct stat tmp_stat = {};
        if (fstat(m_fd, &tmp_stat) < 0) {
            close(m_fd);
            throw except::MemoryMapError();
        }

        if (tmp_stat.st_size == 0) {
            throw mmf::except::EmptyFile();
        }

        m_fileSize = tmp_stat.st_size;
        m_filePtr = (char *) mmap(nullptr, m_fileSize, PROT_READ, MAP_PRIVATE, m_fd, 0);
        if (m_filePtr == MAP_FAILED) {
            close(m_fd);
            throw except::MemoryMapError();
        }

        m_view = {m_filePtr, m_fileSize};
    }

    MMFile::~MMFile() {
        munmap(m_filePtr, m_fileSize);
        close(m_fd);
    }

}