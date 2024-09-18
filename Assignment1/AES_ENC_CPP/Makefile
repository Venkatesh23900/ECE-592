CC = g++
SRCS = sbox.cpp subbytes.cpp shiftrows.cpp mixcolumns.cpp addroundkey.cpp AES_ENC.cpp
OUT = AES_ENC
OUT_TXT = AES_ENC_128_out.txt

.PHONY: run clean

run:
	$(CC) -o $(OUT) $(SRCS)
	./$(OUT) > $(OUT_TXT)

clean:
	rm *.txt
	rm ./$(OUT)
