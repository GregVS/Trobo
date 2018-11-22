; Auto-generated. Do not edit!


(cl:in-package custom_msgs-srv)


;//! \htmlinclude ActionSrv-request.msg.html

(cl:defclass <ActionSrv-request> (roslisp-msg-protocol:ros-message)
  ((skips
    :reader skips
    :initarg :skips
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ActionSrv-request (<ActionSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ActionSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ActionSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-srv:<ActionSrv-request> is deprecated: use custom_msgs-srv:ActionSrv-request instead.")))

(cl:ensure-generic-function 'skips-val :lambda-list '(m))
(cl:defmethod skips-val ((m <ActionSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-srv:skips-val is deprecated.  Use custom_msgs-srv:skips instead.")
  (skips m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ActionSrv-request>) ostream)
  "Serializes a message object of type '<ActionSrv-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skips)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ActionSrv-request>) istream)
  "Deserializes a message object of type '<ActionSrv-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'skips)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ActionSrv-request>)))
  "Returns string type for a service object of type '<ActionSrv-request>"
  "custom_msgs/ActionSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ActionSrv-request)))
  "Returns string type for a service object of type 'ActionSrv-request"
  "custom_msgs/ActionSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ActionSrv-request>)))
  "Returns md5sum for a message object of type '<ActionSrv-request>"
  "bc83a7ef89bbba9a6fa9c799fab90d6c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ActionSrv-request)))
  "Returns md5sum for a message object of type 'ActionSrv-request"
  "bc83a7ef89bbba9a6fa9c799fab90d6c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ActionSrv-request>)))
  "Returns full string definition for message of type '<ActionSrv-request>"
  (cl:format cl:nil "uint8 skips~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ActionSrv-request)))
  "Returns full string definition for message of type 'ActionSrv-request"
  (cl:format cl:nil "uint8 skips~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ActionSrv-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ActionSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ActionSrv-request
    (cl:cons ':skips (skips msg))
))
;//! \htmlinclude ActionSrv-response.msg.html

(cl:defclass <ActionSrv-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type custom_msgs-msg:Action
    :initform (cl:make-instance 'custom_msgs-msg:Action)))
)

(cl:defclass ActionSrv-response (<ActionSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ActionSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ActionSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-srv:<ActionSrv-response> is deprecated: use custom_msgs-srv:ActionSrv-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ActionSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-srv:result-val is deprecated.  Use custom_msgs-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ActionSrv-response>) ostream)
  "Serializes a message object of type '<ActionSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'result) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ActionSrv-response>) istream)
  "Deserializes a message object of type '<ActionSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'result) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ActionSrv-response>)))
  "Returns string type for a service object of type '<ActionSrv-response>"
  "custom_msgs/ActionSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ActionSrv-response)))
  "Returns string type for a service object of type 'ActionSrv-response"
  "custom_msgs/ActionSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ActionSrv-response>)))
  "Returns md5sum for a message object of type '<ActionSrv-response>"
  "bc83a7ef89bbba9a6fa9c799fab90d6c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ActionSrv-response)))
  "Returns md5sum for a message object of type 'ActionSrv-response"
  "bc83a7ef89bbba9a6fa9c799fab90d6c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ActionSrv-response>)))
  "Returns full string definition for message of type '<ActionSrv-response>"
  (cl:format cl:nil "custom_msgs/Action result~%~%================================================================================~%MSG: custom_msgs/Action~%uint8 id~%float32[] params~%~%# The id codes are listed below~%# 0 - scoop~%# 1 - drive (left %, right %)~%# 2 - stop~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ActionSrv-response)))
  "Returns full string definition for message of type 'ActionSrv-response"
  (cl:format cl:nil "custom_msgs/Action result~%~%================================================================================~%MSG: custom_msgs/Action~%uint8 id~%float32[] params~%~%# The id codes are listed below~%# 0 - scoop~%# 1 - drive (left %, right %)~%# 2 - stop~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ActionSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ActionSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ActionSrv-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ActionSrv)))
  'ActionSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ActionSrv)))
  'ActionSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ActionSrv)))
  "Returns string type for a service object of type '<ActionSrv>"
  "custom_msgs/ActionSrv")