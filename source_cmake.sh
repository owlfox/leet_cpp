#!/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"
cmake_dir=$(ls cmake-3.2* -1d)
export PATH=${parent_path}/${cmake_dir}/bin:$PATH
cd -
echo "Using cmake at: $(which cmake)"
