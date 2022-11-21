// e-lang.cpp : Defines the entry point for the application.
//

#include "ec.h"

#include <iostream>
#include <filesystem>

#include <span/source_map.h>
#include <lexer/lexer.h>
#include <format/format.h>

int main()
{
    span::source_map::SourceMap source_map;
	error::io::Result<span::source_map::SourceFile> example_res =
		source_map.load_file("examples/main.e");

    if (!example_res) {
        std::cerr << example_res.error().description() << std::endl;
        return -1;
    }

    span::source_map::SourceFile example = example_res.value();

    lexer::Lexer lex = lexer::Lexer(example);

    lexer::token::Token tok;

    do {
		tok = lex.next_token();

        std::cout << tok << std::endl;
	} while (tok.kind != lexer::token::TokenKind::Eof);

    return 0;
}
