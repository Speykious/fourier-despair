B = bin/

TARGETS = $Bdft.plot
LIBS = -lm
CFLAGS = -g -Wall -Wextra
CC = gcc

all: $(TARGETS)
	
$Bdft.plot: $Bdft.plot.o $Bdft.o $Bhelpers.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$B%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	cd $B && /bin/rm $(TARGETS) && cd ..
