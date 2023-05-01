import solution

def test_solution():
    s = solution.Solution()

    test_cases = [
        (5, [[0, 1], [0, 2], [0, 3], [1, 4]], True),
        (5, [[0,1],[1,2],[2,3],[1,3],[1,4]], False)
        # Add more test cases here
    ]

    for i, (n, edges, expected_output) in enumerate(test_cases):
        result = s.validTree(n, edges)
        assert result == expected_output, f"Test case {i + 1} failed: expected {expected_output}, got {result}"
        print(f"Test case {i + 1} passed.")

if __name__ == "__main__":
    test_solution()
