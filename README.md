# CuPyterLab
Environment for performing experminents in C++  data analisys in Python with extensive support for Jupyter Notebooks.

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
    chmod +x ./scripts/bash/env-setup.sh 
    ./scripts/bash/env-setup.sh "YOUR_PROJECT_NAME_IN_QUOTATION_MARKS"
    ptest
```
### Usage
Run build: 
```
    pbuild
```
Run compiled binary: 
```
    prun
```
Run all tests: 
```
    ptest
```
### Dependencies:
 - [x] google test
 - [x] cmake
 - [ ] btaf
 - [ ] graphviz, anim

### Future
 - [ ] Ninja
 - [ ] gdb

File extensions:
 - .cc for C++ (Linux style)
 - .h for C++ headers
