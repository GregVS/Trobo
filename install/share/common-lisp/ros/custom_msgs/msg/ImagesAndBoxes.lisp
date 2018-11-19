; Auto-generated. Do not edit!


(cl:in-package custom_msgs-msg)


;//! \htmlinclude ImagesAndBoxes.msg.html

(cl:defclass <ImagesAndBoxes> (roslisp-msg-protocol:ros-message)
  ((bot_img
    :reader bot_img
    :initarg :bot_img
    :type sensor_msgs-msg:Image
    :initform (cl:make-instance 'sensor_msgs-msg:Image))
   (top_img
    :reader top_img
    :initarg :top_img
    :type sensor_msgs-msg:Image
    :initform (cl:make-instance 'sensor_msgs-msg:Image))
   (bot_img_boxes
    :reader bot_img_boxes
    :initarg :bot_img_boxes
    :type (cl:vector custom_msgs-msg:Box)
   :initform (cl:make-array 0 :element-type 'custom_msgs-msg:Box :initial-element (cl:make-instance 'custom_msgs-msg:Box)))
   (top_img_boxes
    :reader top_img_boxes
    :initarg :top_img_boxes
    :type (cl:vector custom_msgs-msg:Box)
   :initform (cl:make-array 0 :element-type 'custom_msgs-msg:Box :initial-element (cl:make-instance 'custom_msgs-msg:Box))))
)

(cl:defclass ImagesAndBoxes (<ImagesAndBoxes>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImagesAndBoxes>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImagesAndBoxes)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-msg:<ImagesAndBoxes> is deprecated: use custom_msgs-msg:ImagesAndBoxes instead.")))

(cl:ensure-generic-function 'bot_img-val :lambda-list '(m))
(cl:defmethod bot_img-val ((m <ImagesAndBoxes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:bot_img-val is deprecated.  Use custom_msgs-msg:bot_img instead.")
  (bot_img m))

(cl:ensure-generic-function 'top_img-val :lambda-list '(m))
(cl:defmethod top_img-val ((m <ImagesAndBoxes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:top_img-val is deprecated.  Use custom_msgs-msg:top_img instead.")
  (top_img m))

(cl:ensure-generic-function 'bot_img_boxes-val :lambda-list '(m))
(cl:defmethod bot_img_boxes-val ((m <ImagesAndBoxes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:bot_img_boxes-val is deprecated.  Use custom_msgs-msg:bot_img_boxes instead.")
  (bot_img_boxes m))

(cl:ensure-generic-function 'top_img_boxes-val :lambda-list '(m))
(cl:defmethod top_img_boxes-val ((m <ImagesAndBoxes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:top_img_boxes-val is deprecated.  Use custom_msgs-msg:top_img_boxes instead.")
  (top_img_boxes m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImagesAndBoxes>) ostream)
  "Serializes a message object of type '<ImagesAndBoxes>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'bot_img) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'top_img) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'bot_img_boxes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'bot_img_boxes))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'top_img_boxes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'top_img_boxes))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImagesAndBoxes>) istream)
  "Deserializes a message object of type '<ImagesAndBoxes>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'bot_img) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'top_img) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'bot_img_boxes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'bot_img_boxes)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'custom_msgs-msg:Box))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'top_img_boxes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'top_img_boxes)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'custom_msgs-msg:Box))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImagesAndBoxes>)))
  "Returns string type for a message object of type '<ImagesAndBoxes>"
  "custom_msgs/ImagesAndBoxes")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImagesAndBoxes)))
  "Returns string type for a message object of type 'ImagesAndBoxes"
  "custom_msgs/ImagesAndBoxes")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImagesAndBoxes>)))
  "Returns md5sum for a message object of type '<ImagesAndBoxes>"
  "154afe0ce1a929ba4bd762dc5f49fc14")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImagesAndBoxes)))
  "Returns md5sum for a message object of type 'ImagesAndBoxes"
  "154afe0ce1a929ba4bd762dc5f49fc14")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImagesAndBoxes>)))
  "Returns full string definition for message of type '<ImagesAndBoxes>"
  (cl:format cl:nil "sensor_msgs/Image bot_img~%sensor_msgs/Image top_img~%Box[] bot_img_boxes~%Box[] top_img_boxes~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of camera~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: custom_msgs/Box~%float32 left~%float32 top~%float32 right~%float32 bottom~%~%string id~%# the id should not be changed from 0 except for by the object prediction algorithm~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImagesAndBoxes)))
  "Returns full string definition for message of type 'ImagesAndBoxes"
  (cl:format cl:nil "sensor_msgs/Image bot_img~%sensor_msgs/Image top_img~%Box[] bot_img_boxes~%Box[] top_img_boxes~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of camera~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: custom_msgs/Box~%float32 left~%float32 top~%float32 right~%float32 bottom~%~%string id~%# the id should not be changed from 0 except for by the object prediction algorithm~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImagesAndBoxes>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'bot_img))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'top_img))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'bot_img_boxes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'top_img_boxes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImagesAndBoxes>))
  "Converts a ROS message object to a list"
  (cl:list 'ImagesAndBoxes
    (cl:cons ':bot_img (bot_img msg))
    (cl:cons ':top_img (top_img msg))
    (cl:cons ':bot_img_boxes (bot_img_boxes msg))
    (cl:cons ':top_img_boxes (top_img_boxes msg))
))
