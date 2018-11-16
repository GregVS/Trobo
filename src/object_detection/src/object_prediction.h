#ifndef OBJ_PREDICTION_H
#define OBJ_PREDICTION_H

#include <custom_msgs/ImagesAndBoxes.h>
#include <custom_msgs/Action.h>

typedef const custom_msgs::ImagesAndBoxes::ConstPtr ImagesAndBoxesPtr;
typedef const custom_msgs::Action::ConstPtr ActionPtr;

class ObjectPrediction {

public:
	custom_msgs::ImagesAndBoxes performPrediction(ImagesAndBoxesPtr& currImgBoxes, ImagesAndBoxesPtr& lastImgBoxes, ActionPtr& lastAction);

};

#endif