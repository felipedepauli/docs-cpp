#include <iostream>
#include <cstdarg>

namespace operators {
    int wow() {
        return 11;
    }

    double average (int count, ...) {
        va_list list;
        double sum = 0;

        // va_start(list, count); - initialize list for num number of arguments
        // va_arg(list, int) - access next argument in list. The width is int
        // va_end(list) - clean up the list

        va_start(list, count);
        for (int i = 0; i < count; i++) {
            sum += static_cast<double>(va_arg(list, int));
        }
        va_end(list);

        return sum / count;
    }
}
