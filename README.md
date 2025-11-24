# LBYARCH MCO2

By Francisco and Limtin, S20A

## Program Ouput
![alt text](image.png)

## Results (in seconds)
### 10x10
NASM + C, Average = 0.015

NASM + C, Total = 0.463

C Only, Average = 0.014

C Only, Total = 0.430

### 100x100
NASM + C, Average = 1.525

NASM + C, Total = 45.751

C Only, Average = 1.499

C Only, Total = 44.975

### 500x500
NASM + C, Average = 27.352

NASM + C, Total = 820.546

C Only, Average = 27.693

C Only, Total = 830.795

### Explanation
Hypothetically, NASM is faster in most cases. However, since C does some optimization, making C faster, the results are only slightly different. Cache is also something to consider as it could make the code run faster for both methods.