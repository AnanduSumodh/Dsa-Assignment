# Max Heap vs Linear Search

## Assignment

A university wants to identify the highest student score from:

`78, 92, 65, 88, 95, 72, 84, 90`

The program:

1. Implements a Max Heap and inserts all scores.
2. Records the heap after every insertion.
3. Finds the maximum using a Max Heap.
4. Finds the maximum using Linear Search.
5. Counts comparisons.
6. Compares the two approaches.

## Files

- `main.c` - Source code
- `input.txt` - Input data
- `output.txt` - Program output
- `trace_table.txt` - Max Heap insertion trace
- `complexity_analysis.txt` - Complexity analysis
- `comparison_table.txt` - Method comparison
- `conclusion.txt` - Final conclusion

## Results

Maximum score using Max Heap: **95**

Maximum score using Linear Search: **95**

Max Heap comparisons while building the heap: **12**

Linear Search comparisons: **7**

## Conclusion

For continuously maintaining and retrieving the highest score as new
scores are inserted, a Max Heap provides direct access to the maximum
at the root and supports O(log n) insertion.
