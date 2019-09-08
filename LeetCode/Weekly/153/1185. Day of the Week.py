from datetime import datetime
WEEK = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        return WEEK[datetime(year, month, day).weekday()]
