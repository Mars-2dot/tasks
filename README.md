# tasks
---  
The test file for task 13.1.45 will be located in the build directory. 
Usage example: "./tasks_13_1_45.exe -f ../file.txt -s test -r find" 
# **Dependencies**  
1) Googletest
2) GoogleBenchmark
3) Boost::program_options,filesystem
# **Build**  
## Unix   
```sh 
git clone https://github.com/Mars-2dot/tasks.git  
cd tasks  
mkdir build && cd build  
cmake ..  
make  
```
## Win
If used msvc 
```sh
git clone https://github.com/Mars-2dot/tasks.git  
cd tasks
mkdir build && cd build
cmake ..  
msbuild .\ALL_BUILD.vcxproj
```
