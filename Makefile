B = bin/

TARGETS = $Bdft.plot $Bdft.benchmark
LIBS = -lm
CFLAGS = -Wall -Wextra -O3
CC = gcc

all: $(TARGETS)

$Bdft.plot: $Bdft.plot.o $Bdft.o $Bhelpers.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$Bdft.benchmark: $Bdft.benchmark.o $Bdft.o $Bhelpers.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$B%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	cd $B && /bin/rm * && cd ..
