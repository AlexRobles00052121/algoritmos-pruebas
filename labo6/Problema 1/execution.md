# Manual Execution

If you open this file, only if you want install the extension "Auto-Open Markdown Preview", later click in 'Ctrl + K V' or '⌘ + K V'

In this execution we will do the MaxOneD.

In the first step we will take the array.

Example:

Cases: 1

n = 5


Visually =

| 2 | -3 | 5 | -1 | 4 |
|:--|:--|:---|:--|:--|
|0|1|2|3|4|

A[n+1];

currSum = 0

A[ 0 ] = 0

| 0 |  |  |  |  |  |
|:--|:--|:--|:---|:---|:--|

1°  
i = 1

CurrSum = max(currSum + A[i -1], A[i-1])

| 2 | -3 | 5 | -1 | 4 |
|:--|:--|:---|:--|:--|
|0|1|2|3|4|
  ^

currSum = max(0+2,2)

maxSum = max(2,2)

currSum = 2

New array:

| 0 | 2 |  |  |  |  |
|:--|:--|:--|:---|:---|:--|

2°

i = 2

CurrSum = max(currSum+A[i-1], A[i-1])

| 2 | -3 | 5 | -1 | 4 |
|:--|:--|:---|:--|:--|
|0|1|2|3|4|
| | ^ |

currSum = max(2-3, 2)

maxSum = max(-1,2)

currSum = -1

New array:

| 0 | 2 | 2 |  |  |  |
|:--|:--|:--|:---|:---|:--|

3°

i = 3

currSum = max(currSum+A[i-1], A[i-1])

| 2 | -3 | 5 | -1 | 4 |
|:--|:--|:---|:--|:--|
|0|1|2|3|4|
| | |^|

currSum = max(-1 + 5, 5)

maxSum = max(4,5)

currSum = 5

New array:
 
| 0 | 2 | 2 | 5 |  |  |
|:--|:--|:--|:---|:---|:--|

4°

i = 4

currSum = max(currSum+A[i-1], A[i-1])

| 2 | -3 | 5 | -1 | 4 |
|:--|:--|:---|:--|:--|
|0|1|2|3|4|
| | | |^|

currSum = max(5-1,-1)

maxSum = max(4, 5)

currSum = 4

New array:
 
| 0 | 2 | 2 | 5 | 5 |  |
|:--|:--|:--|:---|:---|:--|

5°

i = 5 

currSum = max(currSum+A[i-1], A[i-1])

| 2 | -3 | 5 | -1 | 4 |
|:--|:--|:---|:--|:--|
|0|1|2|3|4|
| | | | |^|

currSum = max(4+4, 4)

maxSum = max(8, 4)

currSum = 8

New array:
 
| 0 | 2 | 2 | 5 | 5 | 8 |
|:--|:--|:--|:---|:---|:--|

Max sum = 8