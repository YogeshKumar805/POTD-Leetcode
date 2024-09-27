class Segment:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.booked = 0
        self.left = None
        self.right = None
        self.lazy = 0

class MyCalendarTwo:
    def __init__(self):
        self.min_start = 0
        self.max_end = 10**9
        self.root = Segment(self.min_start, self.max_end)

    def book(self, start, end) -> bool:
        if self._max_bookings(self.root, start, end - 1) < 2:
            self._update(self.root, start, end - 1, 1)
            return True
        return False

    def _max_bookings(self, segment, query_start, query_end):
        if query_start > segment.end or query_end < segment.start:
            return 0
        if query_start <= segment.start and segment.end <= query_end:
            return segment.booked + segment.lazy
        self._push_down(segment)
        mid = (segment.start + segment.end) // 2
        left_max = self._max_bookings(segment.left or Segment(segment.start, mid), query_start, query_end)
        right_max = self._max_bookings(segment.right or Segment(mid + 1, segment.end), query_start, query_end)
        return max(left_max, right_max)

    def _update(self, segment, update_start, update_end, val):
        if update_start > segment.end or update_end < segment.start:
            return
        if update_start <= segment.start and segment.end <= update_end:
            segment.lazy += val
            return
        self._push_down(segment)
        mid = (segment.start + segment.end) // 2
        if not segment.left:
            segment.left = Segment(segment.start, mid)
        if not segment.right:
            segment.right = Segment(mid + 1, segment.end)
        self._update(segment.left, update_start, update_end, val)
        self._update(segment.right, update_start, update_end, val)
        segment.booked = max(segment.left.booked + segment.left.lazy, segment.right.booked + segment.right.lazy)

    def _push_down(self, segment):
        if segment.lazy:
            if not segment.left:
                segment.left = Segment(segment.start, (segment.start + segment.end) // 2)
            if not segment.right:
                segment.right = Segment((segment.start + segment.end) // 2 + 1, segment.end)
            segment.left.lazy += segment.lazy
            segment.right.lazy += segment.lazy
            segment.booked += segment.lazy
            segment.lazy = 0
