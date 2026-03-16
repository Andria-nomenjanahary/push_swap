*This project has been created as part of the 42 curriculum by ainaradan, yvoandri.*

# Push_swap

## Description

**Push_swap** is a challenging algorithm project from the 42 School curriculum. The goal is to sort **stack a** using **stack b** with a limited set of operations, outputting only the **"history"** of operations (not the sorted stack itself) that transforms the initial random stack into a sorted ascending stack.

The challenge lies in optimizing the number of operations: fewer instructions means better performance. This implementation explores multiple sorting algorithms and introduces an **adaptive strategy** that selects the best algorithm based on the input's disorder level.

### Core Constraints
- Only two stacks (a and b) are available
- Stack a initially contains random integers (no duplicates)
- Stack b starts empty
- Goal: Sort stack a in ascending order (smallest at top) using minimal operations

---

## Project Structure

```
push_swap/
├── libft/                  # 42's standard C library
│
├── push_swap.h             # Main header file
├── main.c                  # Entry point and mode selection
├── main_utils.c            # Disorder calculation and algorithm execution
│
├── command.h               # Operation function declarations
├── push.c                  # Push operations (pa, pb)
├── swap.c                  # Swap operations (sa, sb, ss)
├── rotation.c              # Rotate operations (ra, rb, rr)
├── reverse_rotation.c      # Reverse rotate operations (rra, rrb, rrr)
│
├── simple_algo.c           # O(n²) Min/Max Extraction algorithm
│
├── medium_algo.c           # O(n√n) Chunk-based sorting main logic
├── medium_algo.h           # Medium algorithm header
├── medium_algo_utils.c     # Small stack sorting (2-5 elements)
├── medium_chunk_sort.c     # √n chunk sort implementation
├── ft_medium_algo_utils1.c # Stack utilities (count, min, max, position)
│
├── complex_algo.c          # O(n log n) Radix sort main logic
├── complex_algo.h          # Complex algorithm header
├── complex_algo_utils.c    # Quick sort and index assignment
├── complex_sort.c          # Small stack sorting & radix LSD sort
│
├── adaptive_algo.c         # Dynamic algorithm selection
│
├── parsing.c               # String parsing and number extraction
├── parsing_skip.c          # Option-aware parsing
├── parsing_utils.c         # Argument parsing utilities
├── number_parser.c         # Number validation and counting
├── options_parser.c        # Command-line option processing
├── options_validator.c     # Option validation logic
├── validation.c            # Input validation (flags, numbers)
│
├── general_utils.c         # General utilities (error, free, is_number)
│
├── calcul_end_index.c      # Index calculation for chunks
│
├── hashset.c               # Hash set implementation for duplicate detection
├── hashset.h               # Hash set header
├── hashset_utils.c         # Duplicate checking and sorted verification
│
├── bench.h                 # Benchmarking structure and functions
├── bench.c                 # Main benchmarking logic
├── bench_utils.c           # Benchmark initialization and statistics
├── bench_swap.c            # Swap operation counters
├── bench_rotation.c        # Rotation operation counters
├── bench_reverse_rotation.c# Reverse rotation counters
├── bench_push.c            # Push operation counters
│
├── checker.h               # Checker program header
├── checker.c               # Checker main program
├── checker_push.c          # Checker push operations
├── checker_swap.c          # Checker swap operations
├── checker_rotation.c      # Checker rotation operations
├── checker_rotate_reverse.c# Checker reverse rotation
├── checker_read_line.c     # Line reading for checker
├── checker_utils.c         # Checker utilities
├── checker_parser.c        # Checker argument parsing
├── move_checker.c          # Command dispatcher for checker
├── stack_in_order.c        # Result verification
│
└── Makefile
```

---

## Compilation

### 1 - Clone the Repository

```bash
git clone <repository-url> push_swap
cd push_swap
```

### 2 - Compile the Project

```bash
make
```

This generates two executables:
- `push_swap`: The main sorting program
- `checker`: The bonus verification program

### 3 - Makefile Rules

| Command | Description |
|---------|-------------|
| `make` | Compile both push_swap and checker |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executables |
| `make re` | Full rebuild |

---

## Usage Examples

### 1 - Basic Usage
```bash
./push_swap "4 67 3 87 23"
./push_swap 4 67 3 87 23
```

### 2 - Algorithm Selection Flags

The program implements 4 sorting strategies with different complexity classes:

| Flag | Algorithm | Complexity | Best For |
|------|-----------|------------|----------|
| `--simple` | Min/Max Extraction | O(n²) | Small stacks, nearly sorted data |
| `--medium` | √n Chunk Sorting | O(n√n) | Medium-sized stacks |
| `--complex` | Radix Sort (Binary) | O(n log n) | Large stacks, highly disordered data |
| `--adaptive` | Dynamic Selection | Varies | Automatically selects based on disorder metric |

```bash
./push_swap 45 12 89 3
./push_swap --simple "78 92 56 26"
./push_swap --medium 78 92 56 26
./push_swap --complex "100 5 78 2 99"
./push_swap --adaptive 45 12 89 3
```

### 3 - Benchmark Mode

The `--bench` flag provides detailed statistics including operation counts, disorder percentage, and strategy used:

```bash
./push_swap --bench "45 12 89 3 67"
# or
./push_swap "45 12 89 3 67" --bench
```

Generate random numbers and benchmark:
```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt)
```

Save benchmark results to a file:
```bash
./push_swap --bench $(cat args.txt) 2> bench.txt
cat bench.txt
```

---

## Available Operations

| Operation | Description |
|-----------|-------------|
| **sa** | Swap first two elements of stack a |
| **sb** | Swap first two elements of stack b |
| **ss** | sa and sb simultaneously |
| **pa** | Push top element from b to a |
| **pb** | Push top element from a to b |
| **ra** | Rotate stack a up (first becomes last) |
| **rb** | Rotate stack b up (first becomes last) |
| **rr** | ra and rb simultaneously |
| **rra** | Reverse rotate stack a down (last becomes first) |
| **rrb** | Reverse rotate stack b down (last becomes first) |
| **rrr** | rra and rrb simultaneously |

---

## Algorithm Details and Justifications

### 1. Simple Algorithm — O(n²) — Min/Max Extraction

**Approach**: Find the minimum value in stack a, rotate it to the top, then push to stack b. Repeat until stack a has 3 or fewer elements, sort those manually, then push everything back.

**Justification**: 
- Optimal for very small stacks (≤ 5 elements)
- Efficient when data is nearly sorted (low disorder < 0.2)
- Minimal overhead, simple to implement and verify
- For n=3, uses at most 3 operations; for n=5, at most 12 operations

**Implementation**: `simple_algo.c` uses hardcoded logic for 2-3 elements and min-extraction for larger small stacks.

---

### 2. Medium Algorithm — O(n√n) — Chunk-Based Sorting

**Approach**: 
1. Create buckets based on value ranges (approximately √n buckets)
2. Push elements from stack a to b if they belong to the current active bucket
3. Within stack b, maintain rough order by rotating smaller values to the bottom
4. Once all buckets are processed, push back to a by finding max in b and rotating to top

**Justification**:
- Balances between simple extraction and complex radix sort
- Chunk size √n provides optimal trade-off between push operations and rotation costs
- Better than O(n²) for medium disorder (0.2 ≤ disorder < 0.5)
- Typical performance: ~400-800 operations for 100 elements

**Implementation**: `medium_chunk_sort.c` uses dynamic bucket sizing and strategic chunk selection.

---

### 3. Complex Algorithm — O(n log n) — Binary Radix Sort (LSD)

**Approach**:
1. **Normalization**: Assign indices 0 to n-1 based on sorted order using quick sort (handles negative numbers and reduces range)
2. **Bitwise Processing**: For each bit position from LSB to MSB:
   - If bit is 1: rotate a (keep in a)
   - If bit is 0: push to b
   - After processing all elements, push b back to a
3. Repeat for all bits needed to represent largest index

**Justification**:
- Optimal for large datasets and high disorder (≥ 0.5)
- Guaranteed O(n log n) complexity where log n is number of bits
- Stable and predictable operation count regardless of input distribution
- Typical performance: ~600-1100 operations for 100 elements, ~5000-7000 for 500 elements 

**Key Insight**: Using indices instead of raw values allows binary representation sorting. Stack a acts as "box 1", stack b as "box 0" in traditional radix sort.

**Implementation**: `complex_algo.c` uses quick sort for initial normalization, then processes bits iteratively in `complex_sort.c`.

---

### 4. Adaptive Algorithm — Dynamic Selection

**Approach**: Calculate a **disorder metric** (inversion count / total pairs) and select algorithm based on threshold:
- **Disorder < 0.2**: Use Simple (O(n²))
- **0.2 ≤ Disorder < 0.5**: Use Medium (O(n√n))
- **Disorder ≥ 0.5**: Use Complex (O(n log n))

**Justification**:
- No single algorithm is optimal for all inputs 
- Disorder metric accurately predicts which strategy will use fewer operations
- Provides best average performance across diverse inputs
- Automatically adapts without user intervention
