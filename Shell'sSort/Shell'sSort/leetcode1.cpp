#include <iostream>
#include <vector>
#include <map>
#include <strstream>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
template<class T>
std::string convertToString(const T val)
{
    string s;
    std::strstream ss;
    ss << val;
    ss >> s;
    return s;
}
int maxPoints(std::vector<Point>& points) {
    int num = points.size();
    if (num == 0) return 0;
    if (num <= 2) return num;
    int max = 1;
    std::map<std::string, int> ma;
    for (std::vector<Point>::iterator i = points.begin(); i != points.end(); i++) {
        std::string tempStr = convertToString((*i).x) + ":" + convertToString((*i).y);
        if (ma.count(tempStr) == 0)
            ma[tempStr] = 1;
        else
            ma[tempStr]++;
    }
    for (std::map<std::string, int>::iterator i = ma.begin(); i != ma.end(); i++) {
        if (max < i->second)
            max = i->second;
    }
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            int sum_temp = 0;
            if (points[i].x == points[j].x && points[i].y == points[j].y)
                continue;
            for (int k = 0; k < num; k++) {
                int v1_x = points[k].x - points[i].x;
                int v1_y = points[k].y - points[i].y;
                int v2_x = points[k].x - points[j].x;
                int v2_y = points[k].y - points[j].y;
                if (v1_x * v2_y - v1_y * v2_x == 0) {
                    sum_temp++;
                }
            }
            if (sum_temp > max) {
                max = sum_temp;
            }
        }
    }
    return max;
}


