TARGETS = dft.plot
LIBS = -lm
CFLAGS = -g -Wall -Wextra
CC = gcc

all: $(TARGETS)
	
dft.plot: dft.plot.o dft.o helpers.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	/bin/rm $(TARGETS)
