#pragma once

#include <string_view>
#include <stdint.h>
#include <optional>

#include <span/source_map.h>

#include "token.h"

namespace lexer {

class Lexer {
private:
	span::source_map::SourceFile source;
	std::shared_ptr<std::string> content;

	size_t offset;

	std::optional<char> bump();
	std::optional<char> peek();

	char next();
	bool next_is(char ch);

	void skip_whitespace();

	void read_ident();

	token::TokenKind read_number();

public:
	Lexer(span::source_map::SourceFile source);

	token::Token next_token();
};

} // namespace lexer
