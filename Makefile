CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lm

src_dir = src/
obj_dir = obj/
out_dir = out/

src = $(wildcard $(src_dir)*.c)
obj = $(src:$(src_dir)%.c=$(obj_dir)%.o)

kdf: $(obj)
	$(CC) $(CFLAGS) -o $(out_dir)$@ $^

$(obj_dir)%.o: $(src_dir)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) kdf
