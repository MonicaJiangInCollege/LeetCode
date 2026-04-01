class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int hour = 0; hour < 12; ++hour) {
            for (int minute = 0; minute < 60; ++minute) {
                // 计算 hour 中 1 的个数
                int hourBits = 0;
                int h = hour;
                while (h) {
                    hourBits += h & 1;
                    h >>= 1;
                }
                // 计算 minute 中 1 的个数
                int minuteBits = 0;
                int m = minute;
                while (m) {
                    minuteBits += m & 1;
                    m >>= 1;
                }
                if (hourBits + minuteBits == turnedOn) {
                    // 构建时间字符串
                    string time = to_string(hour) + ":";
                    if (minute < 10) {
                        time += "0";
                    }
                    time += to_string(minute);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};