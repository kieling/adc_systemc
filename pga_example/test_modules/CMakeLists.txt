add_executable( test_bench

main.cpp
 
)


target_link_libraries(test_bench ${SYSTEMC_LIBRARIES} ${SYSTEMCAMS_LIBRARIES})
