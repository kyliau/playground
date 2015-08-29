// https://leetcode.com/problems/rectangle-area/
// Find the total area covered by two rectilinear rectangles in a 2D plane.
// Each rectangle is defined by its bottom left corner and top right corner.

struct Rectangle {
    int x, y, width, height;
    int area() {
        return width * height;
    }
};

class Solution {
public:
    bool isIntersect(const Rectangle& R, const Rectangle& S) {
        return R.x <= S.x + S.width  && R.x + R.width  >= S.x &&
               R.y <= S.y + S.height && R.y + R.height >= S.y;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        Rectangle R = {
            A, B, C - A, D - B
        };
        Rectangle S = {
            E, F, G - E, H - F
        };
        int totalArea = R.area() + S.area();
        if (isIntersect(R, S)) {
            Rectangle intersection = {
                max(R.x, S.x),
                max(R.y, S.y),
                min(R.x + R.width , S.x + S.width)  - max(R.x, S.x),
                min(R.y + R.height, S.y + S.height) - max(R.y, S.y)
            };
            return totalArea - intersection.area();
        }
        return totalArea;
    }
};
