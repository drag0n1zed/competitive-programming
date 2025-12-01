# Maximum Distance

* **time limit per test:** 4 seconds
* **memory limit per test:** 256 megabytes

You are given $N$ ($3 \le N \le 5000$) integer points on the coordinate plane. Find the square of the maximum Euclidean distance (aka length of the straight line) between any two of the points.

## Input

The first line contains an integer $N$.
The second line contains $N$ integers, the x-coordinates of the points: $x_1, x_2, \dots, x_N$ ($-1000 \le x_i \le 1000$).
The third line contains $N$ integers, the y-coordinates of the points: $y_1, y_2, \dots, y_N$ ($-1000 \le y_i \le 1000$).

## Output

Print one integer, the square of the maximum Euclidean distance between any two of the points.

## Example

### Input

```
3
321 -15 -525
404 373 990
```

### Output

```
1059112
```