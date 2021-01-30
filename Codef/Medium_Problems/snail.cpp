#include <iostream>
#include <string>

using namespace std;

int main() {
    double h, u, d, f;
    while (scanf("%lf %lf %lf %lf", &h, &u, &d, &f), (h)) {
        int dayNum = 1;
        double heightAfterSliding = 0;
        while (true) {
            double initHeight = heightAfterSliding;
            double climb = u - (f/100) * u * (dayNum-1);
            if (climb < 0) {
                climb = 0;
            }
            double heightAfterClimbing = initHeight + climb;
            heightAfterSliding = heightAfterClimbing - d;

            if (heightAfterClimbing > h) {
                cout << "success on day " << to_string(dayNum) << endl;
                break;
            }
            if (heightAfterSliding < 0) {
                cout << "failure on day " << to_string(dayNum) << endl;
                break;
            }
            dayNum++;
        }
    }
    return 0;
}
