#ifndef WAV2_SPECTROGRAM_MMFILE_H
#define WAV2_SPECTROGRAM_MMFILE_H

#include <string>
#include <string_view>
#include <stdexcept>
#include <exception>
#include <iostream>

// Такой врапер кстати можно расширить
// на функциональность для работы между
// потоками и процессами

namespace mmf {
    class MMFile {
    public:
        MMFile() : m_fd(0), m_fileSize(0), m_filePtr(nullptr) {}

        explicit MMFile(const std::string &fileName);

        ~MMFile();

        std::string_view& GetView();

    private:
        int m_fd;
        size_t m_fileSize;
        char *m_filePtr;
        std::string_view m_view;
    };

    namespace exceptions {

    }
}

#endif //WAV2_SPECTROGRAM_MMFILE_H
