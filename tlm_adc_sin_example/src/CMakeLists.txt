ADD_EXECUTABLE(sin_tlm_ams
                            main.cpp
                            tuv_ams_library.cpp
                            )
                    
target_link_libraries(sin_tlm_ams
                    	${SYSTEMC_LIBRARIES}
                   	${SYSTEMCAMS_LIBRARIES}		
                     )
