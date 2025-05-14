# Nama file output
TARGET = sistem_paket

# File sumber
SRCS = main.c admin.c menu.c kode.c paket.c sorting.c global.c

# File header
HEADERS = header.h

# Compiler dan flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Build rules
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
