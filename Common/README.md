## Library containing routines that currently can be called in Python and C/C++.

This folder contains the C++ header and source files, a shared library and object files for the parallel video extraction library. Examples of code snippets for calling the routines in the library are provided below.

#### An example code snippet in Python
The code can be found in '''TestStubs/run_4_parallel_video_extraction.py'''.

'''
import ctypes  
from ctypes import *  
lib = cdll.LoadLibrary('../Common/Release/libCommon.so')  

def __init__(self):  
    self.obj = lib.vidl_new()  // initialise an instance of the library.

.... // some code here
    
lib.vidl_run_on_4_processors(self.obj, create_string_buffer(b_in_dir), create_string_buffer(b_out_dir))  // function takes a pointer to an instance of the library, a string containing the input directory, a string containing the output directory if any.
'''
