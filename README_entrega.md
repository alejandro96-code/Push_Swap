This project has been created as part of the 42 curriculum by alejanr2

# Description

This project sorts a list of integers using two stacks (A and B) and a limited
set of operations, aiming for the smallest number of moves.

## Allowed operations

| Operation | Description |
|-----------|-------------|
| `sa` | swap a: swap the first two elements of A |
| `sb` | swap b: swap the first two elements of B |
| `pa` | push a: move the top of B to A |
| `pb` | push b: move the top of A to B |
| `ra` | rotate a: move the top of A to the bottom |
| `rb` | rotate b: move the top of B to the bottom |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate a: move the bottom of A to the top |
| `rrb` | reverse rotate b: move the bottom of B to the top |
| `rrr` | `rra` and `rrb` at the same time |

`ss` is also allowed, but we did not implement it because we did not use it.

# Instructions

```bash
make
./push_swap 3 2 1
```

To verify with the checker:

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

To count moves:

```bash
ARG="3 2 1"; ./push_swap $ARG | wc -l
```

---

# How it works

1) **Parsing and validation**
	- Validates that all inputs are numbers, there are no duplicates, and there is no overflow (beyond INT range).
	- If the input is already sorted, it stops.

2) **Small cases (2 to 5 numbers)**
	- If there are 2 numbers and they are unsorted: use `sa`.
	- If there are 3 numbers, use `sort_three`.
	- If there are 4 or 5 numbers, use `sort_five` and `sort_three` when needed.
	- If there are more than 6 numbers, use the Turk algorithm.

3) **Large cases (Turk algorithm)**
	- Assign an index to each value according to its sorted order. The smallest gets index 0, the next 1, and so on.
	- Use `push_to_b` to push all numbers to B except 3. If size <= 100, use chunk size 15; otherwise use chunk size 30.
	- Compute the cost to insert each element from B into its correct position in A. Always pick the cheapest and apply combined rotations (`rr`/`rrr`) when possible.
	- Rotate A at the end to bring the minimum to the top.

## Example sort_three

Input:

```
STACK A: [2 3 1]
STACK B: []
```
Function:
1) `rra` moves 1 to the top and the stack becomes `1 2 3`.

Possible output:

### 1)
```
STACK A: [1 2 3]
STACK B: []
```

## Example sort_five

Input:
```
STACK A: [3 5 1 4 2]
STACK B: []
```

Function:
 1) Push the two smallest to B using `pb`.
 2) Sort the remaining 3 with `sort_three`.
 3) Bring them back with `pa pa`.

Possible output:

### 1)
```
STACK A: [3 5 4 ]
STACK B: [1 2]

```

### 2)
```
STACK A: [3 4 5 ]
STACK B: [1 2]
```

### 3)
```
STACK A: [1 2 3 4 5 ]
STACK B: []
```

## Large example (Turk algorithm)

Input:

Input (20 numbers):

```
42 7 19 3 25 14 2 30 11 5 27 1 9 21 4 16 8 24 6 18
```

### 1) Indexing
Values are sorted and indices 0..19 are assigned:

```
1->0 2->1 3->2 4->3 5->4 6->5 7->6 8->7 9->8 11->9
14->10 16->11 18->12 19->13 21->14 24->15 25->16 27->17 30->18 42->19
```

Each node now stores its `index`.

### 2) Push to B by chunks
In `push_swap_turco` for size <= 100 we use `chunk = 15`.
The `cont` variable starts at 0 and we push to B like this:

- If `index <= cont`: `pb` and then `rb` (to keep very low indices lower in B).
- If `index <= cont + chunk`: just `pb`.
- Otherwise: `ra` (rotate A to find another candidate).

With 20 numbers, the first effective block is indices 0..15.
That leaves most values in B and 3 nodes in A.

```
Stack A: [6, 18, 42]
Stack B: [24, 21, 27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8]
```

### 3) Sort the 3 remaining in A
Use `sort_three` to order those 3 elements in A.

### 4) Compute costs for each node in B
For each node in B we compute:

- `target_pos` in A: where it should be inserted to keep order.
- `cost_a`: rotations needed in A to reach `target_pos`.
- `cost_b`: rotations needed in B to bring that node to the top.

If both costs have the same sign, they can be combined with `rr` or `rrr`.
That reduces moves.

How it could look:

```
Stack A: [6, 18, 42]
Stack B: [24, 21, 27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8]
```

```
Stack A: [42, 6, 18]
Stack B: [21, 27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24]
```

```
Stack A: [42, 6, 18, 21]
Stack B: [27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24]
```

```
Stack A: [42, 6, 18, 21, 27]
Stack B: [11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24]
```

```
Stack A: [42, 6, 18, 21, 27]
Stack B: [30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11]
```

```
Stack A: [30, 42, 6, 18, 21, 27]
Stack B: [14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11]
```

```
Stack A: [30, 42, 6, 18, 21, 27]
Stack B: [25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```

 - Here we know the next number is 25 and it is cheaper to move 27 to the top and then insert 25 at the top.

```
Stack A: [27, 30, 42, 6, 18, 21]
Stack B: [25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]

Stack A: [25, 27, 30, 42, 6, 18, 21]
Stack B: [19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```
And with the next one (19) we do the same.

```
Stack A: [21, 25, 27, 30, 42, 6, 18]
Stack B: [19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]

Stack A: [19, 21, 25, 27, 30, 42, 6, 18]
Stack B: [7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```

Now, since we know that the index of the last number is just before the first number in the row, we must
move it to the top before continuing.

```
Stack A: [18, 19, 21, 25, 27, 30, 42, 6]
Stack B: [7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```

Repeat until B is empty.

### 6) Final rotation

It is possible that when the loop ends we get something like this:

```
Stack A: [2, 3, 4, 5, 6, 7, 8, 9, 11, 14, 16, 18, 19, 21, 24, 25, 27, 30, 42, 1]
Stack B; []
```
We use `final_rotate` to bring the minimum index to the top.

Result: A sorted from smallest to largest, B empty.

```
Stack A: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 14, 16, 18, 19, 21, 24, 25, 27, 30, 42]
Stack B; []
```
---


# Resources

- 42 subject notes for `push_swap` (requirements and allowed operations).
- C manuals: `man 3 malloc`, `man 3 free`, `man 2 read`, `man 2 write`.
- Reminder of `int` limits in C (INT_MIN / INT_MAX).
- AI used to explain different algorithms, selecting the "Turk algorithm" and learning the general idea of chunks and costs.
- Comparison of sorting algorithms (https://www.freecodecamp.org/espanol/news/algoritmos-de-ordenacion-explicados-con-ejemplos-en-javascript-python-java-y-c/)