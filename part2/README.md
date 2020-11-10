# Digital Sound

Sound is simply a wave transmitted through the atmosphere through changing pressure. To generate a sound wave, we can use a speaker to vibrate which in turn compresses and decompresses the air around it.  Done repeatedly, it produces the changes in pressure that we perceive as sound. 

### Table of Usage Contents

- [Part 2](#Part-2)

### Usage

Clone the repository. There are **1** executables: main. 

```sh
$ make 
```

## Part 2

**For main,**

```sh
$ ./main <wave_type> <sample_rate> <frequency> <duration> <file_name>
```

For <wave_type>:
1. Sine
2. Square
3. Triangle
4. Saw

An example command would be,

```sh
$ ./main 2 8000 440 1 square_output.txt
```

It will run the executable with
- Wave Type:    **Square**
- Sample Rate:  **8000**
- Frequency:    **440**
- Duration:     **1s**
- File name:    **square_output.txt**

License
----

MIT
