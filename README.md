# Roman Numeral Calculator 

#### This repo should demonstrate a coding kata in the "c" language to add and subtract roman numeral values. 

##### Environment Requirements:
- Ubuntu Linux 14.04
- The C programming language
- GNU GCC compiler tool chain
- GNU Make
- Check unit testing framework ( https://libcheck.github.io/check/ )
- git

##### Setup Notes to Add to Vagrant
- vagrant and hyper-v on windows 
- sudo apt-get install build-essential 
- sudo apt-get install check
- sudo apt-get install zsh
- sudo apt-get install git 
- sudo apt-get install pkg-config 

##### Roman Numeral Rules
- Roman numerals consist of the following letters: I, V, X, L, C, D, and M which mean one, five, ten, fifty, hundred, five hundred and one thousand respectively.
- No more than 3 I,X,C (e.g. IIII, XXXX, CCCCCC)
- No more than 1 V,L,D (e.g. VV, LL, DD)


##### Strategy 
I = 1 
V = 5  
I+V = 4 
II + V = 3 
III + V = 2 
IIII + V = !  

----  
1-5 = (-4) 
1+1-5 = (-3) 
1+1+1-5 = (-2)  

--- 
[[1][5]] = 4 
[[1][1][5]] = 3 
[[1][1][1][5]] = 2 
[[1][1][1][1][5]] = ! 

---
q: for 3995, how many M's can I fit?
a: 3 with 995 remainder
q: for 995, how many Ds can I fit?
a: 1, or you could fit a CM which is 900

MMMDCCCCLXXXXV ! invalid - 4 Cs 4 Xs
should be MMMCMVC  
To Reduce, adding IV 4 and IX 9 etc. will allow more reduced combinations.



##### Running the app to see test output
```
make
./bin/roman
``` 
