# tasks
---  

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
To work, you need to manually install googletest.
```sh
git clone https://github.com/Mars-2dot/tasks.git  
cd tasks
mkdir build && cd build
cmake ..  
msbuild .\ALL_BUILD.vcxproj
```
