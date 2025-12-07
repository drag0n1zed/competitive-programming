The layout of Farmer John's farm is quite peculiar, with a large circular road running around the perimeter of the main field on which his cows graze during the day. Every morning, the cows cross this road on their way towards the field, and every evening they all cross again as they leave the field and return to the barn.

As we know, cows are creatures of habit, and they each cross the road the same way every day. Each cow crosses into the field at a different point from where she crosses out of the field, and all of these crossing points are distinct from each-other. Farmer John owns exactly 26 cows, which he has lazily named A through Z (he is not sure what he will do if he ever acquires a 27th cow...), so there are precisely 52 crossing points around the road. Farmer John records these crossing points concisely by scanning around the circle clockwise, writing down the name of the cow for each crossing point, ultimately forming a string with 52 characters in which each letter of the alphabet appears exactly twice. He does not record which crossing points are entry points and which are exit points.

Looking at his map of crossing points, Farmer John is curious how many times various pairs of cows might cross paths during the day. He calls a pair of cows (a,b) a "crossing" pair if cow a's path from entry to exit must cross cow b's path from entry to exit. This occurs if and only if the four crossing points for the two cows appear in an alternating order around the circle (e.g., a, b, a, b).

Please help Farmer John count the total number of crossing pairs.

### INPUT FORMAT (file circlecross.in):

The input consists of a single line containing a string of 52 upper-case characters. Each letter of the alphabet ('A' through 'Z') appears exactly twice.

### OUTPUT FORMAT (file circlecross.out):

Please print a single integer representing the total number of crossing pairs.

### SAMPLE INPUT:
```
ABCCABDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ
```

### SAMPLE OUTPUT:
```
1
```

### EXPLANATION:

In the sample case, the two crossings for cow A are at indices 0 and 6. The two crossings for cow B are at indices 1 and 7. If we read clockwise along the string (representing the circle), the points appear in the order A, B, A, B. This interleaving means their paths must cross, regardless of which points are entry or exit. No other pair of cows has their crossing points interleaved in this way. For example, cow C's points are adjacent at indices 2 and 3, so its path cannot cross any other. Therefore, only the pair (A, B) is a crossing pair, and the answer is 1.

### PROBLEM CREDITS:

Brian Dean