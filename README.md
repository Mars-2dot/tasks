# tasks
---  
The test file for task 13.1.45 will be located in the build directory. 
Usage example: "./tasks_13_1_45.exe -f ../file.txt -s test -r find" 
# **Dependencies**  
1) Googletest
2) GoogleBenchmark
3) Boost::program_options,filesystem  
If the dependencies are not found on the host, they will be downloaded and installed using the so-called "super-assembly" of cmake. In this case, after the first build, `you need to restart cmake`  so that the installed libraries at the build location are used in the future.
# **Build**  
## Unix(In progress)   
```sh 
git clone https://github.com/Mars-2dot/tasks.git  
cd tasks  
mkdir build && cd build  
cmake ..  
make  
```
## Win
You must use msvc and ninja 
```sh
git clone https://github.com/Mars-2dot/tasks.git  
cd tasks
mkdir build && cd build
cmake -G Ninja ..  
ninja
```
