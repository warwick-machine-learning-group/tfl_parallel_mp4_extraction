'''
* Filename: run_8_parallel_video_extraction.py
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

  def run_on_8_processors(self, in_dir, out_dir):
    b_in_dir = in_dir.encode('utf-8')
    b_out_dir = out_dir.encode('utf-8')
    lib.vidl_run_on_8_processors(self.obj, create_string_buffer(b_in_dir), create_string_buffer(b_out_dir))

  def delete(self):
    lib.vidl_delete(self.obj)

def main(argv):
  input_dir = ''
  output_dir = ''
  opt_list, args = getopt.getopt(argv, "hi:o:", ["idir=", "odir="])
  for opt, arg in opt_list:
    if opt == '-h':
      print('mpirun -np 8 python run_8_parallel_video_extraction.py -i <input_directory> -o <output_directory>')
      sys.exit()
    if opt in ("-i", "--idir"):
      input_dir = arg
    if opt in ("-o", "--odir"):
      output_dir = arg

  v = VidLdr()
  v.run_on_8_processors(input_dir, output_dir)
  v.delete()

if __name__ == "__main__":
  main(sys.argv[1:])
