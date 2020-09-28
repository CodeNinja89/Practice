#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkStraightLine(int (*coordinates)[2], int coordinatesSize, int *coordinatesColSize) {
	int i = 0, ret = 0;
	int x1, y1, vertical = 1;
	
	int y = *(*(coordinates) + 1);
	int x = *(*(coordinates));

	int x_fin = *(*(coordinates + coordinatesSize - 1));
	int y_fin = *(*(coordinates + coordinatesSize - 1) + 1);

	/* special case, vertical line */
	for(i = 0; i < coordinatesSize - 1; i++) {
		if(*(*(coordinates + i)) != *(*(coordinates + (i + 1)))) {
			vertical = 0;
			break;
		}
	}

	if(vertical == 1) {
		ret = 1;
	} else {

		float slope = ((float)((y_fin - y)) / (x_fin - x)) * 1.0f;
		printf("slope: %f\n", slope);

		float currSlope = 0.0;

		for(i = 1; i < coordinatesSize; i++) {
			currSlope = ((float)(y - *(*(coordinates + i) + 1)) / (x - *(*(coordinates + i)))) * 1.0f;
			printf("currSlope: %f\n", currSlope);
			if(currSlope != slope) {
				ret = 0;
				break;
			}
		}
	}
	return ret;
}

int main() {
	int arr[3][2] = {
		{1, 1},
		{2, 3},
		{3, 2},
	};
	checkStraightLine(arr, 3, NULL);
}