import os
import time
import numpy as np  # Import numpy

# Kiểm tra xem thư mục có tồn tại không trước khi thay đổi
dir_path = r"C:\Users\LENOVO\Documents\CODE\CTDL\sortalgo\test\pythonsort"
if os.path.exists(dir_path):
    os.chdir(dir_path)
else:
    print(f"Lỗi: Thư mục {dir_path} không tồn tại!")
    exit()

def process_file(input_filename, output_filename, test_num):
    try:
        with open(input_filename, 'r') as f:
            data = list(map(float, f.read().split()))
        
        if not data:
            print(f"Lỗi: {input_filename} rỗng!")
            return

        n = int(data[0])  
        arr = np.array(data[1:n+1])  # Chuyển danh sách thành mảng numpy

        # Đo thời gian sắp xếp bằng numpy.sort()
        start = time.time()  
        sorted_arr = np.sort(arr)  # Sử dụng numpy.sort()
        end = time.time()
        elapsed_time = end - start

        # Ghi thời gian vào report.txt (chế độ 'a' để không bị ghi đè)
        with open("report.txt", 'a') as f:
            f.write(f"Test {test_num}: {elapsed_time:.6f} giây\n")

        # Ghi kết quả sắp xếp vào file output
        with open(output_filename, 'w') as f:
            f.write(" ".join(map(str, sorted_arr)))

        print(f"✅ Hoàn thành {input_filename} -> {output_filename}, thời gian: {elapsed_time:.6f} giây")
    
    except Exception as e:
        print(f"❌ Lỗi khi xử lý {input_filename}: {e}")

# Xóa nội dung cũ của report.txt trước khi chạy
open("report.txt", 'w').close()

# Xử lý 10 test
for i in range(10):
    input_file = f"{i}.inp"
    output_file = f"{i}.out"
    
    if os.path.exists(input_file):
        process_file(input_file, output_file, i)
    else:
        print(f"⚠️ File {input_file} không tồn tại!")
