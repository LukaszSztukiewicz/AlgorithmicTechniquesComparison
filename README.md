# CuPyterLab
Environment for performing experiments in C++ data analysis in Python with extensive support for Jupyter Notebooks.

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
```
If the there is an error "ptest command is not found" simply load your terminal source file:
```
    . ~/.zshrc
```
### Usage
Add a C++ source file: 
```
    mf NAME_OF_YOUR_FILE
```
Compile your source code: 
```
    ptest
```
Run build: 
```
    pbuild
```
Run all tests: 
```
    ptest
```
Run compiled binary: 
```
    prun
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
