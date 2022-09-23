# Wrapper class for heapq
import heapq

class Heap: 
    def __init__(self, key=lambda x: x):
        self.compare_key = key
        self._heap_data = []
        self.counter = 0

    def push(self, item):
        heapq.heappush(self._heap_data, (self.compare_key(item), self.counter, item))
        self.counter += 1

    def pop(self):
        return heapq.heappop(self._heap_data)[2]
