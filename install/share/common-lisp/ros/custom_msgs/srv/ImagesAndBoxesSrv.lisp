; Auto-generated. Do not edit!


(cl:in-package custom_msgs-srv)


;//! \htmlinclude ImagesAndBoxesSrv-request.msg.html

(cl:defclass <ImagesAndBoxesSrv-request> (roslisp-msg-protocol:ros-message)
  ((skips
    :reader skips
    :initarg :skips
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ImagesAndBoxesSrv-request (<ImagesAndBoxesSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImagesAndBoxesSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImagesAndBoxesSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-srv:<ImagesAndBoxesSrv-request> is deprecated: use custom_msgs-srv:ImagesAndBoxesSrv-request instead.")))

(cl:ensure-generic-function 'skips-val :lambda-list '(m))
(cl:defmethod skips-val ((m <ImagesAndBoxesSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-srv:skips-val is deprecated.  Use custom_msgs-srv:skips instead.")
  (skips m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImagesAndBoxesSrv-request>) ostream)
  "Serializes a message object of type '<ImagesAndBoxesSrv-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skips)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImagesAndBoxesSrv-request>) istream)
  "Deserializes a message object of type '<ImagesAndBoxesSrv-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skips)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImagesAndBoxesSrv-request>)))
  "Returns string type for a service object of type '<ImagesAndBoxesSrv-request>"
  "custom_msgs/ImagesAndBoxesSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImagesAndBoxesSrv-request)))
  "Returns string type for a service object of type 'ImagesAndBoxesSrv-request"
  "custom_msgs/ImagesAndBoxesSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImagesAndBoxesSrv-request>)))
  "Returns md5sum for a message object of type '<ImagesAndBoxesSrv-request>"
  "5d7f9b966106cb762e276fc9ad963134")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImagesAndBoxesSrv-request)))
  "Returns md5sum for a message object of type 'ImagesAndBoxesSrv-request"
  "5d7f9b966106cb762e276fc9ad963134")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImagesAndBoxesSrv-request>)))
  "Returns full string definition for message of type '<ImagesAndBoxesSrv-request>"
  (cl:format cl:nil "uint8 skips~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImagesAndBoxesSrv-request)))
  "Returns full string definition for message of type 'ImagesAndBoxesSrv-request"
  (cl:format cl:nil "uint8 skips~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImagesAndBoxesSrv-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImagesAndBoxesSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ImagesAndBoxesSrv-request
    (cl:cons ':skips (skips msg))
))
;//! \htmlinclude ImagesAndBoxesSrv-response.msg.html

(cl:defclass <ImagesAndBoxesSrv-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type custom_msgs-msg:ImagesAndBoxes
    :initform (cl:make-instance 'custom_msgs-msg:ImagesAndBoxes)))
)

(cl:defclass ImagesAndBoxesSrv-response (<ImagesAndBoxesSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImagesAndBoxesSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImagesAndBoxesSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-srv:<ImagesAndBoxesSrv-response> is deprecated: use custom_msgs-srv:ImagesAndBoxesSrv-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ImagesAndBoxesSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-srv:result-val is deprecated.  Use custom_msgs-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImagesAndBoxesSrv-response>) ostream)
  "Serializes a message object of type '<ImagesAndBoxesSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'result) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImagesAndBoxesSrv-response>) istream)
  "Deserializes a message object of type '<ImagesAndBoxesSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'result) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImagesAndBoxesSrv-response>)))
  "Returns string type for a service object of type '<ImagesAndBoxesSrv-response>"
  "custom_msgs/ImagesAndBoxesSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImagesAndBoxesSrv-response)))
  "Returns string type for a service object of type 'ImagesAndBoxesSrv-response"
  "custom_msgs/ImagesAndBoxesSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImagesAndBoxesSrv-response>)))
  "Returns md5sum for a message object of type '<ImagesAndBoxesSrv-response>"
  "5d7f9b966106cb762e276fc9ad963134")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImagesAndBoxesSrv-response)))
  "Returns md5sum for a message object of type 'ImagesAndBoxesSrv-response"
  "5d7f9b966106cb762e276fc9ad963134")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImagesAndBoxesSrv-response>)))
  "Returns full string definition for message of type '<ImagesAndBoxesSrv-response>"
  (cl:format cl:nil "custom_msgs/ImagesAndBoxes result~%~%================================================================================~%MSG: custom_msgs/ImagesAndBoxes~%sensor_msgs/Image bot_img~%sensor_msgs/Image top_img~%Box[] bot_img_boxes~%Box[] top_img_boxes~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of camera~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: custom_msgs/Box~%float32 left~%float32 top~%float32 right~%float32 bottom~%~%string id~%# the id should not be changed from 0 except for by the object prediction algorithm~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImagesAndBoxesSrv-response)))
  "Returns full string definition for message of type 'ImagesAndBoxesSrv-response"
  (cl:format cl:nil "custom_msgs/ImagesAndBoxes result~%~%================================================================================~%MSG: custom_msgs/ImagesAndBoxes~%sensor_msgs/Image bot_img~%sensor_msgs/Image top_img~%Box[] bot_img_boxes~%Box[] top_img_boxes~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of camera~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: custom_msgs/Box~%float32 left~%float32 top~%float32 right~%float32 bottom~%~%string id~%# the id should not be changed from 0 except for by the object prediction algorithm~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImagesAndBoxesSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImagesAndBoxesSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ImagesAndBoxesSrv-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ImagesAndBoxesSrv)))
  'ImagesAndBoxesSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ImagesAndBoxesSrv)))
  'ImagesAndBoxesSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImagesAndBoxesSrv)))
  "Returns string type for a service object of type '<ImagesAndBoxesSrv>"
  "custom_msgs/ImagesAndBoxesSrv")