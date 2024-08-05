#include <bits/stdc++.h> 
int findAngle(int hour, int minute) {
    // Write your code here.
    // 12 places arrow of hour can point,
    // total 360 deg,360/12 small arrow moves 30deg/h

    // big arrow moves 60places one hour, 360/60  = 6deg/min
    double hours = (hour % 12 + minute/60.0) * 30;
    double minutes = minute * 6;
    double angle = abs(hours-minutes);
    if(angle>180){
        return 360-angle;
    }
    return angle;
} 
