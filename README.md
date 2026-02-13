# Push Swap - Integer Sorting Algorithm

## Overview

**Push Swap** is an optimized C program that sorts integers using two stacks (A and B) with the minimum number of operations. This project is a 42 School algorithm challenge designed to teach efficient sorting and optimization techniques.

## Objective

Sort numbers in Stack A using two stacks with predefined operations:
- **Stack A**: Input and output stack
- **Stack B**: Auxiliary stack for sorting

The goal is to sort Stack A in ascending order using the minimum number of operations possible.

## Supported Operations

### Stack A Operations
- **sa**: Swap the first two elements of Stack A
- **pa**: Push the top element from Stack B to Stack A
- **ra**: Rotate Stack A upward (top element goes to bottom)
- **rra**: Rotate Stack A downward (bottom element goes to top)

### Stack B Operations
- **pb**: Push the top element from Stack A to Stack B
- **rb**: Rotate Stack B upward (top element goes to bottom)
- **rrb**: Rotate Stack B downward (bottom element goes to top)

## Sorting Algorithms

The program selects the optimal sorting algorithm based on input size:

| Element Count | Algorithm | Description |
|---|---|---|
| 2 | Easy Sort | 1 operation |
| 3 | Easy Sort | Max 2-3 operations |
| 4-5 | Easy Sort | Optimized sorting |
| 6+ | Chunk Sort / Hybrid | Optimized for input size |

### 1. Easy Sorting (2-5 Elements)
- Special move combinations for small inputs
- Guarantees minimum number of operations

### 2. Chunk Sort (6+ Elements)
- Divides Stack A into chunks
- Transfers chunks to Stack B with dynamic sizing
- Hybrid optimization method for sorting

### 3. Normalization
- Converts input numbers to rank values starting from 0
- Optimizes by normalizing the range of numbers

## Project Structure

```
push_swap/
├── Makefile                 # Compilation commands
├── includes/
│   └── push_swap.h         # Header file, definitions
└── sources/
    ├── main.c              # Program entry point
    ├── parsing.c           # Parse arguments
    ├── arg_checks.c        # Argument validation
    ├── error_handling.c    # Error management
    ├── easy_sorting.c      # Sorting for 2-5 elements
    ├── easy_sorting_utils.c # Helper functions
    ├── hard_sorting.c      # Sorting for 6+ elements
    ├── chunk_sort_stuff.c  # Chunk sort 1
    ├── chunk_sort_stuff_2.c # Chunk sort 2
    ├── radix_sort_stuff.c  # Radix sort implementation
    ├── normalize.c         # Normalization process
    ├── optimising.c        # Optimization functions
    ├── pushing.c           # Pa/Pb operations
    ├── swapping.c          # Swap operations
    ├── rotating.c          # Ra/Rb operations
    └── reverse_rotating.c  # Rra/Rrb operations
```

## Data Structures

### t_node (Node)
```c
typedef struct s_node
{
    int             value;      // Number value
    struct s_node   *next;      // Pointer to next node
}   t_node;
```

### t_stack (Stack)
```c
typedef struct s_stack
{
    t_node  *top;   // Top node
    int     size;   // Stack size
}   t_stack;
```

## Compilation and Execution

### Compilation
```bash
make
```

### Execution
```bash
./push_swap <numbers>
```

### Examples
```bash
./push_swap 3 2 1 0             # Outputs: Sorting operations
./push_swap 50 3 100 -42 5      # Positive and negative numbers
./push_swap 1 2 3 4 5           # Already sorted (no output)
```

### Testing with Checker
```bash
./push_swap 3 2 1 0 | ./checker_linux 3 2 1 0
```

## Make Commands

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Clean and recompile
```

## Input Validation

The program performs the following checks:

1. ✓ Accepts only numeric input
2. ✓ Validates integer range (INT_MIN - INT_MAX)
3. ✓ Rejects duplicate numbers
4. ✓ Rejects empty arguments

On error, outputs:
```
Error
```

## Optimization Strategies

1. **Dynamic Chunk Size Calculation**: Chunk size adapted to input scale
2. **Optimal Rotation Direction**: Selects up/down rotation for minimum steps
3. **Smart Move Elimination**: Removes redundant consecutive operations
4. **Hybrid Sorting**: Combines chunk sort + radix sort techniques

## Tested Environment

- **Operating System**: Linux/Unix
- **Compiler**: GCC (cc)
- **Standard**: C89/C90
- **Flags**: -Wall -Wextra -Werror (Strict compilation)

## Algorithm Complexity

- **Best Case**: O(n) - Already sorted
- **Average Case**: O(n log n) - Chunk sort
- **Worst Case**: O(n²) - Worst case sorting scenario

## Author

- **ztoptas** - 42 Kocaeli Student
- Email: ztoptas@student.42kocaeli.com

## License

This is a 42 School educational project.

---

## Interesting Details

- Pure **C** implementation (no external libraries)
- Uses **Linked List** data structure
- Follows **42 Norm** code style guidelines
- **Deterministic** - Same input always produces same output

## References

- 42 School Curriculum
- Stack and Linked List Algorithms
- Sorting Algorithms Theory
- Code Optimization Techniques
