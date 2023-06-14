#!/bin/bash

set -e

if [[ $1 == *.cpp ]];
then
	filename=$1
	output=${1##*/}
	output=${output%.*}
else
	filename="$1.cpp"
	output=${1##*/}
fi

echo "filename = $filename"
echo "output = $output"

g++ -std=c++17 $filename -o $output
echo "Compilation finished!"

d=`date +'%Y%m%d_%H%M%S'`
output_dir="${d}_${output}_output"
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
  /usr/bin/time -f "execution time: %e s"  ./$output < $f > $out
done
