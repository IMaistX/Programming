#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "calculator.h"


static void test_add(void **state) {
    (void)state;
    
    assert_int_equal(add(2, 3), 5);
    assert_int_equal(add(-1, 1), 0);
    assert_int_equal(add(0, 0), 0);
    assert_int_equal(add(-5, -3), -7);
    assert_int_equal(add(100, 200), 300);
}


static void test_subtract(void **state) {
    (void)state;
    
    assert_int_equal(subtract(5, 3), 2);
    assert_int_equal(subtract(0, 5), -5);
    assert_int_equal(subtract(-2, -3), 1);
    assert_int_equal(subtract(100, 50), 50);
}


static void test_multiply(void **state) {
    (void)state;
    
    assert_int_equal(multiply(2, 3), 6);
    assert_int_equal(multiply(-2, 3), -6);
    assert_int_equal(multiply(0, 5), 0);
    assert_int_equal(multiply(-4, -5), 20);
}


static void test_divide(void **state) {
    (void)state;
    
    assert_float_equal(divide(10, 2), 5.0, 0.001);
    assert_float_equal(divide(5, 2), 2.5, 0.001);
    assert_float_equal(divide(1, 3), 0.33333, 0.001);
    assert_float_equal(divide(-10, 2), -5.0, 0.001);
    assert_float_equal(divide(5, 0), 0.0, 0.001);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_add),
        cmocka_unit_test(test_subtract),
        cmocka_unit_test(test_multiply),
        cmocka_unit_test(test_divide),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}