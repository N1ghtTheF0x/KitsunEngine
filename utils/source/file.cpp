#include <Utils.hpp>

#include <filesystem>

namespace KitsunEngine
{
    namespace Utils
    {
        File::File(const char* pat,std::ios_base::openmode mode): logger("File"), path(pat)
        {
            stream.open(path,mode);
        }
        File::File(std::string pat,std::ios_base::openmode mode): logger("File"), path(pat)
        {
            stream.open(path,mode);
        }
        File::File(std::stringstream pat,std::ios_base::openmode mode): logger("File"), path(pat.str())
        {
            stream.open(path,mode);
        }
        File::~File()
        {
            stream.close();
        }
        bool File::canRead()
        {
            auto perms = std::filesystem::status(path).permissions();
            return ((perms & std::filesystem::perms::owner_read) != std::filesystem::perms::none) && 
                   ((perms & std::filesystem::perms::group_read) != std::filesystem::perms::none) &&
                   ((perms & std::filesystem::perms::others_read) != std::filesystem::perms::none);
        }
        bool File::canWrite()
        {
            auto perms = std::filesystem::status(path).permissions();
            return ((perms & std::filesystem::perms::owner_write) != std::filesystem::perms::none) && 
                   ((perms & std::filesystem::perms::group_write) != std::filesystem::perms::none) &&
                   ((perms & std::filesystem::perms::others_write) != std::filesystem::perms::none);
        }
        void File::close()
        {
            stream.close();
        }
        size_t File::read(char* buffer,size_t size)
        {
            return stream.readsome(buffer,size);
        }
        void File::write(const char* buffer,size_t size)
        {
            stream.write(buffer,size);
        }
        size_t File::getWriteOffset()
        {
            return stream.tellp();
        }
        void File::setWriteOffset(size_t pos)
        {
            stream.seekp(pos);
        }
        size_t File::getReadOffset()
        {
            return stream.tellg();
        }
        void File::setReadOffset(size_t pos)
        {
            stream.seekg(pos);
        }
        const char* File::getCWD()
        {
            static auto path = std::filesystem::current_path().string();
            return path.c_str();
        }
        size_t File::size()
        {
            return std::filesystem::file_size(path);
        }
    }
}