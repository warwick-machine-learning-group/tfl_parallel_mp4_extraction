## Test stubs

This folder contains the C++ header and source files, a C++ executable and Python scripts for executing the video extraction library.  Examples of code snippets for calling the routines in the library are provided below.

### A code snippet in Python
The complete code can be found in ```run_4_parallel_video_extraction.py```.

```
import ctypes  
from ctypes import *  
lib = cdll.LoadLibrary('../Common/Release/libCommon.so')  

def __init__(self):  
    self.obj = lib.vidl_new()  '''initialise an instance of the library.'''

'''Step 1: Execute the process.'''
lib.vidl_run_on_4_processors(self.obj, create_string_buffer(b_in_dir), create_string_buffer(b_out_dir))  

'''Step 2: Allocate storage for return arrays.'''
number_videos = c_int()
number_frames_elements = c_int()
all_videos_frame_count = POINTER(c_int)()  '''an array to contain the number of frames for multiple videos.'''
all_videos_frame_data = POINTER(c_int)()   '''an array to contain all the data frames for multiple videos.'''

'''Step 3: Fetch the data.  Pass them all by reference so that new values can be returned.'''
lib.vidl_get_all_videos_frames(self.obj, byref(number_videos), byref(all_videos_frame_count), byref(number_frames_elements), byref(all_videos_frame_data))

'''your code here.'''

'''Step 4: Free the C arrays.'''
lib.vidl_delete(self.obj, all_videos_frame_count, all_videos_frame_data)
```  
Reference: (https://stackoverflow.com/questions/52204971/python-ctypes-pass-argument-by-reference-error)

### A code snippet in C++  
The complete code can be found in `load_video.cpp`.  
```
#include <iostream>
#include "CommonDataDefs.h"
#include "video_loader.h"

using namespace CommonDataDefs;
using namespace std;

IntT main( IntT argc, CharT *argv[] )
{
  // ... code for displaying help and reading command line arguments.
  
  // Step 1: Create an instance of VideoLoader.
  VideoLoader video_loader;
  
  // Step 2: Create data structures to hold return arrays.
  IntVectorT videos_frames_count_list;
  UCharVectorT videos_frames_data;
  
  // Step 3: Execute the process.
  video_loader.run_on_4_processors( arguments.at( 2 ), arguments.at( 3 ) ); // input directory, output directory.
  
  // Step 4: Get the data.
  video_loader.get_videos_frames( videos_frames_count_list, videos_frames_data );
  
  return 0;
}
```
