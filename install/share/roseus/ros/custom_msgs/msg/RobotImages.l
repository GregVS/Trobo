;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::RobotImages)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'RobotImages (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::ROBOTIMAGES")
  (make-package "CUSTOM_MSGS::ROBOTIMAGES"))

(in-package "ROS")
;;//! \htmlinclude RobotImages.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass custom_msgs::RobotImages
  :super ros::object
  :slots (_bot_img _top_img ))

(defmethod custom_msgs::RobotImages
  (:init
   (&key
    ((:bot_img __bot_img) (instance sensor_msgs::Image :init))
    ((:top_img __top_img) (instance sensor_msgs::Image :init))
    )
   (send-super :init)
   (setq _bot_img __bot_img)
   (setq _top_img __top_img)
   self)
  (:bot_img
   (&rest __bot_img)
   (if (keywordp (car __bot_img))
       (send* _bot_img __bot_img)
     (progn
       (if __bot_img (setq _bot_img (car __bot_img)))
       _bot_img)))
  (:top_img
   (&rest __top_img)
   (if (keywordp (car __top_img))
       (send* _top_img __top_img)
     (progn
       (if __top_img (setq _top_img (car __top_img)))
       _top_img)))
  (:serialization-length
   ()
   (+
    ;; sensor_msgs/Image _bot_img
    (send _bot_img :serialization-length)
    ;; sensor_msgs/Image _top_img
    (send _top_img :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sensor_msgs/Image _bot_img
       (send _bot_img :serialize s)
     ;; sensor_msgs/Image _top_img
       (send _top_img :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sensor_msgs/Image _bot_img
     (send _bot_img :deserialize buf ptr-) (incf ptr- (send _bot_img :serialization-length))
   ;; sensor_msgs/Image _top_img
     (send _top_img :deserialize buf ptr-) (incf ptr- (send _top_img :serialization-length))
   ;;
   self)
  )

(setf (get custom_msgs::RobotImages :md5sum-) "54e3756641edd5f5344850f8fdb6eba6")
(setf (get custom_msgs::RobotImages :datatype-) "custom_msgs/RobotImages")
(setf (get custom_msgs::RobotImages :definition-)
      "sensor_msgs/Image bot_img
sensor_msgs/Image top_img

================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :custom_msgs/RobotImages "54e3756641edd5f5344850f8fdb6eba6")

