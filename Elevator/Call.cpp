#include "Call.h"

directions getCallDir(Call call) {

	if(call.direction != indiff)
		return call.direction;

	if(call.TargetFloor - call.FromFloor > 0) {
		return up;
	} else {
		return down;
	}

}