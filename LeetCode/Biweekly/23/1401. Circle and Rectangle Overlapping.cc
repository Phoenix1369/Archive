class Solution {
public:
    bool checkOverlap(
            int radius, int x_center, int y_center,
            int x1, int y1, int x2, int y2
    ) {
        int dx = max(max(x1 - x_center, x_center - x2), 0);
        int dy = max(max(y1 - y_center, y_center - y2), 0);
        return (dx * dx) + (dy * dy) <= (radius * radius);
    }   // X and Y dimensions are independent
};
