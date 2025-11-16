# Task: Develop a thread pool with c++

## Concept:
1. Thread pool mange and maintain a certain nummer of threads
2. Why need the thread pool?
   - time consumed task async given to other thread, realse the process ability of the kern thread
   - maximum use the system resource
3. Time consumed task 
    -  time wait IO operation(net, file)
    -  time caculation 