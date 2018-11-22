;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::ImagesAndBoxesSrv)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'ImagesAndBoxesSrv (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::IMAGESANDBOXESSRV")
  (make-package "CUSTOM_MSGS::IMAGESANDBOXESSRV"))
(unless (find-package "CUSTOM_MSGS::IMAGESANDBOXESSRVREQUEST")
  (make-package "CUSTOM_MSGS::IMAGESANDBOXESSRVREQUEST"))
(unless (find-package "CUSTOM_MSGS::IMAGESANDBOXESSRVRESPONSE")
  (make-package "CUSTOM_MSGS::IMAGESANDBOXESSRVRESPONSE"))

(in-package "ROS")





(defclass custom_msgs::ImagesAndBoxesSrvRequest
  :super ros::object
  :slots (_skips ))

(defmethod custom_msgs::ImagesAndBoxesSrvRequest
  (:init
   (&key
    ((:skips __skips) 0)
    )
   (send-super :init)
   (setq _skips (round __skips))
   self)
  (:skips
   (&optional __skips)
   (if __skips (setq _skips __skips)) _skips)
  (:serialization-length
   ()
   (+
    ;; uint8 _skips
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _skips
       (write-byte _skips s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _skips
     (setq _skips (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass custom_msgs::ImagesAndBoxesSrvResponse
  :super ros::object
  :slots (_result ))

(defmethod custom_msgs::ImagesAndBoxesSrvResponse
  (:init
   (&key
    ((:result __result) (instance custom_msgs::ImagesAndBoxes :init))
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&rest __result)
   (if (keywordp (car __result))
       (send* _result __result)
     (progn
       (if __result (setq _result (car __result)))
       _result)))
  (:serialization-length
   ()
   (+
    ;; custom_msgs/ImagesAndBoxes _result
    (send _result :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; custom_msgs/ImagesAndBoxes _result
       (send _result :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; custom_msgs/ImagesAndBoxes _result
     (send _result :deserialize buf ptr-) (incf ptr- (send _result :serialization-length))
   ;;
   self)
  )

(defclass custom_msgs::ImagesAndBoxesSrv
  :super ros::object
  :slots ())

(setf (get custom_msgs::ImagesAndBoxesSrv :md5sum-) "5d7f9b966106cb762e276fc9ad963134")
(setf (get custom_msgs::ImagesAndBoxesSrv :datatype-) "custom_msgs/ImagesAndBoxesSrv")
(setf (get custom_msgs::ImagesAndBoxesSrv :request) custom_msgs::ImagesAndBoxesSrvRequest)
(setf (get custom_msgs::ImagesAndBoxesSrv :response) custom_msgs::ImagesAndBoxesSrvResponse)

(defmethod custom_msgs::ImagesAndBoxesSrvRequest
  (:response () (instance custom_msgs::ImagesAndBoxesSrvResponse :init)))

(setf (get custom_msgs::ImagesAndBoxesSrvRequest :md5sum-) "5d7f9b966106cb762e276fc9ad963134")
(setf (get custom_msgs::ImagesAndBoxesSrvRequest :datatype-) "custom_msgs/ImagesAndBoxesSrvRequest")
(setf (get custom_msgs::ImagesAndBoxesSrvRequest :definition-)
      "uint8 skips
---
custom_msgs/ImagesAndBoxes result

================================================================================
MSG: custom_msgs/ImagesAndBoxes
sensor_msgs/Image bot_img
sensor_msgs/Image top_img
Box[] bot_img_boxes
Box[] top_img_boxes
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

================================================================================
MSG: custom_msgs/Box
float32 left
float32 top
float32 right
float32 bottom

string id
")

(setf (get custom_msgs::ImagesAndBoxesSrvResponse :md5sum-) "5d7f9b966106cb762e276fc9ad963134")
(setf (get custom_msgs::ImagesAndBoxesSrvResponse :datatype-) "custom_msgs/ImagesAndBoxesSrvResponse")
(setf (get custom_msgs::ImagesAndBoxesSrvResponse :definition-)
      "uint8 skips
---
custom_msgs/ImagesAndBoxes result

================================================================================
MSG: custom_msgs/ImagesAndBoxes
sensor_msgs/Image bot_img
sensor_msgs/Image top_img
Box[] bot_img_boxes
Box[] top_img_boxes
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

================================================================================
MSG: custom_msgs/Box
float32 left
float32 top
float32 right
float32 bottom

string id
")



(provide :custom_msgs/ImagesAndBoxesSrv "5d7f9b966106cb762e276fc9ad963134")


