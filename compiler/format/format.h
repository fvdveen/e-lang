#pragma once

#include <ostream>

#include <span/span.h>
#include <lexer/token.h>

std::ostream &operator<<(std::ostream &o, const lexer::token::TokenKind &kind);

std::ostream &operator<<(std::ostream &o, const lexer::token::Token &token);

std::ostream &operator<<(std::ostream &o, const span::Span &span);