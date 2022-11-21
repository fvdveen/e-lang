#pragma once

namespace span {

struct Span {
    size_t lo, hi;
};

void print_span(Span span);

}

