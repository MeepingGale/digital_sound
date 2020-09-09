# Digital Sound

Sound is simply a wave transmitted through the atmospherethrough changing pressure. To generate a sound wave, we can use a speaker to vibrate which in turn compresses and decompresses the air around it.  Done repeatedly, it produces the changesin pressure that we perceiveas sound. 


### Usage

Clone the repository. There are **2** executables, gensine and gendial. 

```sh
$ make
```

For gensine,

```sh
$ ./gensine
```

The program then will ask you to enter frequency, sample rate, and duration.

For gendial, 

```sh
$ ./gendial
```

The program then will ask you to enter a 10-digit number.


### DTMF

DTMF stands for Dual-Tone Multi-Frequency and is most commonly used in telephone dialing and signaling. The frequencies are as of below:

|        | 1209 Hz | 1336 Hz | 1477 Hz | 1633 Hz |
| ------ | :-----: | :-----: | :-----: | :-----: |
| 697 Hz |    1    |    2    |    3    |    A    |
| 770 Hz |    4    |    5    |    6    |    B    |
| 852 Hz |    7    |    8    |    9    |    C    |
| 941 Hz |    *    |    0    |    #    |    D    |


License
----

MIT
