#include "format.h"

std::ostream &operator<<(std::ostream &o, const lexer::token::TokenKind &kind) {
	using enum lexer::token::TokenKind;
	switch (kind) {
	case Illegal:
		return o << "Illegal";
	case Eof:
		return o << "Eof";

	// Literals
	case Ident:
		return o << "Ident";
	case Float:
		return o << "Float";
	case Integer:
		return o << "Int";
	case Str:
		return o << "Str";

	// Operators
	case Eq:
		return o << "Eq";
	case Lt:
		return o << "Lt";
	case Le:
		return o << "Le";
	case EqEq:
		return o << "EqEq";
	case Ne:
		return o << "Ne";
	case Ge:
		return o << "Ge";
	case Gt:
		return o << "Gt";
	case AndAnd:
		return o << "AndAnd";
	case OrOr:
		return o << "OrOr";
	case Not:
		return o << "Not";

	case Plus:
		return o << "Plus";
	case Minus:
		return o << "Minus";
	case Star:
		return o << "Star";
	case Slash:
		return o << "Slash";
	case Percent:
		return o << "Percent";
	case Caret:
		return o << "Caret";
	case And:
		return o << "And";
	case Or:
		return o << "Or";
	case Shl:
		return o << "Shl";
	case Shr:
		return o << "Shr";

	case PlusEq:
		return o << "PlusEq";
	case MinusEq:
		return o << "MinusEq";
	case StarEq:
		return o << "StarEq";
	case SlashEq:
		return o << "SlashEq";
	case PercentEq:
		return o << "PercentEq";
	case CaretEq:
		return o << "CaretEq";
	case AndEq:
		return o << "AndEq";
	case OrEq:
		return o << "OrEq";
	case ShlEq:
		return o << "ShlEq";
	case ShrEq:
		return o << "ShrEq";

	// Puntuation
	case Dot:
		return o << "Dot";
	case Comma:
		return o << "Comma";
	case Semi:
		return o << "Semi";
	case Colon:
		return o << "Colon";
	case ModSep:
		return o << "ModSep";
	case RArrow:
		return o << "RArrow";

	// Delimiters
	case LParenthesis:
		return o << "LParenthesis";
	case LBrace:
		return o << "LBrace";
	case LBracket:
		return o << "LBracket";

	case RParenthesis:
		return o << "RParenthesis";
	case RBrace:
		return o << "RBrace";
	case RBracket:
		return o << "RBracket";

	default:
		return o << "Invalid TokenKind: " << static_cast<int>(kind);
	}
}

std::ostream &operator<<(std::ostream &o, const lexer::token::Token &token) {
	return o << "Token { kind: " << token.kind << ", literal: " << token.literal
			 << ", span: " << token.span << " }";
}

std::ostream &operator<<(std::ostream &o, const span::Span &span) {
	return o << "Span { lo: " << span.lo << ", hi: " << span.hi << " }";
}