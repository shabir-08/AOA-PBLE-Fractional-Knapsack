# Smart Delivery Planning – Fractional Knapsack

## PBLE 1 – Analysis of Algorithms

A menu-driven C implementation of the **Fractional Knapsack Problem** using the **Greedy Algorithm**.

## Problem Statement

A delivery vehicle has a fixed carrying capacity and a set of packages. Each package has a weight and an associated value/profit.

The objective is to maximize the total value carried by the vehicle. Unlike the 0/1 Knapsack problem, a fraction of a package can be selected.

## Objectives

* Understand the Greedy Method.
* Calculate the Value/Weight ratio for each package.
* Sort packages in decreasing order of Value/Weight ratio.
* Select complete packages whenever possible.
* Select a fraction of a package when the remaining capacity is insufficient.
* Calculate the maximum achievable value.
* Analyze the time complexity of the algorithm.

## Algorithm

1. Enter the package details.
2. Calculate the Value/Weight ratio for every package.
3. Sort packages in decreasing order of their ratio.
4. Start with the full vehicle capacity.
5. Select packages starting from the highest ratio.
6. If the complete package fits, select it completely.
7. Otherwise, select the required fraction of the package.
8. Continue until the vehicle capacity is full.
9. Display the selected packages, total weight used, and maximum value.

## Example

| Package | Value | Weight | Value/Weight |
| ------- | ----: | -----: | -----------: |
| 1       |    40 |      5 |         8.00 |
| 2       |    30 |     10 |         3.00 |
| 3       |    50 |      5 |        10.00 |
| 4       |    20 |      4 |         5.00 |

Vehicle Capacity:

```text
15
```

After sorting by Value/Weight ratio:

```text
Package 3 → Ratio = 10
Package 1 → Ratio = 8
Package 4 → Ratio = 5
Package 2 → Ratio = 3
```

The optimal selection is:

```text
Package 3 → 100%
Package 1 → 100%
Package 4 → 100%
Package 2 → 10%
```

Maximum value:

```text
113
```

Total weight used:

```text
15
```

## Menu

The program provides the following options:

1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

## Complexity Analysis

Let `n` be the number of packages.

* Ratio calculation: `O(n)`
* Sorting: `O(n²)` using Bubble Sort
* Package selection: `O(n)`

Therefore, the overall time complexity is:

```text
O(n²)
```

The space complexity is:

```text
O(n)
```

because an array is used to store package information.

## Concepts Used

* Greedy Algorithm
* Fractional Knapsack
* Sorting
* Arrays
* Structures
* Functions
* Time Complexity Analysis

## Technologies

* C
* GCC
* Git
* GitHub
