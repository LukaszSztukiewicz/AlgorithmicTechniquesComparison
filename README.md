# CuPyterLab
Environment for performing experminents in C++ and data analisys in Python with extensive support for Jupyter Notebooks.

[Google Style Guide](https://google.github.io/styleguide/cppguide.html)

Target: 
 - [x] Linux
 - [x] WSL2

### Setup: 
#### Linux
```
    git clone https://github.com/LukaszSztukiewicz/CuPyterLab.git && cd CuPyterLab
```

```
    ./configure ; make ; make install
    chmod +x ./scripts/bash/env-setup.sh 
    ./scripts/bash/env-setup.sh "YOUR_PROJECT_NAME_IN_QUOTATION_MARKS"
    ptest
```
### Usage
Build: 
```
    make
```
Run: 
```
    prun
```
Test: 
```
    ptest
```
Debug:
```
    cmake . -DCMAKE_BUILD_TYPE=Debug
```
### Dependencies:
 - [x] google test
 - [x] cmake
 - [ ] btaf
 - [ ] graphviz, anim
 - [ ] gdb

File extensions:
 - .cc for C++ (Linux style)
 - .h for C++ headers
