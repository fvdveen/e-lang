#include "source_map.h"

#include <cstdio>
#include <cerrno>
#include <cerrno>

namespace span::source_map {

SourceFile::SourceFile(std::filesystem::path path, std::string content)
	: file_path(path), content(std::make_shared<std::string>(content)) {}

std::shared_ptr<std::string> SourceFile::get_content() { return content; }

std::expected<SourceFile, error::io::Error> span::source_map::SourceMap::load_file(std::filesystem::path file_path)
{
    std::FILE* fp = std::fopen(file_path.string().c_str(), "rb");

    if (!fp) {
        return std::unexpected(error::io::Error::from_errno(errno));
    }

    std::string content;
    std::fseek(fp, 0, SEEK_END);
    content.resize(std::ftell(fp));
    std::rewind(fp);
    std::fread(&content[0], 1, content.size(), fp);
    std::fclose(fp);

    return SourceFile(file_path, content);
}

}