#include<iostream>

#include<taskflow/taskflow.hpp> //Header only?

using namespace std;

int main(int argc, char* argv[]) {
    tf::Executor executor;
    tf::Taskflow taskflow;

    auto [A, B, C, D] = taskflow.emplace(  // create four tasks
        [] () { cout << "Task-A\n"; },
        [] () { cout << "Task-B\n"; },
        [] () { cout << "Task-C\n"; },
        [] () { cout << "Task-D\n"; } 
    );                                  
                                        
    A.precede(B, C);  // A runs before B and C
    D.succeed(B, C);  // D runs after  B and C
                                        
    executor.run(taskflow).wait();

    return 0;
}