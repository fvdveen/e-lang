#include "lexer.h"

bool is_whitespace(char ch) {
	return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

bool is_ident(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

bool is_numeric(char ch) { return ch >= '0' && ch <= '9'; }

namespace lexer {

std::optional<char> Lexer::bump() {
	if (!(offset < content->size())) {
		return std::nullopt;
	}

	return content->at(offset++);
}

std::optional<char> Lexer::peek() {
	if (!(offset < content->size())) {
		return std::nullopt;
	}

	return content->at(offset);
}

char Lexer::next() {
	if (peek().has_value())
		return peek().value();
	else
		return 0;
}

bool Lexer::next_is(char ch) { return next() == ch; }

void Lexer::skip_whitespace() { while (is_whitespace(next())) {
		bump();
	}
}

void Lexer::read_ident() {
	while (peek().has_value() && is_ident(peek().value())) {
		bump();
	}
}

token::TokenKind Lexer::read_number() {
	while (is_numeric(next())) {
		bump();
	}

	if (next_is('.')) {
		bump();

		while (is_numeric(next())) {
			bump();
		}

		return token::TokenKind::Float;
	} else {
		return token::TokenKind::Integer;
	}
}

Lexer::Lexer(span::source_map::SourceFile source) : source(source), offset(0) {
	content = source.get_content();
}

token::Token Lexer::next_token() {
	using enum token::TokenKind;

	char first_char;

	skip_whitespace();

	size_t start = offset;

	auto maybe_first_char = bump();
	if (!maybe_first_char) {
		return token::Token{
			Eof,
			std::string(),
			span::Span{offset, offset},
		};
	}

	first_char = maybe_first_char.value();

	token::TokenKind kind = Illegal;

	if (is_ident(first_char)) {
		read_ident();
		kind = Ident;
	} else if (is_numeric(first_char)) {
		kind = read_number();
	} else {
		switch (first_char) {
		// Delimiters
		case '(':
			kind = LParenthesis;
			break;
		case ')':
			kind = RParenthesis;
			break;
		case '{':
			kind = LBrace;
			break;
		case '}':
			kind = RBrace;
			break;
		case '[':
			kind = LBracket;
			break;
		case ']':
			kind = RBracket;
			break;

		// Punctuation
		case '.':
			kind = Dot;
			break;
		case ',':
			kind = Comma;
		case ':':
			if (next_is(':')) {
				bump();
				kind = ModSep;
			} else {
				kind = Colon;
			}
			break;

		// Punctuation or operators
		case '-':
			if (next_is('>')) {
				bump();
				kind = RArrow;
			} else if (next_is('=')) {
				bump();
				kind = MinusEq;
			} else {
				kind = Minus;
			}
			break;

		// Operators
		case '=':
			if (next_is('=')) {
				bump();
				kind = EqEq;
			} else {
				kind = Eq;
			}
			break;
		case '!':
			if (next_is('=')) {
				bump();
				kind = Ne;
			} else {
				kind = Not;
			}
			break;
		case '&':
			if (next_is('&')) {
				bump();
				kind = AndAnd;
			} else if (next_is('=')) {
				bump();
				kind = AndEq;
			} else {
				kind = And;
			}
			break;
		case '|':
			if (next_is('|')) {
				bump();
				kind = OrOr;
			} else if (next_is('=')) {
				bump();
				kind = OrEq;
			} else {
				kind = Or;
			}
			break;
		case '<':
			if (next_is('=')) {
				bump();
				kind = Le;
			} else if (next_is('<')) {
				bump();
				if (next_is('=')) {
					bump();
					kind = ShlEq;
				} else {
					kind = Shl;
				}
			} else {
				kind = Lt;
			}
			break;
		case '>':
			if (next_is('=')) {
				bump();
				kind = Ge;
			} else if (next_is('>')) {
				bump();
				if (next_is('=')) {
					bump();
					kind = ShrEq;
				} else {
					kind = Shr;
				}
			} else {
				kind = Gt;
			}
			break;

		case '+':
			if (next_is('=')) {
				bump();
				kind = PlusEq;
			} else {
				kind = Plus;
			}
			break;
		case '*':
			if (next_is('=')) {
				bump();
				kind = StarEq;
			} else {
				kind = Star;
			}
			break;
		case '/':
			if (next_is('=')) {
				bump();
				kind = SlashEq;
			} else {
				kind = Slash;
			}
			break;
		case '%':
			if (next_is('=')) {
				bump();
				kind = PercentEq;
			} else {
				kind = Percent;
			}
			break;
		case '^':
			if (next_is('=')) {
				bump();
				kind = CaretEq;
			} else {
				kind = Caret;
			}
			break;
		default:
			break;
		}
	}

	return token::Token{
		kind,
		content->substr(start, offset - start),
		span::Span(start, offset),
	};
}

} // namespace lexer