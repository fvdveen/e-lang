#include "span.h"

#include <iostream>

namespace span {

void print_span(Span span)
{
    std::cout << "Span{ lo: " << span.lo << ", hi: " << span.hi << " }" << std::endl;
}

}