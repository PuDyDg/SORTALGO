import os
import time
import numpy as np  

dir_path = r"C:\Users\LENOVO\Documents\CODE\CTDL\sortalgo\test\pythonsort"
os.chdir(dir_path)


def process_file(input_filename, output_filename, test_num):
    with open(input_filename, 'r') as f:
        data = list(map(float, f.read().split()))
    


    n = int(data[0])  
    arr = np.array(data[1:n+1])  

    start = time.time()  
    sorted_arr = np.sort(arr)  
    end = time.time()
    elapsed_time = end - start

    with open("report.txt", 'a') as f:
        f.write(f"Test {test_num}: {elapsed_time:.6f} giây\n")

    with open(output_filename, 'w') as f:
        f.write(" ".join(map(str, sorted_arr)))

    


open("report.txt", 'w').close()

for i in range(10):
    input_file = f"{i}.inp"
    output_file = f"{i}.out"
    
    process_file(input_file, output_file, i)

