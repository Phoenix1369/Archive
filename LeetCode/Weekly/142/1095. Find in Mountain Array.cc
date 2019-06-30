/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int N = mountainArr.length();
        int mode = ternary_search(0, N-1, mountainArr);

        int pos = binary_search(0, mode, target, mountainArr);
        if (mountainArr.get(pos) == target) {
            return pos;
        }
        pos = reverse_binary_search(mode, N-1, target, mountainArr);
        if (mountainArr.get(pos) == target) {
            return pos;
        }
        return -1;
    }

private:
    int binary_search(int lo, int hi, int val, MountainArray& ma) {
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ma.get(mid) < val) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    int reverse_binary_search(int lo, int hi, int val, MountainArray& ma) {
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ma.get(mid) > val) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    int ternary_search(int lo, int hi, MountainArray& ma) {
        while (lo < hi) {
            int m1 = (lo + lo + hi) / 3;
            int m2 = (lo + hi + hi + 2) / 3;
            int f1 = ma.get(m1);
            int f2 = ma.get(m2);
            if (f1 < f2) {
                lo = m1 + 1;
            } else if (f1 > f2) {
                hi = m2 - 1;
            } else {
                lo = m1 + 1;
                hi = m2 - 1;
            }
        }
        return lo;
    }
};
