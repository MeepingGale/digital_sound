# Digital Sound

Sound is simply a wave transmitted through the atmosphere through changing pressure. To generate a sound wave, we can use a speaker to vibrate which in turn compresses and decompresses the air around it.  Done repeatedly, it produces the changes in pressure that we perceive as sound. 

### Table of Usage Contents

- [Part 2a](#Part-2a)
- [Part 2b](#Part-2b)

### Usage

Clone the repository. There's **1** executables: main. 

```sh
$ make 
```

## Part 2a

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

## Part 2b

**For main2b,**

```sh
$ ./main2b
```
It will guide you to input values and returns error message if an error occurs.

For <wave_type>:
1. Sine
2. Square
3. Triangle
4. Saw

It will give out these prompts 
- Enter the delay.  **delay >= 0**
- Enter the attenuation.    **attenuation >= 0**
- Enter the atime.  
- Enter the alevel.  **(alevel <= 1 && alevel > 0)**
- Enter the dtime.  
- Enter the slevel. **(slevel <= 1 && slevel > 0)**
- Enter the rtime. 
- Enter the filename.    

Make sure sum of atime, dtime, rtime does not exceed 8000.

License
----

MIT
