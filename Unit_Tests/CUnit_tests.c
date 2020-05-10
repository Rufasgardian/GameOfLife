#include "CUnit_tests.h"


int main(int argc, char const *argv[]){
    
    // initiliazing CU
    if(CUE_SUCCESS != CU_initialize_registry()){
        return CU_get_error();
    }

    // create arena test suite
    CU_pSuite pSCreateArena = CU_add_suite("Test create arena", NULL, NULL);
    CU_ADD_TEST(pSCreateArena, test_create_arena);
    CU_ADD_TEST(pSCreateArena, test_create_arena_2);
    

    // add live cell test suite
    CU_pSuite pSAddLiveCell = CU_add_suite("Test adding live cell", NULL, NULL);
    CU_ADD_TEST(pSAddLiveCell, test_add_live_cells);


    // add dead cell test suite
    CU_pSuite pSAddDeadCell = CU_add_suite("Test adding dead cell", NULL, NULL);
    CU_ADD_TEST(pSAddDeadCell, test_add_dead_cells);

    // clipped test suite
    CU_pSuite pSClipped = CU_add_suite("Test clipped version", NULL, NULL);
    CU_ADD_TEST(pSClipped, test_clipped);
    CU_ADD_TEST(pSClipped, test_clipped_2);

    // circular test suite
    CU_pSuite pSCircular = CU_add_suite("Test circular version", NULL, NULL);
    CU_ADD_TEST(pSCircular, test_circular);
    CU_ADD_TEST(pSCircular, test_circular_2);

    // basic set mode and running tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    return 0;
}



// test #1 for create area function
void test_create_arena(void){

    int expected[5][5];

    int **actual = create_area(5, 5);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            expected[i][j] = 0;
        }
    }

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            CU_ASSERT_EQUAL(actual[i][j], expected[i][j]); // checking equality
        }
    }
}


// test #2 for create area function
void test_create_arena_2(void){

    // make sure row or column is not equal to 0
    CU_ASSERT_FALSE(create_area(1, 0));
    CU_ASSERT_FALSE(create_area(0, 1));
    CU_ASSERT_FALSE(create_area(0, 0));

    // make sure row or column is not less than 0
    CU_ASSERT_FALSE(create_area(-1, 0));
    CU_ASSERT_FALSE(create_area(0, -1));
    CU_ASSERT_FALSE(create_area(-1, -1));
    CU_ASSERT_FALSE(create_area(-1, 1));
    CU_ASSERT_FALSE(create_area(1, -1));

}


// test #1 for add live cells function
void test_add_live_cells(void){

    int **area = create_area(5, 5);

    add_live_cells(area, 3, 3);

    int actual = area[3][3]; // live cell must be equal to 1


    int expected = 1;

    CU_ASSERT_TRUE(actual == expected);
    CU_ASSERT_EQUAL(actual, expected);
    CU_ASSERT_FALSE(actual < 1);
    CU_ASSERT_FALSE(actual > 1);
    CU_ASSERT_FALSE(actual != expected);
}


// test #1 for add dead cells function
void test_add_dead_cells(void){

    int **area = create_area(5, 5);

    add_dead_cells(area, 3, 2);

    int actual = area[3][2]; // dead cell must be equal to 1

    int expected = 0;

    CU_ASSERT_TRUE(actual == expected);
    CU_ASSERT_EQUAL(actual, expected);
    CU_ASSERT_FALSE(actual > 1);
    CU_ASSERT_FALSE(actual < -1);
    CU_ASSERT_FALSE(actual != expected);
    
}

// test #1 for clipped logic
void test_clipped(void){

    // arena which our function returns
    int **actual_arena = create_area(5, 5);

    add_live_cells(actual_arena, 2, 1);
    add_live_cells(actual_arena, 2, 2);
    add_live_cells(actual_arena, 2, 3);

    actual_arena = clipped(actual_arena,5, 5);


    // arena which must be returned
    int **expected_arena = create_area(5, 5);

    add_live_cells(expected_arena, 1, 2);
    add_live_cells(expected_arena, 2, 2);
    add_live_cells(expected_arena, 3, 2);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            CU_ASSERT_EQUAL(actual_arena[i][j], expected_arena[i][j]); // checking equality
        }
    }
}


// test #2 for clipped logic
void test_clipped_2(void){

    // arena which our function returns
    int **actual_arena = create_area(5, 5);

    add_live_cells(actual_arena, 1, 0);
    add_live_cells(actual_arena, 1, 1);
    add_live_cells(actual_arena, 1, 3);

    actual_arena = clipped(actual_arena,5, 5);

    // arena which must be returned
    int **expected_arena = create_area(5, 5);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            CU_ASSERT_EQUAL(actual_arena[i][j], expected_arena[i][j]); // checking equality
        }
    }
}


// test #1 for circular logic
void test_circular(void){

    // arena which our function returns
    int **actual_arena = create_area(4, 5);

    add_live_cells(actual_arena, 3, 2);
    add_live_cells(actual_arena, 3, 3);
    add_live_cells(actual_arena, 3, 4);

    actual_arena = circular(actual_arena, 4, 5);


    // arena which must be returned
    int **expected_arena = create_area(4, 5);

    add_live_cells(expected_arena, 0, 3);
    add_live_cells(expected_arena, 2, 3);
    add_live_cells(expected_arena, 3, 3);

    for(int i=0; i < 4; i++){
        for(int j=0; j < 5; j++){
            CU_ASSERT_EQUAL(actual_arena[i][j], expected_arena[i][j]); // checking equality
        }
    }
}

// test #2 for circular logic
void test_circular_2(void){

    // arena which our function returns
    int **actual_arena = create_area(4, 5);

    add_live_cells(actual_arena, 0, 4);
    add_live_cells(actual_arena, 1, 4);
    add_live_cells(actual_arena, 3, 4);

    actual_arena = circular(actual_arena, 4, 5);

    // arena which must be returned
    int **expected_arena = create_area(4, 5);
    add_live_cells(expected_arena, 0, 0);
    add_live_cells(expected_arena, 0, 3);
    add_live_cells(expected_arena, 0, 4);

    for(int i=0; i < 4; i++){
        for(int j=0; j < 5; j++){
            CU_ASSERT_EQUAL(actual_arena[i][j], expected_arena[i][j]); // checking equality
        }
    }
}