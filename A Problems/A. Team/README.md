# Problem: Counting Valid Attempts



## Problem Statement

The problem requires determining the number of valid attempts from a set of questions. Each question is represented as a list of integers (either 0 or 1). A valid attempt is defined as a question where the sum of the integers equals **2**.

### problem link : https://codeforces.com/problemset/problem/231/A

---

## Input Format

1. An integer, **n**, representing the number of questions.
2. Each of the following **n** lines contains a space-separated list of integers (0 or 1) representing a question.

---

## Output Format

The output is a single integer indicating the number of valid attempts, i.e., questions where the sum of integers equals **2**.

---

## Explanation of Logic

### Function: `valid`
- **Purpose**: This function processes a list of questions and determines how many are valid.
- **Logic**:
  1. Iterate through each question (a list of integers).
  2. Compute the cumulative sum of integers for each question.
  3. If the sum equals **2**, mark the question as valid and move to the next one.
  4. Return the total count of valid questions.

### Input Parsing
- The program first reads the number of questions.
- For each question, it reads a line of input, splits it into integers, and stores it as a list in a 2D vector or list structure.

### Main Function Logic
1. Parse the number of questions and the list of integers for each question.
2. Pass the list of questions to the `valid` function.
3. Print the result, which is the count of valid attempts.

---

## Key Insights

1. **Efficient Validation**: As soon as the sum equals **2** for a question, the function skips processing the rest of the integers in that question (using a break).
2. **Input Parsing**: The use of string manipulation ensures that the program can handle space-separated integers cleanly.

---

## Complexity Analysis

- **Time Complexity**:
  - Parsing the input takes \( O(n \cdot m) \), where \( n \) is the number of questions and \( m \) is the average length of a question.
  - The validation process also takes \( O(n \cdot m) \) in the worst case.
  - Overall complexity: \( O(n \cdot m) \).

- **Space Complexity**:
  - The program uses \( O(n \cdot m) \) space to store the questions in a 2D list or vector.

---

## Example Walkthrough

### Example 1

**Input**:
3 1 0 1 1 1 0 0 0 0



**Explanation**:
1. Question 1: `[1, 0, 1]` → Sum = 2 → Valid
2. Question 2: `[1, 1, 0]` → Sum = 2 → Valid
3. Question 3: `[0, 0, 0]` → Sum = 0 → Not valid

**Output**: `2`

---

### Example 2

**Input**:
2 0 1 0 1 0 0


**Explanation**:
1. Question 1: `[0, 1, 0]` → Sum = 1 → Not valid
2. Question 2: `[1, 0, 0]` → Sum = 1 → Not valid

**Output**: `0`

---

## Summary

The problem focuses on efficiently identifying valid questions where the sum equals **2**. Input parsing and the validation process are structured to ensure clarity and optimal performance. The program outputs the total count of valid attempts based on the conditions provided.
