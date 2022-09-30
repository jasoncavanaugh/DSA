class Bit: 
    # BIT uses 1-indexing
    def __init__(self, input_nums):
        self.nums = [0 for i in range(len(input_nums) + 1)]
        for i in range(1, len(self.nums)):
            self.update(i, input_nums[i - 1])

        self._examine()

    def prefix_sum(self, idx):
        cur_sum = 0
        while idx > 0:
            cur_sum += self.nums[idx]
            idx -= idx & -idx
        return cur_sum


    def update(self, idx, incr):
        while idx < len(self.nums):
            self.nums[idx] += incr
            idx += idx & -idx

    def get_val(self, idx):
        return self.prefix_sum(idx) - self.prefix_sum(idx - 1)

    def _examine(self):
        print(self.nums)


arr = [3, 4, 6, 7, 9, 2, 1, 0, 2, 4, 8, 11, 16, 5, 21, 2, 8, 7]
bit = Bit(arr)
tests = [["update", 1, 3], ["update", 10, 30], ["prefix_sum", 11], ["prefix_sum", 5]] 
for t in tests:
    match t[0]:
        case "update":
            print(f"Update: idx = {t[1]}, incr = {t[2]}")
            bit.update(t[1], t[2])
        case "prefix_sum":
            print(f"Prefix sum: idx = {t[1]}, {bit.prefix_sum(t[1])}")
    bit._examine()
