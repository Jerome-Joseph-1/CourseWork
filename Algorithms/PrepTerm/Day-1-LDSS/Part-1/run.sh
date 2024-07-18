#!/bin/bash

echo "Compiling main.cpp"

# Measure compilation time
start_compile=$(date +%s)
g++ main.cpp -o main
end_compile=$(date +%s)
compile_time=$((end_compile - start_compile))

if [ -f main ]; then
    echo "Compilation completed in $compile_time seconds."

    echo "Executing main.cpp"
    
    # Measure execution time
    start_exec=$(date +%s)
    ./main < input.txt
    end_exec=$(date +%s)
    exec_time=$((end_exec - start_exec))
    
    echo "Execution completed in $exec_time seconds."
    
    rm main
    echo "Program Completed"
else
    echo "Compilation failed. main executable not found."
fi
