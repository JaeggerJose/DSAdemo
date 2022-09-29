# Homework 1 is for 2 dimensions dynamic array and pointer operation

---
### Homework 1-1
- 2 version: ``new`` ``malloc``

We need 2 input x and y, which for the number of string and legth limitation of each string.

And then we need to input the string and insert it into the 2 dimension.

After inserted it, needed to sorting it with *ASCII from large to small* using *Bubble sort*.

#### Problem solutions
1. If we use malloc we need to use ``memset`` to clear the address.
2. If we want to select the both method ``malloc`` and ``new``, we need to set a *deafult memory allocate method* before determine method, which we are going to use.
---
### Homework 1-2

According to the Question 1-1, we can enter some latin name, and we need to **align the space** of each latin name.

---

### Constructing Code

- Homework 1-1
  1. Declare and input x and y value for the number of strings and the legth limitaion of each string.
  2. Declare and input method for selecting the way to allocate memory. **(optional)**
  3. Allocate the first dymension of the pointer arrays, and the amont of the pointer arrays is x.
  4. Allocate the second dymension of the x pointers in last pointer array, and the amount of the pointers is y.
  5. Input the string x time and insert the each letter one by one into the pointer, which the last step was allocated,   meanwhile check if the inputed string is longer than y, or not.
  6. Checking the first letter's **ASCII** and using bubble sort to sort the string from the largest value to the smallest.
  7. print the whole strings out.
- Homework 1-2
  1. Declare and input x value for the number of strings and the string array with size.
  2. Start input string and meanwhile checking the length of each string.
  3. find the maximum lenght of string out and insert the maxixmum string length value into y.
  3. Allocate the first dymension of the pointer arrays, and the amont of the pointer arrays is x.
  4. Allocate the second dymension of the x pointers in last pointer array, and the amount of the pointers is y.
  5. Input the string x time and insert the each letter one by one into the pointer, which the last step was allocated, meanwhile check if the inputed string is longer than y, or not.
  6. Counting the string length before space and get the maximum of the string length.
  7. Get the needed added space amount using the maximum of the string length to minux each string length before space.
  8. Direct print the space for each string and then print strings out one by one. (Step 8 and Step 9 choice one to use)
  9. Add the needed added space front the string and print them out. (Step 8 and Step 9 choice one to use)
 
---
### Task finished checking
- [x] Homework 1-1 new version
- [x] Homework 1-1 malloc version
- [x] Homework 1-1 both selecting version
- [x] Homework 1-2
---
### Reference
- [2D dynamic array](https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new)
- [Malloc method](https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/)
- [New method](https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/)
- [cin string method](https://stackoverflow.com/questions/61572940/c-beginner-stdcin-to-stdstring)
- [getline skipped solution](https://stackoverflow.com/questions/42818899/detecting-enter-key-in-c)
- [string strcpy method](https://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c)
- [Clear Char Array in C](https://www.delftstack.com/howto/c/clear-array-in-c/)
- [Segmentation fault 1](https://blog.csdn.net/Genaral_/article/details/124078032)
- [Segmentation fault 2](https://blog.51cto.com/u_15072908/4283378)
- [Free and delete](https://stackoverflow.com/questions/38136086/how-do-you-free-a-2d-mallocd-array-in-c)
- [Control the legth of cout](https://stackoverflow.com/questions/25918057/how-to-set-a-fixed-width-with-cout)
