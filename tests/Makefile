CLANG=/mnt/traces/jma/llvm-project/build/bin/clang-16

all:
	$(CLANG) -ggdb -O2 -fsanitize-address-field-padding=1 -fsanitize=address test3.c -o test

ast:
	$(CLANG) -Xclang -ast-dump -fsanitize-address-field-padding=1 -fsanitize=address test3.c | grep HERE -A500

normal:
	$(CLANG) test3.c -o test
clean:
	rm -f test
