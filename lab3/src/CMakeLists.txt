ADD_EXECUTABLE(adc_systemc
                  main.cpp
                  )

target_link_libraries(adc_systemc
                    	${SYSTEMC_LIBRARIES}
                   		${SYSTEMCAMS_LIBRARIES}
                     )
