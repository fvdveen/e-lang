#pragma once

#include <ostream>
#include <span/span.h>
#include <string>

namespace lexer::token {

enum class TokenKind {
	Illegal,
	Eof,

	// Literals
	Ident,
	Float,
	Integer,
	Str,

	// Operators
	Eq,
	Lt,
	Le,
	EqEq,
	Ne,
	Ge,
	Gt,
	AndAnd,
	OrOr,
	Not,

	Plus,
	Minus,
	Star,
	Slash,
	Percent,
	Caret,
	And,
	Or,
	Shl,
	Shr,

	PlusEq,
	MinusEq,
	StarEq,
	SlashEq,
	PercentEq,
	CaretEq,
	AndEq,
	OrEq,
	ShlEq,
	ShrEq,

	// Puntuation
	Dot,
	Comma,
	Semi,
	Colon,
	ModSep,
	RArrow,

	// Delimiters
	LParenthesis,
	LBrace,
	LBracket,

	RParenthesis,
	RBrace,
	RBracket,
};

struct Token {
	TokenKind kind;

	std::string literal;

	span::Span span;
};

} // namespace lexer::token
