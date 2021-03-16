# tasks
---  
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
cd Modules
git clone https://github.com/google/googletest.git && cd googletest  
mkdir build && cd build
cmake ..  
```
Then build the dependency in any convenient way and install the project itself with the tasks.  
```sh
cd *root directory of repo*  
mkdir build && cd build  
cmake ..  
```
Build a project in any convenient way.
# **Usage**  
Directory with tasks - 'main'  
Directory with tests - 'tests'  
These directories will contain executable files  



