#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <cmocka.h>
#include "shifr.h"


static void test_clean_key(void **state) {
    char key[] = "BANANA";
    char *result = CleanKey(key);
    
    assert_string_equal(result, "BAN");
    free(result);
}


static void test_sort_key(void **state) {
    char key[] = "BA";
    int poryadok[2] = {-1, -1};
    
    SortKey(key, poryadok, 2);
    
    assert_int_equal(poryadok[0], 1); 
    assert_int_equal(poryadok[1], 0); 
}


static void test_perestanovka(void **state) {
    char text[] = "HELLO";
    char key[] = "BA";
    int poryadok[2] = {1, 0}; 
    
    char *encrypted = Perestanovka(text, key, poryadok);
    
    assert_non_null(encrypted); 
    free(encrypted);
}


static void test_de_perestanovka(void **state) {
    char encrypted_text[] = "ELHL_O";
    char key[] = "BA";
    int poryadok[2] = {1, 0};
    
    char *decrypted = DePerestanovka(encrypted_text, key, poryadok);
    
    assert_non_null(decrypted);
    free(decrypted);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_clean_key),
        cmocka_unit_test(test_sort_key),
        cmocka_unit_test(test_perestanovka),
        cmocka_unit_test(test_de_perestanovka),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
