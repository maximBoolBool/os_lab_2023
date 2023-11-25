CC = gcc
CFLAGS = -Wall -pthread

all: client server

# Создайте индекс для библиотеки common.a перед компиляцией client и server
client: client.c common/libcommon.a
	$(CC) $(CFLAGS) -o client client.c -Lcommon -lcommon

common/libcommon.a common/common.o
	ar rcs common/libcommon.a common/common.o
	ranlib common/libcommon.a

common/common.o: common/common.c common/common.h
	$(CC) $(CFLAGS) -c -o common/common.o common/common.c

clean:
	rm -f client server common/libcommon.a common/common.o
