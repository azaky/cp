#!/bin/bash

# Installation:
# - Download the file.
#   $ wget https://gist.githubusercontent.com/azaky/9682507b62c9b22dca4d3290e74c3e60/raw/bade3755a516122b0ccfbb0107000e5ae3104d47/run_hashcode_go.sh
# - Make the file executable.
#   $ chmod +x run_hashcode_go.sh
#
# Setup:
# - Put the test data into folder input_data.
#   From the directory you run this script:
#   $ ls input_data
#   a_an_example.in.txt  b_basic.in.txt  c_coarse.in.txt  d_difficult.in.txt  e_elaborate.in.txt
#
# Usage:
# 1. From top-level directory
#    $ ./run_hashcode_go.sh main.go
#    It will create a new folder <timestamp>_go_output containing
#    the source code (copied) and the outputs for each test cases.
# 2. From inside a directory
#    $ ./run_hashcode_go.sh dir/main.go
#    It will create a new folder <timestamp>_<dir>_output like above.
#
# Example run:
# $ ./run_hashcode_go.sh main.go
#   Compiling main.go into main ...
#   Compilation finished!
#   Creating output dir 20220224_172244_go_output ...
#   Copying source code to output dir ...
#   Running ...
#   Processing input_data/a_an_example.in.txt ...
#   execution time: 0.00 s
#   Processing input_data/b_basic.in.txt ...
#   execution time: 0.00 s
#   Processing input_data/c_coarse.in.txt ...
#   execution time: 0.00 s
#   Processing input_data/d_difficult.in.txt ...
#   execution time: 0.46 s
#   Processing input_data/e_elaborate.in.txt ...
#   execution time: 0.46 s
#
# $ ./run_hashcode_go.sh some_directory/main.go
#   Compiling some_directory/main.go into main ...
#   Compilation finished!
#   Creating output dir 20220224_172330_some_directory_output ...
#   Copying source code to output dir ...
#   Running ...
#   Processing input_data/a_an_example.in.txt ...
#   execution time: 0.00 s
#   Processing input_data/b_basic.in.txt ...
#   execution time: 0.00 s
#   Processing input_data/c_coarse.in.txt ...
#   execution time: 0.00 s
#   Processing input_data/d_difficult.in.txt ...
#   execution time: 0.44 s
#   Processing input_data/e_elaborate.in.txt ...
#   execution time: 0.50 s

set -e

if [[ $1 == *.go ]];
then
	filename=$1
else
	filename="$1.cpp"
fi

# If the file is inside a directory, we use the directory name as the output.
# Otherwise, set it to "go".
if [[ $filename != */* ]];
then
	output="go"
else
	output="$(dirname "$filename")"
	output="$(basename "$output")"
fi

# Compile the file.
executable="main"

echo "Compiling $filename into $executable ..."
go build -o $executable $filename
echo "Compilation finished!"

d=`date +'%Y%m%d_%H%M%S'`
output_dir="${d}_${output}_output"

echo "Creating output dir $output_dir ..."
mkdir -p $output_dir

echo "Copying source code to output dir ..."
cp $filename $output_dir

echo "Running ..."

input_dir="input_data"
for f in "$input_dir"/*
do
  echo "Processing $f ..."
  out="${f/.in/".out"}"
  out="${out/$input_dir/"$output_dir"}"
	/usr/bin/time -f "execution time: %e s" ./$executable < $f > $out
done
