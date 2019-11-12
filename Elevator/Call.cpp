#include "Call.h"

directions findCallDir(Call call) {

	if(call.TargetFloor - call.FromFloor > 0) {
		return up;
	} else {
		return down;
	}

}