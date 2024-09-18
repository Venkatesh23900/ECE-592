CC = g++
SRCS = inv_sbox.cpp inv_subbytes.cpp inv_shiftrows.cpp inv_mixcolumns.cpp addroundkey.cpp AES_DEC.cpp
OUT = AES_DEC
OUT_TXT = AES_DEC_128_out.txt

.PHONY: run clean

run:
	$(CC) -o $(OUT) $(SRCS)
	./$(OUT) > $(OUT_TXT)

clean:
	rm *.txt
	rm ./$(OUT)

