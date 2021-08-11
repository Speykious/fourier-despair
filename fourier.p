set xlabel 'Frequency (?)'
set ylabel 'Amplitude'
set y2label 'Amplitude'
plot for [i=2:3] 'dft_sine_440.plot.txt' using 1:i with fs

pause -1
