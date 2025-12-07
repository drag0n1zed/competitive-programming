# Gymnastics

### Problem Description

> In order to improve their physical fitness, the cows have taken up gymnastics! Farmer John designates his favorite cow Bessie to coach the `N` other cows and to assess their progress as they learn various gymnastic skills.
>
> In each of `K` practice sessions (`1 ≤ K ≤ 10`), Bessie ranks the `N` cows according to their performance (`1 ≤ N ≤ 20`). Afterward, she is curious about the consistency in these rankings. A pair of two distinct cows is **consistent** if one cow did better than the other one in every practice session.
>
> Help Bessie compute the total number of consistent pairs.

### Input Format (file `gymnastics.in`)

The first line of the input file contains two positive integers, `K` and `N`.

The next `K` lines will each contain the integers `1…N` in some order, indicating the rankings of the cows (cows are identified by the numbers `1…N`). If cow `A` appears before cow `B` in one of these lines, that means cow `A` did better than cow `B`.

**Constraints:**
*   `1 ≤ K ≤ 10`
*   `1 ≤ N ≤ 20`

### Output Format (file `gymnastics.out`)

Output a single integer on a single line, representing the total number of consistent pairs.

### Sample Input

```
3 4
4 1 2 3
4 1 3 2
4 2 1 3
```

### Sample Output

```
4
```

### Explanation

The consistent pairs of cows are (4, 1), (4, 2), (4, 3), and (1, 3).
*   Cow 4 is better than cow 1 in all 3 sessions.
*   Cow 4 is better than cow 2 in all 3 sessions.
*   Cow 4 is better than cow 3 in all 3 sessions.
*   Cow 1 is better than cow 3 in all 3 sessions.

No other pair is consistent. For example, for the pair (1, 2), cow 1 is better in the first two sessions but cow 2 is better in the third.

### Problem Credits

Nick Wu