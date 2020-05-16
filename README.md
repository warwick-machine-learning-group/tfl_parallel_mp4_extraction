# A Parallel Video Extraction library

This objective of this project is to develop a parallel video extraction library and integrate it into Python.  
A goal of the project is to obtain a speedup when extracting videos frames.

Currently, we have provided three Python scripts to extract all the frames in multiple videos using 4, 8 and 16 processor cores:
1. run_4_parallel_video_extraction.py
2. run_8_parallel_video_extraction.py
3. run_16_parallel_video_extraction.py

The video frames can be saved into a local filesystem directory or loaded into memory, for example: Python's numpy arrays, C / C++ arrays.

## Usage:
To execute on 4 processor cores:
mpirun -np 4 python run_4_parallel_video_extraction.py -i <input directory> -o <output directory>

To execute on 8 processor cores:
mpirun -np 8 python run_8_parallel_video_extraction.py -i <input directory> -o <output directory>
  
To execute on 16 processor cores:
mpirun -np 16 python run_16_parallel_video_extraction.py -i <input directory> -o <output directory>
  
### Notes on usage
1. If you want to save the frames into a local filesystem directory, provide an output directory.  When an output directory is provided, the frames will only be written to the filesystem and not loaded into memory.
2.  Work-in-progress (Expected completion 21 May 2020): If you want to load the frames into memory, provide "" as the output directory.  This will notify the program that all the frames are to be loaded into memory.
