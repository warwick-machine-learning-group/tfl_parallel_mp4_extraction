# A Parallel Video Extraction library

This objective of this project is to develop a parallel video extraction library. The library uses the Message Passing Interface (MPI) for parallel computing. Differently to video loaders that use multi-threading which can be executed on a single CPU or on cell-based processors found in graphics cards, the library uses multiple CPUs. On one hand, video processing is well suited for graphical processing units. On the other hand when processing in bulk there is a potential for obtaining a speedup using multiple CPUs.

Currently, three Python scripts are provided for extracting all the frames in multiple videos using 4, 8 and 16 CPUs.  The names of the script are given below:   
1. `run_4_parallel_video_extraction.py`
2. `run_8_parallel_video_extraction.py`
3. `run_16_parallel_video_extraction.py`

The Python scripts are available in the folder `TestStub`.  A Linux shell executable is also provided in `TestStub/Release`.   
Tests output are available in the folder `Test_Output`.  

The data frames can be saved into a local filesystem directory.  The data frames can be loaded into memory, for example: in Python's data structures, C / C++ data structures.  

## Usage
To execute on 4 CPUs:  
`mpirun -np 4 python run_4_parallel_video_extraction.py -i <input directory> -o <output directory>`

To execute on 8 CPUs:  
`mpirun -np 8 python run_8_parallel_video_extraction.py -i <input directory> -o <output directory>`
  
To execute on 16 CPUs:  
`mpirun -np 16 python run_16_parallel_video_extraction.py -i <input directory> -o <output directory>`
  
### Notes on usage
1. Save to disk: If you want to save the frames into a local filesystem directory, provide an output directory.  When an output directory is provided, the frames will only be written to the filesystem and not loaded into memory.  
2. Load into memory: If you want to load the frames into memory only, provide `-o ""` as the output directory. This will notify the program that all the frames are to be loaded into memory. The frames will not be saved to disk.  

## Dependencies
The following libraries must be installed on your machine:  
1. Boost C++ version 1.73.  https://www.boost.org/users/history/version_1_73_0.html. The video extraction library uses Boost::filesystem.
2. OpenCV 4.3. https://opencv.org/releases/ 
3. OpenMPI 4.0.3. https://www.open-mpi.org/software/ompi/v4.0/ 
