# Tên của tệp thực thi
TARGET = main

# Thư mục chứa các tệp nguồn (source files)
SOURCE_DIR = src

# Thư mục chứa các tệp header
HEADER_DIR = inc

# Các tệp nguồn (source files)
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)

# Các tệp đối tượng (object files) tương ứng với các tệp nguồn
OBJECTS = $(SOURCES:.c=.o)

# Trình biên dịch
CC = gcc

# Cờ biên dịch (có thể thêm các cờ khác tùy theo nhu cầu)
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra

# Quy tắc biên dịch tệp đối tượng từ tệp nguồn
$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Quy tắc biên dịch tệp thực thi từ các tệp đối tượng
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Quy tắc chạy tệp thực thi
run: $(TARGET)
	./$(TARGET)

# Quy tắc dọn dẹp (xóa các tệp đối tượng và tệp thực thi)
clean:
	rm -f $(SOURCE_DIR)/*.o $(TARGET)

# Đánh dấu các quy tắc không phải là tên tệp
.PHONY: all clean run
