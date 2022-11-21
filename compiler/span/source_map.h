#pragma once

#include <string>
#include <memory>
#include <filesystem>
#include <string_view>
#include <unordered_map>
#include <expected>

#include <error/io.h>

namespace span::source_map {

class SourceFile {
private:
    std::filesystem::path file_path;
    std::shared_ptr<std::string> content;

    friend class SourceMap;

    SourceFile(std::filesystem::path path, std::string content);

public:
    std::shared_ptr<std::string> get_content();
};

class SourceMap {
private:
	std::unordered_map<std::filesystem::path, SourceFile> files;

public:
    std::expected<SourceFile, error::io::Error> load_file(std::filesystem::path path);
};

}