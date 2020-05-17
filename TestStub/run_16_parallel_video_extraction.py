'''
* Filename: run_16_parallel_video_extraction.py
* Author: Edward Chuah
* Organisation: The University of Warwick, UK
* Owner: To be included
* Licence: To be included
'''
#!/usr/bin/env python

import sys
import getopt
import ctypes
from ctypes import *
lib = cdll.LoadLibrary('../Common/Release/libCommon.so')

class VidLdr(object):
  def __init__(self):
    self.obj = lib.vidl_new()

  def run_on_16_processors(self, in_dir, out_dir):
    b_in_dir = in_dir.encode('utf-8')
    b_out_dir = out_dir.encode('utf-8')
    lib.vidl_run_on_16_processors(self.obj, create_string_buffer(b_in_dir), create_string_buffer(b_out_dir))
    number_videos = c_int()
    number_frames_elements = c_int()
    all_videos_frame_count = POINTER(c_int)()
    all_videos_frame_data = POINTER(c_int)()
    lib.vidl_get_all_videos_frames(self.obj, byref(number_videos), byref(all_videos_frame_count), byref(number_frames_elements), byref(all_videos_frame_data))
    print('From Python, received total number of videos', number_videos.value)
    print('From Python, received total number of frames elements', number_frames_elements.value)

  def delete(self):
    lib.vidl_delete(self.obj)

def main(argv):
  input_dir = ''
  output_dir = ''
  opt_list, args = getopt.getopt(argv, "hi:o:", ["idir=", "odir="])
  for opt, arg in opt_list:
    if opt == '-h':
      print('mpirun -np 16 python run_16_parallel_video_extraction.py -i <input_directory> -o <output_directory>')
      sys.exit()
    if opt in ("-i", "--idir"):
      input_dir = arg
    if opt in ("-o", "--odir"):
      output_dir = arg

  v = VidLdr()
  v.run_on_16_processors(input_dir, output_dir)
  v.delete()

if __name__ == "__main__":
  main(sys.argv[1:])
