#!/bin/bash

if [ "YOUR_PROJECT_NAME_IN_QUOTATION_MARKS" = "$1" ]; then
  projectname="defaultproject"
elif [ -z "$1" ]; then
  projectname="defaultproject"
else
  projectname="$1"
fi

#add dependencies
cd lib && git clone https://github.com/google/googletest.git && cd ..

echo "
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Set the name of the project as THIS variable
set(THIS ${projectname})
project(\${THIS})

#source headers
include_directories(src)

#dependencies
add_subdirectory(lib/googletest)

#our subdirectories (goes into subdirectory and searches for CMakeLists.txt there)
add_subdirectory(src)
add_subdirectory(test)
" > CMakeLists.txt

prun="alias prun=./build/bin/${projectname}_run" 
ptest="alias ptest=./build/bin/${projectname}_test"
pbuild="alias pbuild=./scripts/bash/pbuild.sh"
pmake="alias pmake=./scripts/bash/pmake.sh"

#check what type of shell you are using and add the functions to the shell profile
for i in in "$HOME/.zshrc" "$HOME/.bashrc" "$HOME/.bash_profile" "$HOME/.profile"; do
  if [ -f $i ]; then
    for j in "$prun" "$ptest" "$pbuild" "$pmake"; do
      if [ -z "$(grep -F "$j" $i)" ]; then
        echo "$j" >> $i
      fi
    done
  fi
done

chmod +x ./scripts/bash/mf.sh
./scripts/bash/mf.sh ${projectname}

#run build
chmod +x ./scripts/bash/pbuild.sh
chmod +x ./scripts/bash/pmake.sh

