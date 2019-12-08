#include "Call.h"

directions getCallDir(Call& call) {

	if(call.direction != indiff)
		return call.direction;
		
	if(call.TargetFloor - call.FromFloor > 0) {
		call.direction = up;
	} else {
		call.direction = down;
	}

	return call.direction;

}