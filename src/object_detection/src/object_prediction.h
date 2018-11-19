#ifndef OBJ_PREDICTION_H
#define OBJ_PREDICTION_H

#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>

class ObjectPrediction {

public:
	custom_msgs::ImagesAndBoxes performPrediction(const custom_msgs::ImagesAndBoxes& currImgBoxes, const custom_msgs::ImagesAndBoxes& lastImgBoxes, const custom_msgs::Action& lastAction);

};

#endif