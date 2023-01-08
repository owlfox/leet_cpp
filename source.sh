#!/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )

cd "$parent_path"
export PATH=${parent_path}/cmake-3.25.1-linux-x86_64/bin:$PATH
cd -