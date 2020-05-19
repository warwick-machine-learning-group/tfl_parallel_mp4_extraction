## Tests output

### Machine specifications:  
AMD Athlon X4 880K Quad Core Processor  
16GB DDR3 SDRAM  
1TB Harddisk  
GeForce GTX 1050.  

### Operating system:  
Ubuntu 16.04 LTS.

### Test:
Number of videos: 52   
Resolution: 352 x 288   

1. 4 cores: Python script `run_4_parallel_video_extraction.py`   
<img src = "https://github.com/warwick-machine-learning-group/tfl_parallel_mp4_extraction/blob/master/Test_Output/test_result_run_on_4_cores.png" height="400">

2. 4 cores: C++ executable `vidext`   
<img src = "https://github.com/warwick-machine-learning-group/tfl_parallel_mp4_extraction/blob/master/Test_Output/test_run_c%2B%2B_executable_on_4_cores.png" height="400">

3. 1 core: C++ executable `vidext`
<img src = "https://github.com/warwick-machine-learning-group/tfl_parallel_mp4_extraction/blob/master/Test_Output/test_run_single_core.png" height="140">
