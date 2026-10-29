
#include "aggregation.hpp"

#include <cassert>
#include <stdexcept>
#include <vector>

int main()
{
    NDArray array({2, 3}, {1, 2, 3, 4, 5, 6});

    // Total sum
    assert(aggregation::sum(array) == 21.0);

    // Reduction along axes
    assert((aggregation::sum(array, 0).values()
            == std::vector<double>{5, 7, 9}));

    assert((aggregation::sum(array, 1).values()
            == std::vector<double>{6, 15}));

    // Minimum and maximum
    assert((aggregation::minimum(array, 1).values()
            == std::vector<double>{1, 4}));

    assert((aggregation::maximum(array, 1).values()
            == std::vector<double>{3, 6}));

    // Element-wise addition
    NDArray second({2, 3}, {10, 20, 30, 40, 50, 60});

    assert((aggregation::add(array, second).values()
            == std::vector<double>{11, 22, 33, 44, 55, 66}));

    // Different shapes must not be added
    bool error_caught = false;

    try {
        NDArray different_shape({3, 2}, {1, 2, 3, 4, 5, 6});
        aggregation::add(array, different_shape);
    } catch (const std::invalid_argument&) {
        error_caught = true;
    }

    assert(error_caught);

    // Invalid axis must be rejected
    error_caught = false;

    try {
        aggregation::sum(array, 2);
    } catch (const std::invalid_argument&) {
        error_caught = true;
    }

    assert(error_caught);

    return 0;
}
