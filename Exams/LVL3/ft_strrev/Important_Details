# 📚 String Storage in C

This document explains where strings are stored in C depending on how they are declared, whether they are modifiable, and the behavior of each storage method.

---

## 🧵 Declaration Types

| Declaration Type   | Example                  | Memory Storage | Modifiable | Notes                                 |
|--------------------|--------------------------|----------------|------------|---------------------------------------|
| **String Literal** | `char *s = "abc";`       | `.rodata`      | ❌ No       | Shared and read-only                  |
| **Character Array**| `char s[] = "abc";`      | Stack          | ✅ Yes      | Local, modifiable copy                |
| **Heap Allocation**| `char *s = malloc(...);` | Heap           | ✅ Yes      | Must be freed manually                |

---

## 🧠 Memory Segment Summary

### 🔸 `.rodata` (Read-Only Data)
- Stores **string literals**.
- Attempting to modify data here leads to **undefined behavior** (often crashes).

### 🔸 Stack
- Used for **local variables**, including arrays like `char s[]`.
- Automatically freed when the function returns.
- Fast access, but limited in size.

### 🔸 Heap
- Used for **dynamic memory allocation** (`malloc`, `calloc`, etc.).
- Data persists until explicitly freed using `free()`.
- Good for large or long-lived data.

---

## ✅ Best Practices

- Use **character arrays** if you need to modify the string.
- Use the **heap** for dynamic or large strings.
- Never modify **string literals** — always treat them as read-only.
- Always ensure your strings are **null-terminated** (`'\0'`).

---

## 📌 Example

```c
char *literal = "hello";       // read-only
char array[] = "hello";        // modifiable
char *heap_str = malloc(6);    // modifiable (don't forget to free)
strcpy(heap_str, "hello");

