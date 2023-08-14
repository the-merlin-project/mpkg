build:
	rm -r ../build
	mkdir ../build
	$(CC) ./main.c -o ../build/mpkg -Wall -Wextra -Wshadow -fsanitize=address
run:
	../build/mpkg
clean:
	rm -r ../build
