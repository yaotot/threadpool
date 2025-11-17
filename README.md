# Task: Develop a thread pool with c++

## Concept:
1. Thread pool mange and maintain a certain nummer of threads
2. Why need the thread pool?
   - time consumed task async given to other thread, realse the process ability of the kern thread
   - maximum use the system resource
3. Time consumed task 
    -  time wait IO operation(net, file)
    -  time caculation 

4. how to decide the number of thread in pool?
    - cpu center    --number of cpu core
    - IO center     --2 * number of cpu core
  
5. Componet of the thread pools
    - producter thread
    - data structure: multithread operation env, Queue
    - thread pool thread (consumer threads)