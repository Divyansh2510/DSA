#include<iostream>
#include<math.h>
using namespace std;

 double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double diff = fabs(hourAngle - minuteAngle);

        return min(diff, 360 - diff);
    }
    
int main(){
	int h=12,min=30;
	cout<<angleClock(h,min);
	return 0;
}
