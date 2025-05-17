# Rush01 — What I Learned

This file summarizes the key concepts I learned and understood while implementing the `Rush01` project from the 1337 Piscine.

---

## 🧠 Recursion and Backtracking

### 1. Recursion and `for` loops together

- In the `solve()` function, a `for` loop is used to try placing values (1 to 4) in a grid cell.
- For each value, the function:
  1. Places the value in the grid.
  2. Calls itself recursively to handle the next cell.
  3. If the recursive call fails, it **backtracks** by undoing the placement.
- When the recursive call returns, the `for` loop continues with the next value, if any.

> ✅ I learned that the **code after the recursive call still runs when returning**, including the rest of the `for` loop if it hasn't finished.

---

### 2. Recursive call per cell

- Each recursive call is responsible for exactly **one cell** in the grid.
- That’s why I used `row` and `col` as **arguments**, and never modified them directly.
- Instead, I computed `next_row` and `next_col` to move forward.

> 💡 This ensures each function call is clean and isolated — a very important property in recursion.

---

### 3. Backtracking as a concept

Backtracking consists of 3 parts:
1. A `for` loop that tries all options.
2. A recursive call to go deeper.
3. A rollback or **undo step** if the path fails.

Example:

```c
grid[row][col] = num;        // try placing a number
if (solve(...)) return 1;    // recurse deeper
grid[row][col] = 0;          // undo if needed (backtrack)

