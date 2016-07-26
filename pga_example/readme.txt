  
Follow the following command to execute a test_modules example:

run test_bench located in pga_example/bin using the command: 

./test_bench 

After execution two tabular files will appear amp.dat and offset.dat. These files can be opened by any of text editor programs.

The amp.dat shows the value of input signal amplified with 10 (gain of the amplifier is set to 10)

The offset.dat shows the value of input signal plus offset (offset=4)


Note:

In the above example the type of signal value is specified as integer.

IN YOUR PROJECT YOU SHOULD USE DOUBLE TYPE.

Since the amplifier and offset modules are implemented as generic template classes, this should not be a problem.


Also, stimuli module should be changed so that the input signals are analog signals with following shapes:

1. sine signal
2. triangle signal
3. saw signal

(See specifications for exercise 2)


